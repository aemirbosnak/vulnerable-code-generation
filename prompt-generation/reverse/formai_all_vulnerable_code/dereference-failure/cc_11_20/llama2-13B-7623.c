//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_PACKET_SIZE 1500

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[INET_ADDRSTRLEN];
    int established;
};

int main(int argc, char *argv[]) {
    int listen_sock;
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(2222)
    };

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port 2222...\n");

    while (1) {
        int client_sock;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        char client_ip[INET_ADDRSTRLEN];

        if ((client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Keep track of established connections
        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = client_sock;
        memcpy(&conn->client_addr, &client_addr, sizeof(client_addr));
        strcpy(conn->client_ip, inet_ntoa(client_addr.sin_addr));
        conn->established = 0;

        // Handle incoming packets
        while (1) {
            char buffer[MAX_PACKET_SIZE];
            int bytes_recv = recv(client_sock, buffer, MAX_PACKET_SIZE, 0);

            if (bytes_recv <= 0) {
                break;
            }

            // Check if the client is sending a SYN packet
            if (buffer[0] == 0x14 && buffer[1] == 0x00 && buffer[2] == 0x01) {
                // SYN packet, establish the connection
                conn->established = 1;
                break;
            }

            // Check if the client is sending a FIN packet
            if (buffer[0] == 0x14 && buffer[1] == 0x00 && buffer[2] == 0x02) {
                // FIN packet, close the connection
                conn->established = 0;
                break;
            }

            // Send an ACK packet back to the client
            send(client_sock, buffer, bytes_recv, 0);
        }

        // Close the connection
        close(client_sock);
    }

    return 0;
}