//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "pop.mail.com"
#define PORT "110"

int main() {
    int sock;
    struct sockaddr_in server_address;
    struct hostent *host;
    char buffer[1024];
    char username[50], password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket");
        exit(1);
    }

    // Get IP address of server
    host = gethostbyname(SERVER);

    if (host == NULL) {
        printf("Error: Could not resolve hostname");
        exit(1);
    }

    // Setup the server address
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(PORT));
    server_address.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)host->h_addr)));

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Error: Could not receive message from server");
        exit(1);
    }

    // Send username to server
    char user_request[100];
    strcpy(user_request, "USER ");
    strcat(user_request, username);
    strcat(user_request, "\r\n");

    if (send(sock, user_request, strlen(user_request), 0) < 0) {
        printf("Error: Could not send username to server");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Error: Could not receive message from server");
        exit(1);
    }

    // Send password to server
    char pass_request[100];
    strcpy(pass_request, "PASS ");
    strcat(pass_request, password);
    strcat(pass_request, "\r\n");

    if (send(sock, pass_request, strlen(pass_request), 0) < 0) {
        printf("Error: Could not send password to server");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Error: Could not receive message from server");
        exit(1);
    }

    // Send STAT command to server
    char stat_request[] = "STAT\r\n";

    if (send(sock, stat_request, strlen(stat_request), 0) < 0) {
        printf("Error: Could not send STAT command to server");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Error: Could not receive message from server");
        exit(1);
    }

    // Parse the response to get the number of emails
    int num_emails;
    char *ptr;
    ptr = strtok(buffer, " ");

    while (ptr != NULL) {
        if (isdigit(*ptr)) {
            num_emails = atoi(ptr);
            break;
        }

        ptr = strtok(NULL, " ");
    }

    printf("You have %d emails\n", num_emails);

    // Send QUIT command to server
    char quit_request[] = "QUIT\r\n";

    if (send(sock, quit_request, strlen(quit_request), 0) < 0) {
        printf("Error: Could not send QUIT command to server");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Error: Could not receive message from server");
        exit(1);
    }

    // Close the socket
    close(sock);

    return 0;
}