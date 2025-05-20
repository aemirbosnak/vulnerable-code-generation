//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address = "mail.example.com";     // replace with your POP3 server address
    int server_port = 110;                        // default POP3 port

    // create socket
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // setup server address and port
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Error: Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // get server response
    char server_data[BUFFER_SIZE];
    int length;
    length = recv(sock, server_data, BUFFER_SIZE, 0);
    if (length == -1) {
        perror("Error: Failed to receive data");
        exit(EXIT_FAILURE);
    }
    server_data[length] = '\0';

    // print server response
    printf("%s", server_data);

    // send user name
    char *user_name = "user john";                 // replace with your user name
    length = send(sock, user_name, strlen(user_name), 0);
    if (length == -1) {
        perror("Error: Failed to send data");
        exit(EXIT_FAILURE);
    }

    // get server response
    length = recv(sock, server_data, BUFFER_SIZE, 0);
    if (length == -1) {
        perror("Error: Failed to receive data");
        exit(EXIT_FAILURE);
    }
    server_data[length] = '\0';

    // print server response
    printf("%s", server_data);

    // send password
    char *password = "pass mypassword";           // replace with your password
    length = send(sock, password, strlen(password), 0);
    if (length == -1) {
        perror("Error: Failed to send data");
        exit(EXIT_FAILURE);
    }

    // get server response
    length = recv(sock, server_data, BUFFER_SIZE, 0);
    if (length == -1) {
        perror("Error: Failed to receive data");
        exit(EXIT_FAILURE);
    }
    server_data[length] = '\0';

    // print server response
    printf("%s", server_data);

    // send list command
    char *list_command = "list";
    length = send(sock, list_command, strlen(list_command), 0);
    if (length == -1) {
        perror("Error: Failed to send data");
        exit(EXIT_FAILURE);
    }

    // get server response
    length = recv(sock, server_data, BUFFER_SIZE, 0);
    if (length == -1) {
        perror("Error: Failed to receive data");
        exit(EXIT_FAILURE);
    }
    server_data[length] = '\0';

    // print server response
    printf("%s", server_data);

    // send quit command
    char *quit_command = "quit";
    length = send(sock, quit_command, strlen(quit_command), 0);
    if (length == -1) {
        perror("Error: Failed to send data");
        exit(EXIT_FAILURE);
    }

    // get server response
    length = recv(sock, server_data, BUFFER_SIZE, 0);
    if (length == -1) {
        perror("Error: Failed to receive data");
        exit(EXIT_FAILURE);
    }
    server_data[length] = '\0';

    // print server response
    printf("%s", server_data);

    // close socket
    close(sock);

    return EXIT_SUCCESS;
}