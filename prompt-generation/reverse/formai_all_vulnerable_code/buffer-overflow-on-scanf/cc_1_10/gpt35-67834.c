//FormAI DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_NUM 8888

void cyberpunk_connect(int sock)
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT_NUM);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to Cyber Network\n");
}

void cyberpunk_send(int sock, const char *message)
{
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error: Send failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Sent message: %s\n", message);
}

void cyberpunk_recv(int sock)
{
    char buf[1024] = {0};
    int bytes_received = 0;

    if ((bytes_received = recv(sock, buf, sizeof(buf), 0)) < 0) {
        perror("Error: Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s", buf);
}

int main(void)
{
    int sock = 0;
    struct sockaddr_in server_addr;
    char message[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Socket creation failed");
        exit(EXIT_FAILURE);
    }

    cyberpunk_connect(sock);

    printf("Enter message to send: ");
    scanf("%s", message);

    cyberpunk_send(sock, message);

    cyberpunk_recv(sock);

    return 0;
}