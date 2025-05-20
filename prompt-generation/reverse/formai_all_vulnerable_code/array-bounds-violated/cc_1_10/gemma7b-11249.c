//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define PORT 8080

typedef struct {
    char name[50];
    int age;
} Person;

Person persons[10] = {
    {"John Doe", 25},
    {"Jane Doe", 30},
    {"Peter Pan", 12},
    {"Mary Poppins", 20},
    {"The Cat in the Hat", 4},
    {"SpongeBob SquarePants", 32},
    {"Bob Belcher", 40},
    {"Tina Belcher", 35},
    {"Linda Belcher", 22},
    {"Gene Belcher", 28}
};

void handle_client(int sockfd) {
    char buf[1024];
    int len = recv(sockfd, buf, 1024, 0);
    buf[len] = '\0';
    printf("Client: %s\n", buf);

    char response[1024];
    sprintf(response, "Hello, %s! You are %d years old.", buf, persons[0].age);
    send(sockfd, response, strlen(response), 0);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Bind socket to port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for connections
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);
        handle_client(newsockfd);
        close(newsockfd);
    }

    return 0;
}