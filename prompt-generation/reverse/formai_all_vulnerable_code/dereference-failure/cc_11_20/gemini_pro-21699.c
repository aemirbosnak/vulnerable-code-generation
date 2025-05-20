//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_PRODUCTS 100

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void *handle_client(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[1024];
    int n;

    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        // Parse the request
        char *request = strtok(buffer, " ");
        char *args[10];
        int num_args = 0;
        while ((args[num_args] = strtok(NULL, " ")) != NULL) {
            num_args++;
        }

        // Handle the request
        if (strcmp(request, "GET") == 0) {
            // Send the list of products
            char response[1024];
            int i;
            for (i = 0; i < num_products; i++) {
                sprintf(response + strlen(response), "%d %s %d %f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            }
            write(sockfd, response, strlen(response));
        } else if (strcmp(request, "ADD") == 0) {
            // Add a new product
            if (num_args < 4) {
                write(sockfd, "Invalid request\n", strlen("Invalid request\n"));
                continue;
            }
            int id = atoi(args[0]);
            char *name = args[1];
            int quantity = atoi(args[2]);
            float price = atof(args[3]);
            products[num_products].id = id;
            strcpy(products[num_products].name, name);
            products[num_products].quantity = quantity;
            products[num_products].price = price;
            num_products++;
            write(sockfd, "Product added\n", strlen("Product added\n"));
        } else if (strcmp(request, "UPDATE") == 0) {
            // Update an existing product
            if (num_args < 5) {
                write(sockfd, "Invalid request\n", strlen("Invalid request\n"));
                continue;
            }
            int id = atoi(args[0]);
            char *name = args[1];
            int quantity = atoi(args[2]);
            float price = atof(args[3]);
            int i;
            for (i = 0; i < num_products; i++) {
                if (products[i].id == id) {
                    strcpy(products[i].name, name);
                    products[i].quantity = quantity;
                    products[i].price = price;
                    write(sockfd, "Product updated\n", strlen("Product updated\n"));
                    break;
                }
            }
            if (i == num_products) {
                write(sockfd, "Product not found\n", strlen("Product not found\n"));
            }
        } else if (strcmp(request, "DELETE") == 0) {
            // Delete an existing product
            if (num_args < 1) {
                write(sockfd, "Invalid request\n", strlen("Invalid request\n"));
                continue;
            }
            int id = atoi(args[0]);
            int i;
            for (i = 0; i < num_products; i++) {
                if (products[i].id == id) {
                    products[i] = products[num_products - 1];
                    num_products--;
                    write(sockfd, "Product deleted\n", strlen("Product deleted\n"));
                    break;
                }
            }
            if (i == num_products) {
                write(sockfd, "Product not found\n", strlen("Product not found\n"));
            }
        } else {
            // Invalid request
            write(sockfd, "Invalid request\n", strlen("Invalid request\n"));
        }
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t tid[MAX_CLIENTS];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Create a new thread to handle the client
        if (pthread_create(&tid[newsockfd], NULL, handle_client, &newsockfd) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
}