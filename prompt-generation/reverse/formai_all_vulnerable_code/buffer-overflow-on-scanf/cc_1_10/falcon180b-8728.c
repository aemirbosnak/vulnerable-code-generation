//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
} FileData;

int main() {
    FILE *file_in, *file_out;
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
    FileData file_data;

    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    file_in = fopen(file_name, "rb");
    if (file_in == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file_in, 0, SEEK_END);
    int file_size = ftell(file_in);
    rewind(file_in);

    if (file_size > MAX_FILE_CONTENT_LENGTH) {
        printf("Error: File content too large.\n");
        exit(1);
    }

    fread(file_content, sizeof(char), file_size, file_in);
    fclose(file_in);

    file_data.file_name[0] = '\0';
    strcat(file_data.file_name, file_name);
    strcat(file_data.file_name, ".recovered");

    file_out = fopen(file_data.file_name, "wb");
    if (file_out == NULL) {
        printf("Error: Failed to create recovered file.\n");
        exit(1);
    }

    fwrite(file_content, sizeof(char), file_size, file_out);
    fclose(file_out);

    printf("File recovery successful.\n");
    return 0;
}