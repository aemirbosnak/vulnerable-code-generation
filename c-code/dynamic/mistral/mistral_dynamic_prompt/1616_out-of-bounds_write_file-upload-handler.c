#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void upload_file(char* fileName, char* buffer) {
    FILE *file = fopen(fileName, "wb");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, stdin);
    while (bytesRead > 0) {
        fwrite(buffer, 1, bytesRead, file);
        bytesRead = fread(buffer, 1, BUFFER_SIZE, stdin);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    char fileName[128];
    char *buffer = malloc(BUFFER_SIZE);
    strcpy(fileName, argv[1]);

    // user input is considered the file data for simplicity
    // in a real-world scenario, this would come from a file, network request, etc.
    printf("Enter the file content (ctrl+d to finish):\n");
    char c;
    size_t i = 0;
    while ((c = getchar()) != EOF) {
        buffer[i++] = c;
        if (i >= BUFFER_SIZE) {
            printf("Buffer overflow detected. Exceeded %d bytes.\n", BUFFER_SIZE);
        }
    }

    upload_file(fileName, buffer);
    free(buffer);
    return 0;
}
