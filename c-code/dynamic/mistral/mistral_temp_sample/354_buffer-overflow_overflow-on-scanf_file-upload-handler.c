#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define MAX_FILE_SIZE 1000

void process_file(char* file_data) {
    char buffer[BUFFER_SIZE];
    int pos = 0;

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        if (pos + strlen(buffer) + 1 > MAX_FILE_SIZE) {
            printf("File size exceeded.\n");
            break;
        }
        strcat(file_data, buffer);
        pos += strlen(buffer) + 1;
    }
}

int main() {
    char file_data[MAX_FILE_SIZE];
    char buffer[256];

    printf("Upload a file (max size: %d bytes):\n", MAX_FILE_SIZE);
    scanf("%s", buffer);
    process_file(file_data);
    printf("File data received:\n%s\n", file_data);
    return 0;
}
