//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILES 10

void file_read(char* filename, char* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    data = (char*)malloc(file_size + 1);
    if (data == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    int bytes_read = fread(data, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error reading file '%s'\n", filename);
        free(data);
        return;
    }

    data[file_size] = '\0';
    fclose(file);
}

int main() {
    char data[MAX_FILE_SIZE];
    char files[MAX_FILES][MAX_FILE_SIZE];
    int file_count = 0;

    printf("Enter the file names separated by a space:\n");
    scanf("%[^\n]s", files);

    while (files[file_count]!= NULL) {
        file_read(files[file_count], data);
        printf("Data from file '%s':\n%s\n", files[file_count], data);
        file_count++;
    }

    return 0;
}