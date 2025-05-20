#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    char request[BUFFER_SIZE];
    char filename[256];
    char buffer[BUFFER_SIZE];
    FILE *file;

    if (argc != 3) {
        printf("Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    strcpy(request, argv[1]);
    strcat(request, " HTTP/1.1\r\n");
    strcat(request, "Content-Type: multipart/form-data\r\n");
    strcat(request, "Content-Length: ");
    char length[12];
    sprintf(length, "%d\r\n", strlen(argv[2]) + 1);
    strcat(request, length);
    strcat(request, "\r\n\r\n");
    strcat(request, argv[2]);

    file = fopen("uploaded_files", "ab");
    if (!file) {
        perror("Failed to open file for writing");
        return 1;
    }

    fwrite(request, 1, strlen(request), file);
    fclose(file);

    return 0;
}
