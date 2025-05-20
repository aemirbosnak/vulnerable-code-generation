//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char ip[20];
    int start, end, i, j, count = 0;

    printf("Enter the IP address: ");
    fgets(ip, 20, stdin);
    ip[strlen(ip) - 1] = '\0';     // Remove newline character

    printf("Enter the starting port number: ");
    scanf("%d", &start);
    getchar();

    printf("Enter the ending port number: ");
    scanf("%d", &end);
    getchar();

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return -1;
    }

    // Fill in server details
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;

    // Iterate through port numbers and check if they are open
    for (i = start; i <= end; i++) {
        server.sin_port = htons(i);

        // Connect to server
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Port %d is closed\n", i);
        }
        else {
            printf("Port %d is open\n", i);
            count++;
        }
    }

    // Close the socket
    close(sock);

    printf("\nScan completed!\n");
    printf("%d open port(s) found\n", count);

    return 0;
}