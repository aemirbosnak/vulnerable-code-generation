//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Recursively reverse a string
char *reverse_string(char *str) {
    if (*str == '\0') {
        return str;
    }
    else {
        return reverse_string(str + 1) + 1;
    }
}

// Recursively calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Recursively calculate the sum of the digits in a number
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n % 10 + sum_of_digits(n / 10);
    }
}

int main() {
    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the loopback address and a random port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = htons(0);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Get the port number assigned to the socket
    int addrlen = sizeof(addr);
    if (getsockname(sockfd, (struct sockaddr *)&addr, &addrlen) == -1) {
        perror("getsockname");
        exit(1);
    }

    // Print the port number
    printf("Listening on port %d\n", ntohs(addr.sin_port));

    // Accept a connection
    int clientfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
    if (clientfd == -1) {
        perror("accept");
        exit(1);
    }

    // Receive data from the client
    char buffer[1024];
    int nbytes = recv(clientfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        exit(1);
    }

    // Reverse the received data
    char *reversed_data = reverse_string(buffer);

    // Calculate the factorial of the length of the received data
    int factorial_of_length = factorial(strlen(buffer));

    // Calculate the sum of the digits in the length of the received data
    int sum_of_digits_of_length = sum_of_digits(strlen(buffer));

    // Send the reversed data, the factorial of the length, and the sum of the digits in the length back to the client
    char response[1024];
    sprintf(response, "%s %d %d", reversed_data, factorial_of_length, sum_of_digits_of_length);
    if (send(clientfd, response, strlen(response), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the client connection
    close(clientfd);

    // Close the server socket
    close(sockfd);

    return 0;
}