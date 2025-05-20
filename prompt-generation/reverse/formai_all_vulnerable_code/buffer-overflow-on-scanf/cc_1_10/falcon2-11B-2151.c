//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void print_stock(char *symbol, double price, double change, double volume) {
    printf("%s: %f %f %f\n", symbol, price, change, volume);
}

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char symbol[10];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to the server
    portno = PORT;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Request stock data
    printf("Enter a stock symbol: ");
    scanf("%s", symbol);
    strcpy(buffer, symbol);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));

    // Read the response from the server
    read(sockfd, buffer, sizeof(buffer));

    // Parse the response
    char *price = strtok(buffer, " ");
    char *change = strtok(NULL, " ");
    char *volume = strtok(NULL, " ");

    // Display the stock data
    printf("Stock: %s\n", symbol);
    printf("Price: %f\n", atof(price));
    printf("Change: %f\n", atof(change));
    printf("Volume: %f\n", atof(volume));

    // Close the socket
    close(sockfd);

    return 0;
}