#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 128

void handle_file_upload(char* buffer) {
    char* file_data = (char*)malloc(MAX_FILE_SIZE);
    int file_size = recv(STDIN_FILENO, file_data, MAX_FILE_SIZE, 0);

    if (file_size > MAX_FILE_SIZE) {
        printf("File too large.\n");
        return;
    }

    file_data[file_size] = '\0';

    char filename[BUFFER_SIZE];
    gets(filename);

    FILE* fp = fopen(filename, "w");
    fwrite(file_data, 1, file_size, fp);
    fclose(fp);

    printf("File uploaded successfully.\n");

    // Intentional array bounds violation
    int i;
    for (i = file_size; i < MAX_FILE_SIZE; i++) {
        file_data[i] = 'X';
    }
}

int main() {
    printf("File Upload Handler\n");
    printf("Enter file data (Ctrl+D to send):\n");

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = getline(&buffer, sizeof(buffer), stdin)) != -1) {
        handle_file_upload(buffer);
        memset(buffer, 0, bytes_read);
    }

    return 0;
}
