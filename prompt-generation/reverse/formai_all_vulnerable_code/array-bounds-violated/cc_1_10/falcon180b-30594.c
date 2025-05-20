//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_data[MAX_FILE_SIZE];
} FileData;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    FILE *file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size == -1) {
        printf("Error getting file size\n");
        fclose(file);
        return 1;
    }

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds maximum limit of 10MB\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    FileData file_data;
    memset(&file_data, 0, sizeof(FileData));

    fread(file_data.file_name, 1, MAX_FILE_NAME_LENGTH - 1, file);
    file_data.file_name[MAX_FILE_NAME_LENGTH - 1] = '\0';

    fread(file_data.file_data, 1, file_size, file);
    file_data.file_data[file_size] = '\0';

    fclose(file);

    printf("File name: %s\n", file_data.file_name);
    printf("File data:\n%s\n", file_data.file_data);

    return 0;
}