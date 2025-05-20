//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    int id;
    char name[50];
    float bid;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_CLIENTS][MAX_ITEMS];
int num_items = 0;
int num_bids = 0;
int clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t lock;

void *client_thread(void *arg) {
    int client_socket = *(int *)arg;
    int client_id = num_clients++;

    while (1) {
        char buffer[1024];
        int len = recv(client_socket, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            break;
        }

        char command[50];
        char args[1024];
        sscanf(buffer, "%s %s", command, args);

        if (strcmp(command, "LIST") == 0) {
            char response[1024];
            sprintf(response, "ITEMS");
            for (int i = 0; i < num_items; i++) {
                sprintf(response + strlen(response), " %d %s %.2f", items[i].id, items[i].name, items[i].price);
            }
            send(client_socket, response, strlen(response), 0);
        } else if (strcmp(command, "BID") == 0) {
            int item_id;
            float bid_amount;
            sscanf(args, "%d %f", &item_id, &bid_amount);

            pthread_mutex_lock(&lock);
            int found = 0;
            for (int i = 0; i < num_items; i++) {
                if (items[i].id == item_id) {
                    found = 1;
                    if (bid_amount > items[i].price) {
                        items[i].price = bid_amount;
                        bids[client_id][i].bid = bid_amount;
                    }
                    break;
                }
            }
            pthread_mutex_unlock(&lock);

            if (found) {
                char response[1024];
                sprintf(response, "BID_ACCEPTED %d %.2f", item_id, bid_amount);
                send(client_socket, response, strlen(response), 0);
            } else {
                char response[1024];
                sprintf(response, "BID_REJECTED %d", item_id);
                send(client_socket, response, strlen(response), 0);
            }
        } else if (strcmp(command, "CLOSE") == 0) {
            break;
        }
    }

    close(client_socket);
    num_clients--;

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    pthread_mutex_init(&lock, NULL);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        pthread_t client_thread_id;
        pthread_create(&client_thread_id, NULL, client_thread, &client_socket);
    }

    close(server_socket);

    return 0;
}