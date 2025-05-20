//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_OK "+OK"

int main() {
    // Get the host name and port number from the user.
    char host[1024];
    int port;
    printf("Enter the POP3 server host name: ");
    scanf("%s", host);
    printf("Enter the POP3 server port number: ");
    scanf("%d", &port);

    // Create a socket for connecting to the POP3 server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Specify the address and port of the POP3 server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the POP3 server.
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the POP3 server.
    char buf[1024];
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Send the USER command to the POP3 server.
    sprintf(buf, "USER username\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Send the PASS command to the POP3 server.
    sprintf(buf, "PASS password\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Send the LIST command to the POP3 server.
    sprintf(buf, "LIST\r\n");
    send(sockfd, buf, strlen(buf), 0);

    // Read the list of messages from the POP3 server.
    int num_messages;
    recv(sockfd, buf, sizeof(buf), 0);
    sscanf(buf, "+OK %d messages", &num_messages);
    printf("%d messages found.\n", num_messages);

    for (int i = 1; i <= num_messages; i++) {
        recv(sockfd, buf, sizeof(buf), 0);
        printf("%s", buf);
    }

    // Send the QUIT command to the POP3 server.
    sprintf(buf, "QUIT\r\n");
    send(sockfd, buf, strlen(buf), 0);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}