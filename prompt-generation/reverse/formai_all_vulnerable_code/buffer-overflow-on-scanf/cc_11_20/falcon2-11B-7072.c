//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int socket_fd, port_number, conn_fd, n;
    struct sockaddr_in server_address, client_address;
    char buffer[1024], command[20], *ptr;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Enter the command: ");
    scanf("%s", command);

    if (strcmp(command, "help") == 0) {
        printf("Available commands:\n");
        printf("help\n");
        printf("cd <directory>\n");
        printf("ls\n");
        printf("put <filename> <local_path>\n");
        printf("get <filename> <remote_path>\n");
        printf("quit\n");
    } else if (strcmp(command, "cd") == 0) {
        printf("Enter the directory: ");
        scanf("%s", buffer);
        ptr = strtok(buffer, " \t\n");
        while (ptr!= NULL) {
            write(socket_fd, ptr, strlen(ptr));
            printf("> %s\n", ptr);
            ptr = strtok(NULL, " \t\n");
        }
    } else if (strcmp(command, "ls") == 0) {
        ptr = "";
        if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
            perror("ERROR reading from socket");
            exit(1);
        }
        ptr = buffer;
        printf("%s\n", ptr);
    } else if (strcmp(command, "put") == 0) {
        printf("Enter the filename: ");
        scanf("%s", buffer);
        printf("Enter the local path: ");
        scanf("%s", buffer);
        ptr = strtok(buffer, " \t\n");
        while (ptr!= NULL) {
            write(socket_fd, ptr, strlen(ptr));
            printf("> %s\n", ptr);
            ptr = strtok(NULL, " \t\n");
        }
    } else if (strcmp(command, "get") == 0) {
        printf("Enter the filename: ");
        scanf("%s", buffer);
        printf("Enter the remote path: ");
        scanf("%s", buffer);
        ptr = strtok(buffer, " \t\n");
        while (ptr!= NULL) {
            write(socket_fd, ptr, strlen(ptr));
            printf("> %s\n", ptr);
            ptr = strtok(NULL, " \t\n");
        }
    } else if (strcmp(command, "quit") == 0) {
        close(socket_fd);
        exit(0);
    } else {
        printf("Invalid command\n");
    }

    return 0;
}