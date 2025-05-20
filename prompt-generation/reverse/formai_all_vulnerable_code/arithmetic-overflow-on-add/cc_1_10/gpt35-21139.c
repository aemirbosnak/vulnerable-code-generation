//FormAI DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 3
#define BUFFER_SIZE 1024

void send_data(int client_sock, char *data);
void display_statistics();

int main(int argc, char const *argv[]) {

    int server_sock, client_sock, addr_len, activity, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    int clients[MAX_CLIENTS] = {0};
    fd_set readfds;
    int max_sd;

    // create server socket
    if((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to address and port
    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // listen for incoming connections
    if(listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    while(1) {
        FD_ZERO(&readfds);

        // add server socket to set
        FD_SET(server_sock, &readfds);
        max_sd = server_sock;

        // add all connected clients to set
        for(int i = 0; i < MAX_CLIENTS; i++) {
            int sd = clients[i];

            if(sd > 0) {
                FD_SET(sd, &readfds);
            }

            if(sd > max_sd) {
                max_sd = sd;
            }
        }

        // wait for activity on one of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if(FD_ISSET(server_sock, &readfds)) {
            // new client connection
            addr_len = sizeof(client_addr);
            if((new_socket = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
                perror("Failed to accept new connection");
                exit(EXIT_FAILURE);
            }

            // add new socket to array of clients
            for(int i = 0; i < MAX_CLIENTS; i++) {
                if(clients[i] == 0) {
                    clients[i] = new_socket;
                    printf("New connection accepted, socket fd is %d\n", new_socket);
                    break;
                }
            }
        }

        for(int i = 0; i < MAX_CLIENTS; i++) {
            int sd = clients[i];

            if(FD_ISSET(sd, &readfds)) {
                // client sent data
                if(read(sd, buffer, BUFFER_SIZE) == 0) {
                    // client disconnected
                    printf("Client %d disconnected\n", sd);
                    // close socket and remove from array of clients
                    close(sd);
                    clients[i] = 0;
                } else {
                    // display received data statistics
                    display_statistics(buffer);
                    // echo data back to client
                    send_data(sd, buffer);
                }
            }
        }
    }

    return 0;
}

void send_data(int client_sock, char *data) {
    if(send(client_sock, data, strlen(data), 0) != strlen(data)) {
        perror("Failed to send data");
        exit(EXIT_FAILURE);
    }
}

void display_statistics(char *data) {
    int len = strlen(data);
    int word_count = 0;
    int alpha_count = 0;
    int digit_count = 0;

    // iterate over characters in data buffer
    for(int i = 0; i < len; i++) {
        char c = data[i];
        if(c == ' ') {
            // space indicates end of word
            word_count++;
        } else if(isalpha(c)) {
            alpha_count++;
        } else if(isdigit(c)) {
            digit_count++;
        }
    }

    printf("Received data statistics:\n");
    printf("Total bytes received: %d\n", len);
    printf("Total words received: %d\n", word_count+1); // add 1 to include last word
    printf("Total alphabetical characters received: %d\n", alpha_count);
    printf("Total numerical characters received: %d\n", digit_count);
}