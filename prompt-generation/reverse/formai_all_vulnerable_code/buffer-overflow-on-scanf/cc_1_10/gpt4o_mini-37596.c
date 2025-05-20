//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void flirtWithTheServer(const char *server_ip, int port);
void offerMyHeart(FILE *fp, const char *file_name, const char *server_ip, int port);
void shareMyLove(int sockfd, const char *file_name);
void whisperGoodbye(int sockfd);

int main() {
    char server_ip[20];
    int port;
    
    printf("Oh, my dear, where does your heart reside? (Enter FTP server IP): ");
    fgets(server_ip, sizeof(server_ip), stdin);
    
    printf("What port shall we dance on? (Enter FTP port, usually 21): ");
    scanf("%d", &port);
    
    flirtWithTheServer(server_ip, port);
    
    return 0;
}

void flirtWithTheServer(const char *server_ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Oh dear! Couldn't create a socket!");
        return;
    }

    // Configuring the server's address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Attempting to connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Curses! The connection to your love was denied.");
        close(sockfd);
        return;
    }

    // Listening to the server's sweet nothings
    recv(sockfd, response, sizeof(response), 0);
    printf("Server says: %s\n", response);

    // Offering a file to be sent (File name prompt)
    char file_name[255];
    printf("What tender file shall I offer to the server? (Enter file name): ");
    scanf("%s", file_name);
    
    offerMyHeart(fopen(file_name, "rb"), file_name, server_ip, port);
    
    whisperGoodbye(sockfd);
}

void offerMyHeart(FILE *fp, const char *file_name, const char *server_ip, int port) {
    if (fp == NULL) {
        perror("I can't find your precious file... Can we find another?");
        return;
    }

    // Optionally, here we would send authentication details,
    // but let's focus on the romance of file transfer!
    
    // Share the love
    shareMyLove(fileno(fp), file_name);

    fclose(fp);
    printf("Ah, the file has flown to my beloved server...\n");
}

void shareMyLove(int sockfd, const char *file_name) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead, totalSent = 0;

    // The file size to let the server know what to expect
    FILE *fp = fopen(file_name, "rb");
    
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    
    // Sending the size of the file to the server
    send(sockfd, &file_size, sizeof(file_size), 0);
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        if (send(sockfd, buffer, bytesRead, 0) == -1) {
            perror("Oh! The love was not fully received!");
            break;
        }
        totalSent += bytesRead;
        printf("Sent %zu of %ld bytes... My heart beats faster!\n", totalSent, file_size);
    }

    printf("All my love has been sent, elegantly and effortlessly!\n");
    fclose(fp);
}

void whisperGoodbye(int sockfd) {
    close(sockfd);
    printf("Alas, I bid you adieu, sweet server. Until we meet again!\n");
}