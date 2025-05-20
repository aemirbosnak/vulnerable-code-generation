//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110

int main(int argc, char const *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    
    char buffer[1024], username[50], password[50];
    int read_bytes;

    if (sock < 0) {
        perror("Could not create mail client socket.");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Cannot connect to the Mail server.");
        return -1;
    }

    printf("Welcome to the POP3 Mail Client!\n");

    printf("Enter your username: ");
    fgets(username, 50, stdin);
    username[strcspn(username, "\r\n")] = 0;

    printf("Enter your password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\r\n")] = 0;

    printf("Authenticating...\n");
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    read_bytes = recv(sock, buffer, 1024, 0);
    buffer[read_bytes] = '\0'; // Null-terminate the buffer.
    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    read_bytes = recv(sock, buffer, 1024, 0);
    buffer[read_bytes] = '\0'; // Null-terminate the buffer.
    printf("%s", buffer);

    printf("Logged in successfully.\n");

    printf("Fetching your emails...\n");
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);
    read_bytes = recv(sock, buffer, 1024, 0);
    buffer[read_bytes] = '\0'; // Null-terminate the buffer.
    printf("%s", buffer);

    printf("Select an email to read: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;

    sprintf(buffer, "RETR %s\r\n", buffer);
    send(sock, buffer, strlen(buffer), 0);
    read_bytes = recv(sock, buffer, 1024, 0);
    buffer[read_bytes] = '\0'; // Null-terminate the buffer.
    printf("%s", buffer);

    close(sock);

    return 0;
}