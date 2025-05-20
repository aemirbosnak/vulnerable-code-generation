//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_LINE_SIZE 1024
#define PORT 25
#define TIMEOUT_SECONDS 10
#define RECV_BUFFER_SIZE 4096

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char hostname[1024];
    char message[1024];
    char receive_buffer[RECV_BUFFER_SIZE];
    int message_len = 0;
    int receive_len = 0;

    // Get hostname from user
    printf("Enter hostname: ");
    scanf("%s", hostname);

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        printf("Error: Hostname not found.\n");
        return 1;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }

    // Send HELO command
    strcpy(message, "HELO ");
    strcat(message, hostname);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);

    // Send MAIL FROM command
    strcpy(message, "MAIL FROM: ");
    strcat(message, hostname);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);

    // Send RCPT TO command
    strcpy(message, "RCPT TO: ");
    strcat(message, hostname);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);

    // Send DATA command
    strcpy(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);

    // Send message body
    strcpy(message, "This is a test message.\r\n");
    send(sock, message, strlen(message), 0);

    // Send dot to end message
    strcpy(message, ".\r\n");
    send(sock, message, strlen(message), 0);

    // Receive response
    memset(receive_buffer, 0, RECV_BUFFER_SIZE);
    while (1)
    {
        int bytes_received = recv(sock, receive_buffer, RECV_BUFFER_SIZE, 0);
        if (bytes_received <= 0)
        {
            printf("Error: Failed to receive response.\n");
            return 1;
        }
        receive_buffer[bytes_received] = '\0';
        printf("Received: %s", receive_buffer);
        if (strstr(receive_buffer, "220")!= NULL)
        {
            break;
        }
    }

    // Close connection
    close(sock);
    return 0;
}