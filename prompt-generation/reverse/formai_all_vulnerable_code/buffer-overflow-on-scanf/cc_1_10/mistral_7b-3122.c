//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define WIFI_LIGHT_IP "192.168.1.100"
#define WIFI_LIGHT_PORT 80
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(void) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket: could not open socket");

    // Set up the struct addressing information
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(WIFI_LIGHT_PORT);
    inet_pton(AF_INET, WIFI_LIGHT_IP, &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        die("connect: could not connect to server");

    printf("\nConnected to WiFi Light server.\n");

    while (1) {
        printf("\nEnter command (on, off, dim <int>): ");
        scanf("%s", send_buf);

        // Prepare message to send
        memset(send_buf + strlen(send_buf), 0, BUFFER_SIZE - strlen(send_buf) - 1);
        strcat(send_buf, ":");

        if (strcmp(send_buf, "on") == 0) {
            strcat(send_buf, "1");
        } else if (strcmp(send_buf, "off") == 0) {
            strcat(send_buf, "0");
        } else if (strcmp(send_buf, "dim") == 0 && strlen(send_buf) < BUFFER_SIZE - 4) {
            int dim;
            scanf("%d", &dim);
            sprintf(send_buf + strlen(send_buf), "%d", dim);
        }

        // Send message
        if (send(sockfd, send_buf, strlen(send_buf), 0) < 0)
            die("send: could not send data to server");

        // Receive response
        memset(recv_buf, 0, BUFFER_SIZE);
        if (recv(sockfd, recv_buf, BUFFER_SIZE - 1, 0) < 0)
            die("recv: could not receive data from server");

        printf("Server response: %s\n", recv_buf);
    }

    close(sockfd);
    return 0;
}