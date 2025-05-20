//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 10

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int send_packets;
    int recv_packets;
    double avg_latency;
} QoSData;

QoSData clients[MAX_CLIENTS];
int client_count = 0;

void init_client(QoSData *client, const char *ip) {
    strncpy(client->ip, ip, INET_ADDRSTRLEN);
    client->send_packets = 0;
    client->recv_packets = 0;
    client->avg_latency = 0.0;
}

void update_client_data(QoSData *client, double latency) {
    client->send_packets++;
    client->recv_packets++;
    client->avg_latency = ((client->avg_latency * (client->recv_packets - 1)) + latency) / client->recv_packets;
}

void print_qos_data() {
    printf("\nQoS Data:\n");
    printf("IP Address        Sent Packets    Received Packets    Avg Latency (ms)\n");
    for (int i = 0; i < client_count; i++) {
        printf("%-16s      %d                %d                   %.2f\n",
               clients[i].ip,
               clients[i].send_packets,
               clients[i].recv_packets,
               clients[i].avg_latency);
    }
}

int find_client(const char *ip) {
    for (int i = 0; i < client_count; i++) {
        if (strcmp(clients[i].ip, ip) == 0) {
            return i;
        }
    }
    return -1;
}

void add_client(const char *ip) {
    if (client_count < MAX_CLIENTS) {
        init_client(&clients[client_count], ip);
        client_count++;
    } else {
        printf("Max client limit reached!\n");
    }
}

double simulate_packet_send_receive(const char *ip) {
    // Simulating latency in ms
    double latency = (rand() % 100) + 1; // Random latency from 1 to 100 ms
    usleep((latency * 1000)); // Simulating the sending time delay
    return latency;
}

int main() {
    srand(time(NULL));
    char input_ip[INET_ADDRSTRLEN];
    char command[10];
    
    while (1) {
        printf("Enter command (add <IP>, stats, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s", input_ip);
            if (find_client(input_ip) == -1) {
                add_client(input_ip);
            } else {
                printf("Client %s already exists.\n", input_ip);
            }
        } else if (strcmp(command, "stats") == 0) {
            for (int i = 0; i < client_count; i++) {
                double latency = simulate_packet_send_receive(clients[i].ip);
                update_client_data(&clients[i], latency);
            }
            print_qos_data();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}