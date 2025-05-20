//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNS 10
#define MAX_PACKET_LEN 1400

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[50];
    int established;
};

int main(int argc, char *argv[]) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", listen_addr.sin_port);

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        if (getpeername(client_sock, (struct sockaddr *)&client_addr, &client_addr_len) < 0) {
            perror("getpeername failed");
            close(client_sock);
            continue;
        }

        char client_name[50];
        if (getnameinfo((struct sockaddr *)&client_addr, client_addr_len, client_name, sizeof(client_name), NULL, 0, NULL) < 0) {
            perror("getnameinfo failed");
            close(client_sock);
            continue;
        }

        printf("Connection from %s\n", client_name);

        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = client_sock;
        memcpy(&conn->client_addr, &client_addr, sizeof(struct sockaddr_in));
        strcpy(conn->client_name, client_name);
        conn->established = 0;

        // Handle incoming packets
        while (1) {
            char buffer[MAX_PACKET_LEN];
            int bytes_recv = recv(client_sock, buffer, MAX_PACKET_LEN, 0);

            if (bytes_recv < 0) {
                perror("recv failed");
                close(client_sock);
                break;
            }

            // Check if the packet is a SYN packet
            if (buffer[0] == 0x12 && buffer[1] == 0x01 && buffer[2] == 0x01) {
                // Respond with a SYN-ACK packet
                char syn_ack_buffer[MAX_PACKET_LEN];
                syn_ack_buffer[0] = 0x12;
                syn_ack_buffer[1] = 0x01;
                syn_ack_buffer[2] = 0x02;
                send(client_sock, syn_ack_buffer, MAX_PACKET_LEN, 0);
            } else if (buffer[0] == 0x12 && buffer[1] == 0x02 && buffer[2] == 0x01) {
                // Respond with an ACK packet
                char ack_buffer[MAX_PACKET_LEN];
                ack_buffer[0] = 0x12;
                ack_buffer[1] = 0x02;
                ack_buffer[2] = 0x02;
                send(client_sock, ack_buffer, MAX_PACKET_LEN, 0);

                // Update the connection state
                conn->established = 1;
            } else {
                // Drop the packet
                close(client_sock);
                break;
            }
        }

        // Close the connection when it's no longer established
        if (!conn->established) {
            close(client_sock);
        }
    }

    return 0;
}