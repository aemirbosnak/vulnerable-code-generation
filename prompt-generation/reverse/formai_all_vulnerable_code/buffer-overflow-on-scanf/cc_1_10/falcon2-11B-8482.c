//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int get_stock_prices(char* symbol, char* prices[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];
    int n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    // Send request to server
    sprintf(buffer, "%s\n", symbol);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    // Parse response and populate prices array
    char* price_str;
    int i;
    char* token;

    price_str = strtok(buffer, "\n");
    while (price_str!= NULL) {
        token = strtok(NULL, "\t");
        prices[i++] = token;
        price_str = strtok(NULL, "\n");
    }

    // Close socket
    close(sockfd);

    return i;
}

int main() {
    char symbol[50];
    char prices[100][50];
    int num_prices;

    // Get stock symbol from user
    printf("Enter stock symbol: ");
    scanf("%s", symbol);

    // Get stock prices
    num_prices = get_stock_prices(symbol, prices);

    if (num_prices > 0) {
        printf("Stock Prices:\n");
        for (int i = 0; i < num_prices; i++) {
            printf("%s\n", prices[i]);
        }
    } else {
        printf("Error fetching stock prices\n");
    }

    return 0;
}