//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock1, sock2, sock3;
    struct sockaddr_in server1, server2;
    char buffer1[1024], buffer2[1024];
    int num1, num2, sum = 0;

    // Create sockets
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    sock2 = socket(AF_INET, SOCK_STREAM, 0);

    // Set server addresses
    server1.sin_family = AF_INET;
    server1.sin_addr.s_addr = inet_addr("192.168.0.1");
    server1.sin_port = htons(PORT);

    server2.sin_family = AF_INET;
    server2.sin_addr.s_addr = inet_addr("192.168.0.2");
    server2.sin_port = htons(PORT);

    // Connect to servers
    connect(sock1, (struct sockaddr *)&server1, sizeof(server1));
    connect(sock2, (struct sockaddr *)&server2, sizeof(server2));

    // Receive numbers from servers
    recv(sock1, buffer1, 1024, 0);
    recv(sock2, buffer2, 1024, 0);

    // Calculate sum
    num1 = atoi(buffer1);
    num2 = atoi(buffer2);
    sum = num1 + num2;

    // Send result to client
    send(sock3, "Hello, client! The average of 1 and 2 is: ", 25, 0);
    send(sock3, &sum, sizeof(int), 0);

    // Close sockets
    close(sock1);
    close(sock2);
    close(sock3);

    return 0;
}