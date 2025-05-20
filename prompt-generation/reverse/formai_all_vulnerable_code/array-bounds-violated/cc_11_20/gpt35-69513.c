//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 110 // port used for POP3 protocol

int main(int argc, char *argv[]) {
    int sock, bytes_recieved;
    char buffer[1024];
    struct hostent *host;
    struct sockaddr_in server_address;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // get host from command line argument
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("Error getting host name");
        exit(1);
    }

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_address.sin_zero), 8);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // receive server greeting
    if ((bytes_recieved = recv(sock, buffer, 1024, 0)) == -1) {
        perror("Error receiving from server");
        exit(1);
    }
    buffer[bytes_recieved] = '\0';
    printf("%s", buffer);

    // send username
    char username_command[256];
    sprintf(username_command, "USER %s\n", argv[2]);
    if (send(sock, username_command, strlen(username_command), 0) == -1) {
        perror("Error sending username");
        exit(1);
    }

    // receive response to username command
    if ((bytes_recieved = recv(sock, buffer, 1024, 0)) == -1) {
        perror("Error receiving from server");
        exit(1);
    }
    buffer[bytes_recieved] = '\0';
    printf("%s", buffer);

    // send password
    char password[256];
    printf("Please enter your password: ");
    fgets(password, 256, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove newline character from password
    char password_command[256];
    sprintf(password_command, "PASS %s\n", password);
    if (send(sock, password_command, strlen(password_command), 0) == -1) {
        perror("Error sending password");
        exit(1);
    }

    // receive response to password command
    if ((bytes_recieved = recv(sock, buffer, 1024, 0)) == -1) {
        perror("Error receiving from server");
        exit(1);
    }
    buffer[bytes_recieved] = '\0';
    printf("%s", buffer);

    // send quit command
    char quit_command[10] = "QUIT\n";
    if (send(sock, quit_command, strlen(quit_command), 0) == -1) {
        perror("Error sending quit command");
        exit(1);
    }

    // receive response to quit command
    if ((bytes_recieved = recv(sock, buffer, 1024, 0)) == -1) {
        perror("Error receiving from server");
        exit(1);
    }
    buffer[bytes_recieved] = '\0';
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}