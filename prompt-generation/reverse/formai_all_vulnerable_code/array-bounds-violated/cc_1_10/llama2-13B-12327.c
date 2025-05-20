//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DIARY_FILE "diary.txt"
#define DIARY_SIZE 1024 * 1024 * 10

struct entry {
    char date[20];
    char title[50];
    char text[256];
};

int main(void) {
    int sock;
    struct sockaddr_in server_addr;
    struct entry entry;
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Read the diary file from the server
    read(sock, buffer, 256);
    buffer[256] = '\0';
    printf("Diary entry: %s\n", buffer);

    // Write a new diary entry to the server
    entry.date[0] = 'T';
    entry.date[1] = 'oday';
    entry.title[0] = 'My';
    entry.title[1] = 'Diary';
    entry.text[0] = 'This';
    entry.text[1] = 'is';
    entry.text[2] = 'my';
    entry.text[3] = 'diary';
    write(sock, &entry, sizeof(entry));

    // Close the socket
    close(sock);

    return 0;
}