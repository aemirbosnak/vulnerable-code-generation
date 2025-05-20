//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

// function to send pop3 command to server and print response
void send_pop3_command(int sockfd, const char* command) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // send command
    send(sockfd, command, strlen(command), 0);

    // receive response
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';

    // print response
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    struct hostent *server_info;
    struct sockaddr_in server_addr;
    int sockfd, i;
    char buffer[BUFFER_SIZE];
    char *username, *password;
    ssize_t bytes_received;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    // get server info
    server_info = gethostbyname(argv[1]);
    if (server_info == NULL) {
        fprintf(stderr, "Error: no such host \n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // fill in server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // receive greeting from server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send username
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    username = strtok(buffer, "\n");
    sprintf(buffer, "USER %s\r\n", username);
    send_pop3_command(sockfd, buffer);

    // send password
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    password = strtok(buffer, "\n");
    sprintf(buffer, "PASS %s\r\n", password);
    send_pop3_command(sockfd, buffer);

    // send STAT command to get mailbox status
    send_pop3_command(sockfd, "STAT\r\n");

    // send LIST command to get list of messages
    send_pop3_command(sockfd, "LIST\r\n");

    // loop to retrieve each message
    for (i = 1; ; i++) {
        // send RETR command to retrieve message i
        sprintf(buffer, "RETR %d\r\n", i);
        send_pop3_command(sockfd, buffer);

        // ask if user wants to retrieve another message
        printf("Retrieve another message? (y/n): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (buffer[0] == 'n' || buffer[0] == 'N') {
            break;
        }
    }

    // send QUIT command to end session
    send_pop3_command(sockfd, "QUIT\r\n");

    // close socket
    close(sockfd);

    return 0;
}