//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    // Define constants
    const char* server_ip = "pop3.example.com";
    const int server_port = 110;
    const char* username = "user@example.com";
    const char* password = "password";

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket");
        return 1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server");
        return 1;
    }

    // Login to server
    char buff[1024];
    int bytes_read = recv(sock, buff, 1024, 0);
    buff[bytes_read] = '\0';

    char username_command[256];
    sprintf(username_command, "USER %s\r\n", username);
    send(sock, username_command, strlen(username_command), 0);

    bytes_read = recv(sock, buff, 1024, 0);
    buff[bytes_read] = '\0';

    char password_command[256];
    sprintf(password_command, "PASS %s\r\n", password);
    send(sock, password_command, strlen(password_command), 0);

    bytes_read = recv(sock, buff, 1024, 0);
    buff[bytes_read] = '\0';

    // Retrieve mailbox information
    send(sock, "STAT\r\n", strlen("STAT\r\n"), 0);
    bytes_read = recv(sock, buff, 1024, 0);
    buff[bytes_read] = '\0';

    printf("%s", buff);

    // Retrieve list of messages
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    bytes_read = recv(sock, buff, 1024, 0);
    buff[bytes_read] = '\0';

    printf("%s", buff);

    // Logout and close socket
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    close(sock);

    return 0;
}