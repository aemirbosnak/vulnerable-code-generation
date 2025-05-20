//FormAI DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    // code to initialize server address and port
    struct sockaddr_in server_addr;
    struct hostent *server;
    int port = atoi(argv[2]);
    char *hostname = argv[1];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host.\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // code to connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Connection failed.\n");
        exit(1);
    }

    // code to authenticate user
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "220") != NULL) {
            break;
        }
    }
    char user[50], pass[50];
    printf("Username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "331") != NULL) {
            break;
        }
    }
    printf("Password: ");
    scanf("%s", pass);
    sprintf(buffer, "PASS %s\r\n", pass);
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "230") != NULL) {
            break;
        }
    }

    // code to send email
    char from[50], to[50], subject[100], msg[BUFFER_SIZE];
    printf("From: ");
    scanf("%s", from);
    printf("To: ");
    scanf("%s", to);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Message: ");
    scanf("%s", msg);
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "250") != NULL) {
            break;
        }
    }
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "250") != NULL) {
            break;
        }
    }
    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "354") != NULL) {
            break;
        }
    }
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, msg);
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "250") != NULL) {
            break;
        }
    }
    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "221") != NULL) {
            break;
        }
    }
    close(sockfd);

    return 0;
}