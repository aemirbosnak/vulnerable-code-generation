//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char command[1024];
    char filename[1024];
    char* server_ip = "ftpserver.net";
    int port_num = 21;
  
    printf("Hello there, I am your new FTP client!\n");
    printf("Let me go ahead and connect to the server for you..\n");

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    server_addr.sin_addr.s_addr = inet_addr(server_ip); 

    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        printf("Oops! There was an error connecting to the server. Could you check your internet connection please?\n");
        return -1;
    }

    printf("Great! I'm now connected to the FTP server. What would you like to do next?\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer)); 
        memset(command, 0, sizeof(command));
        memset(filename, 0, sizeof(filename));
      
        printf("\nType in your command or type 'exit' to quit: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; 

        if (strcmp(command, "exit") == 0) {
            printf("\nGoodbye! Thanks for using my FTP client!\n");
            return 0;
        }

        if (strncmp(command, "get", 3) == 0) {
            sscanf(command+4, "%s", filename);
            sprintf(buffer, "RETR %s\r\n", filename);
            send(sock_fd, buffer, strlen(buffer), 0);
            recv(sock_fd, buffer, sizeof(buffer), 0);
            printf("\n%s", buffer);
            if (strncmp(buffer, "550", 3) == 0) {
                printf("Sorry, the file \"%s\" does not exist on the server.\n", filename);
                continue;
            }
            FILE* fp = fopen(filename, "wb");
            while (recv(sock_fd, buffer, sizeof(buffer), 0) > 0) {
                fwrite(buffer, 1, sizeof(buffer), fp);
                memset(buffer, 0, sizeof(buffer));
            }
            fclose(fp);
            printf("Success! Downloaded file \"%s\"\n", filename);
        }

        else if (strncmp(command, "ls", 2) == 0) {
            sprintf(buffer, "LIST\r\n");
            send(sock_fd, buffer, strlen(buffer), 0);
            recv(sock_fd, buffer, sizeof(buffer), 0);
            printf("\n%s", buffer);
            if (strncmp(buffer, "550", 3) == 0) {
                printf("Sorry, there are no files to display on the server.");
                continue;
            }
            while (recv(sock_fd, buffer, sizeof(buffer), 0) > 0) {
                printf("%s", buffer);
                memset(buffer, 0, sizeof(buffer));
            }
        }

        else {
            printf("Oops! Invalid command. Try again.\n");
        }
    }

    close(sock_fd);
    return 0;
}