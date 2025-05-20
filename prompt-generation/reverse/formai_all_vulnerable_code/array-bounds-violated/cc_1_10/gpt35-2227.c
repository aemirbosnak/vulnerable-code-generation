//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: genious
/* POP3 Client Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

/* function to send data to server */
void send_to_server(int sock, char *message) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", message);
    send(sock, buffer, strlen(buffer), 0);
}

/* function to receive data from server */
void recv_from_server(int sock) {
    char buffer[MAX_BUFFER_SIZE];
    int n;
    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        printf("%.*s", n, buffer); // print received data
        if (buffer[n - 1] == '\n') {
            break; // end of message
        }
    }
}

int main(int argc, char* argv[]) {
    /* check input arguments */
    if (argc < 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(1);
    }

    /* create socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    /* initialize server address */
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    /* connect to server */
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    /* receive welcome message */
    recv_from_server(sock);

    /* send username */
    char username[MAX_BUFFER_SIZE];
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    send_to_server(sock, username);
    recv_from_server(sock);

    /* send password */
    char password[MAX_BUFFER_SIZE];
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    send_to_server(sock, password);
    recv_from_server(sock);

    /* send STAT command to get number of messages */
    send_to_server(sock, "STAT");
    recv_from_server(sock);

    /* send LIST command to get list of messages */
    send_to_server(sock, "LIST");
    recv_from_server(sock);

    /* select message to retrieve */
    char message_id[MAX_BUFFER_SIZE];
    printf("Message ID: ");
    fgets(message_id, sizeof(message_id), stdin);
    send_to_server(sock, message_id);
    recv_from_server(sock);

    /* send RETR command to retrieve message */
    send_to_server(sock, "RETR");
    recv_from_server(sock);

    /* close socket */
    close(sock);
    
    return 0;
}