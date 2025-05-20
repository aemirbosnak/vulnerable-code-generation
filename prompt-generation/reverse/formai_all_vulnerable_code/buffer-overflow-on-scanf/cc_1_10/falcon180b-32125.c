//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    struct sockaddr_in server_addr;
    int sockfd, port;
    char *server_ip;
    double start_time, end_time, elapsed_time;
    int bytes_received;

    printf("Enter the IP address of the server: ");
    scanf("%s", server_ip);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);

    bytes_received = recv(sockfd, NULL, 0, 0);

    end_time = time(NULL);

    elapsed_time = difftime(end_time, start_time);

    printf("Internet speed test results:\n");
    printf("Bytes received: %d\n", bytes_received);
    printf("Elapsed time: %.2lf seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}