//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 21

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[256];
    char command[100];
    char *args[10];

    printf("\n\nWelcome to FTP Client v1.0 by Ken Thompson\n");
    printf("-------------------------------------------\n");

    while (1) {
        printf("\nCommands:\n");
        printf("1. Connect to server\n");
        printf("2. Login\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter server IP: ");
                scanf("%s", serveraddr.sin_addr.s_addr);
                serveraddr.sin_family = AF_INET;
                serveraddr.sin_port = htons(PORT);

                sockfd = socket(AF_INET, SOCK_STREAM, 0);
                connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
                printf("Connected to server\n");
                break;

            case 2:
                printf("Enter username: ");
                fgets(command, sizeof(command), stdin);
                command[strlen(command) - 1] = '\0';
                strcpy(args[0], "USER");
                strcat(args[0], " ");
                strcat(args[0], command);
                write(sockfd, args[0], strlen(args[0]));

                printf("Enter password: ");

                // Reversed string algorithm to hide password input
                char password[20];
                int i;
                for (i = 0; i < 20; i++) {
                    password[i] = getchar();
                    putchar('*');
                }
                password[i] = '\0';

                for (int j = 0; j < strlen(password); j++) {
                    char temp = password[j];
                    password[j] = password[strlen(password) - 1 - j];
                    password[strlen(password) - 1 - j] = temp;
                }

                strcpy(args[0], "PASS");
                strcat(args[0], " ");
                write(sockfd, args[0], strlen(args[0]));

                for (int k = 0; k < strlen(password); k++) {
                    write(sockfd, &password[k], 1);
                }
                write(sockfd, "\r\n", 2);
                break;

            case 3:
                close(sockfd);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}