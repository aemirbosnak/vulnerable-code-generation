//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_MAX_LENGTH 1024
#define FILE_SIZE_MAX 1048576

int main(void) {
    char file_name[FILE_NAME_MAX_LENGTH];
    char recovered_data[FILE_SIZE_MAX];
    FILE *file;
    int file_size, recovered_size;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (!file) {
        printf("Unable to open file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);

    if (file_size > FILE_SIZE_MAX) {
        printf("File too large to recover!\n");
        return 1;
    }

    rewind(file);
    fread(recovered_data, 1, file_size, file);

    printf("Original file contents:\n");
    printf("%s\n", recovered_data);

    memset(recovered_data, 0, FILE_SIZE_MAX);
    recovered_size = snprintf(recovered_data, FILE_SIZE_MAX, "Recovered data for %s", file_name);

    fclose(file);
    file = fopen(file_name, "w");
    if (!file) {
        printf("Unable to open file for writing!\n");
        return 1;
    }

    fwrite(recovered_data, 1, recovered_size, file);

    fclose(file);

    printf("File successfully recovered and overwritten!\n");

    return 0;
}