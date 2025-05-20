#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888

typedef struct {
    char fileName[256];
    char fileContent[4096];
} SyncFile;

int main() {
    int sockfd, new_fd, numBytes;
    struct sockaddr_in serv_addr;
    SyncFile *clientFile;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on bind");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        new_fd = accept(sockfd, NULL, NULL);
        clientFile = (SyncFile *) malloc(sizeof(SyncFile));

        numBytes = recv(new_fd, clientFile, sizeof(SyncFile), 0);
        printf("Received a new file: %s\n", clientFile->fileName);

        // DEREFERENCE NULL POINTER HERE
        printf("File content: %s\n", clientFile->fileContent);

        close(new_fd);
    }

    close(sockfd);
    return 0;
}
