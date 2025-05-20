#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char* buffer) {
    char fileName[256];
    char fileData[BUFFER_SIZE];
    FILE *file;

    strcpy(fileName, "uploaded_files/");
    strcat(fileName, buffer);
    strcat(fileName, ".txt");

    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating file: %s\n", fileName);
        return;
    }

    fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);
    printf("File uploaded: %s\n", fileName);
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter file to upload (up to %d bytes):\n", BUFFER_SIZE);
    gets(buffer);

    handle_file_upload(buffer);

    return 0;
}
