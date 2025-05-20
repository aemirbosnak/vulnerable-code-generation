//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    if (inet_aton("127.0.0.1", &servaddr.sin_addr) == -1)
    {
        perror("inet_aton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    char mailto[1024];
    memset(mailto, 0, sizeof(mailto));
    printf("Enter the recipient's email address: ");
    scanf("%s", mailto);

    char mailfrom[1024];
    memset(mailfrom, 0, sizeof(mailfrom));
    printf("Enter the sender's email address: ");
    scanf("%s", mailfrom);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "MAIL FROM: <%s>\r\n", mailfrom);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RCPT TO: <%s>\r\n", mailto);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    char message[1024];
    memset(message, 0, sizeof(message));
    printf("Enter the email message: ");
    scanf("%[^\n]s", message);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%s\r\n.\r\n", message);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}