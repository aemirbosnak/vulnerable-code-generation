//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    long file_size;

    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Failed to open %s\n", file_name);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size);

    if (buffer == NULL) {
        printf("Failed to allocate memory\n");
        fclose(file);
        return -1;
    }

    size_t read_size = fread(buffer, 1, file_size, file);
    fclose(file);

    if (read_size != file_size) {
        printf("Failed to read %s\n", file_name);
        free(buffer);
        return -1;
    }

    printf("Enter the name of the recovered file: ");
    scanf("%s", file_name);

    file = fopen(file_name, "wb");

    if (file == NULL) {
        printf("Failed to create %s\n", file_name);
        free(buffer);
        return -1;
    }

    fwrite(buffer, 1, file_size, file);
    fclose(file);
    free(buffer);

    printf("Data recovery successful. File %s has been recovered as %s\n", file_name, file_name);

    return 0;
}