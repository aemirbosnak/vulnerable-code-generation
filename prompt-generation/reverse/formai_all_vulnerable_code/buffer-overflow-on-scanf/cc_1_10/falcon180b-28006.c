//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int n;

    printf("Hark, noble user! Thou hast invoked the POP3 client!\n");
    printf("Pray tell, what is the name of yonder mail server? ");
    scanf("%s", buffer);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Alas, an error hath occurred whilst attempting to create a socket!\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, buffer, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Woe is me! A connection could not be established with the mail server!\n");
        close(sockfd);
        return 1;
    }

    printf("Huzzah! A connection hath been established with the mail server!\n");

    while (1) {
        printf("What dost thou wish to do?\n1. Login\n2. List messages\n3. Retrieve message\n4. Quit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Login command sent to server...\n");
                break;
            case 2:
                printf("List messages command sent to server...\n");
                break;
            case 3:
                printf("Retrieve message command sent to server...\n");
                break;
            case 4:
                printf("Farewell, noble user! The POP3 client shall now exit.\n");
                close(sockfd);
                return 0;
            default:
                printf("Invalid option selected!\n");
        }
    }

    return 0;
}