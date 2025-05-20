//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define QOS_PORT 5000
#define QOS_SERVER "127.0.0.1"

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE_LENGTH];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to QoS server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(QOS_PORT);
    inet_pton(AF_INET, QOS_SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to QoS server\n");
        exit(1);
    }

    // Send QoS request
    char qos_request[] = "GET /qos HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
    send(sock, qos_request, strlen(qos_request), 0);

    // Receive QoS response
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, MAX_LINE_LENGTH, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}