//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_ADDRESS "pop3.server.com"
#define SERVER_PORT "110"

int main()
{
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int error;
    if ((error = getaddrinfo(SERVER_ADDRESS, SERVER_PORT, &hints, &result)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(error));
        exit(1);
    }

    int sockfd;
    struct addrinfo *rp;
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;

        close(sockfd);
    }

    if (rp == NULL)
    {
        fprintf(stderr, "Could not connect to server\n");
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // display welcome message from the server
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // send user name
    char username[256];
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // remove newline character
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response from server
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // send password
    char password[256];
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // remove newline character
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response from server
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // list messages in mailbox
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response from server
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // quit session
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response from server
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}