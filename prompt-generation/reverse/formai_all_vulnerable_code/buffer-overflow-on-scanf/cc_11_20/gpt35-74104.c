//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

int main() {
    int client_socket, port_number, n;
    char buffer[1024];
    struct sockaddr_in server_address;
    struct hostent *server;

    port_number = 25; // SMTP port number

    printf("Enter server hostname: ");
    char hostname[100];
    scanf("%s", hostname);

    // get server IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return 1;
    }
    char *server_ip = inet_ntoa(*(struct in_addr *)server->h_addr_list[0]);

    // create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        return 1;
    }

    // connect to server
    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_aton(server_ip, &(server_address.sin_addr));
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        return 1;
    }

    // read welcome message from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // send HELO command
    char helo_cmd[100];
    sprintf(helo_cmd, "HELO %s\r\n", hostname);
    n = write(client_socket, helo_cmd, strlen(helo_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // read response from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // send MAIL FROM command
    char mail_from_cmd[100];
    printf("Enter your email address: ");
    char from_address[100];
    scanf("%s", from_address);
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", from_address);
    n = write(client_socket, mail_from_cmd, strlen(mail_from_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // read response from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // send RCPT TO command
    char rcpt_to_cmd[100];
    printf("Enter recipient email address: ");
    char to_address[100];
    scanf("%s", to_address);
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", to_address);
    n = write(client_socket, rcpt_to_cmd, strlen(rcpt_to_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // read response from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // send DATA command
    char data_cmd[100];
    sprintf(data_cmd, "DATA\r\n");
    n = write(client_socket, data_cmd, strlen(data_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // read response from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // send message
    printf("Enter email message:\n");
    char message[1000];
    getchar();
    fgets(message, 1000, stdin);
    n = write(client_socket, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // send QUIT command
    char quit_cmd[100];
    sprintf(quit_cmd, "QUIT\r\n");
    n = write(client_socket, quit_cmd, strlen(quit_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return 1;
    }

    // read response from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    // close socket
    close(client_socket);

    return 0;
}