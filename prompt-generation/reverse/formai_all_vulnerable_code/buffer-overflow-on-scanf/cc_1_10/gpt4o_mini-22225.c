//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_SERVERS 10
#define PING_COUNT 4
#define TIMEOUT_SEC 1
#define BUFFER_SIZE 64

struct Server {
    char ip[16];
    int successful_pings;
    double total_time;
};

void ping_server(struct Server *server) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return;
    }

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, server->ip, &server_addr.sin_addr);

    for(int i = 0; i < PING_COUNT; i++) {
        clock_t start_time = clock();
        int sent = sendto(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (sent < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                printf("Ping to %s timed out!\n", server->ip);
            } else {
                perror("Send failed");
            }
        } else {
            socklen_t addr_len = sizeof(server_addr);
            int received = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
            clock_t end_time = clock();
            double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
            
            if (received < 0) {
                printf("Ping to %s failed!\n", server->ip);
            } else {
                server->successful_pings++;
                server->total_time += time_taken;
                printf("Ping to %s took %.2f ms\n", server->ip, time_taken);
            }
        }
        sleep(1); // Delay for a second before next ping
    }

    close(sock);
}

void display_results(struct Server *servers, int server_count) {
    printf("\n--- QoS Monitoring Results ---\n");
    for (int i = 0; i < server_count; i++) {
        double average_time = servers[i].successful_pings ? servers[i].total_time / servers[i].successful_pings : 0;
        printf("Server: %s, Successful Pings: %d, Average Time: %.2f ms\n",
               servers[i].ip, servers[i].successful_pings, average_time);
    }
}

int main() {
    struct Server servers[MAX_SERVERS];
    int server_count = 0;

    printf("Welcome to the Network QoS Monitor!\n");
    printf("Enter IP addresses (type 'done' when finished): \n");
    
    while (server_count < MAX_SERVERS) {
        printf("Server %d: ", server_count + 1);
        char user_input[16];
        scanf("%s", user_input);
        
        if (strcmp(user_input, "done") == 0) break;

        strcpy(servers[server_count].ip, user_input);
        servers[server_count].successful_pings = 0;
        servers[server_count].total_time = 0.0;
        server_count++;
    }

    printf("Starting the QoS monitoring for %d servers...\n", server_count);
    
    for (int i = 0; i < server_count; i++) {
        ping_server(&servers[i]);
    }

    display_results(servers, server_count);
    
    printf("QoS monitoring completed! Thank you!\n");
    return 0;
}