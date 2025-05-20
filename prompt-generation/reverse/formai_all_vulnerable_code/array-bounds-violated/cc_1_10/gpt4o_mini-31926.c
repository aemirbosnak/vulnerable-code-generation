//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define HOSTNAME "ftp.example.com" // Loving whisper: Change to your sweet server address

void flirtWithServer(int sockfd);
void caressTheData(int sockfd);
void serenade(const char* command, int sockfd);
void listenToTheEcho(int sockfd);
void promiseToUpload(int sockfd, const char* filename);
void whisperToDownload(int sockfd, const char* filename);

int main() {
    struct sockaddr_in server_addr;
    char username[50], password[50];
    int sockfd;

    // Caressing the heart before we plunge into the depths
    printf("Welcome, my love, to the FTP Client.\n");
    printf("Please, whisper your username: ");
    scanf("%s", username);
    printf("And your secret password: ");
    scanf("%s", password);

    // Sweet connection to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Oh no, my love! The connection was not made.");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    struct hostent *host = gethostbyname(HOSTNAME);
    if (host == NULL) {
        fprintf(stderr, "Unable to resolve the host name.");
        return 1;
    }
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Dearest connection
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("The connection has failed, my heart aches.");
        return 1;
    }

    flirtWithServer(sockfd);
    serenade("USER ", sockfd);
    serenade(username, sockfd);
    serenade("PASS ", sockfd);
    serenade(password, sockfd);
    caressTheData(sockfd);

    // Choose your adventure, my love
    int choice;
    char filename[100];
    while (1) {
        printf("What would you like to do?\n1. List files\n2. Upload a file\n3. Download a file\n4. Exit\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                serenade("LIST", sockfd);
                listenToTheEcho(sockfd);
                break;
            case 2:
                printf("Oh, my darling, which file would you like to upload? ");
                scanf("%s", filename);
                promiseToUpload(sockfd, filename);
                break;
            case 3:
                printf("Which file stirs your heart's desire to download? ");
                scanf("%s", filename);
                whisperToDownload(sockfd, filename);
                break;
            case 4:
                printf("As we part, my love, know that the distance does not lessen my heart's affection.\n");
                close(sockfd);
                return 0;
            default:
                printf("Your choice was a little unclear. Please choose a number between 1 and 4.\n");
        }
    }
}

void flirtWithServer(int sockfd) {
    listenToTheEcho(sockfd);
}

void caressTheData(int sockfd) {
    printf("Caressing the connection...\n");
    listenToTheEcho(sockfd);
}

void serenade(const char* command, int sockfd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s%s\r\n", command, command);
    send(sockfd, buffer, strlen(buffer), 0);
    listenToTheEcho(sockfd);
}

void listenToTheEcho(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesReceived = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        printf("%s", buffer);
    } else {
        printf("Alas, I cannot hear the sweet nothings from our beloved server.\n");
    }
}

void promiseToUpload(int sockfd, const char* filename) {
    serenade("STOR ", sockfd);
    serenade(filename, sockfd);
    // Implementation of the upload would go here (omitted for brevity)
}

void whisperToDownload(int sockfd, const char* filename) {
    serenade("RETR ", sockfd);
    serenade(filename, sockfd);
    // Implementation of the download would go here (omitted for brevity)
}