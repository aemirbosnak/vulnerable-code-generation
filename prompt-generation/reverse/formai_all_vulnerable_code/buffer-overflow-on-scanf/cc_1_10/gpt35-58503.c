//FormAI DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_SIZE 100

int main() {
    char file_name[FILE_NAME_SIZE];
    int shift_key;

    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);
    printf("Enter the shift key (integer): ");
    scanf("%d", &shift_key);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }

    // Obtain file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read file content into buffer
    char *buffer = malloc(file_size + 1);
    fread(buffer, 1, file_size, file);

    // Encrypt buffer
    for (int i = 0; i < file_size; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] = 'a' + ((buffer[i] - 'a' + shift_key) % 26);
        }
        else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] = 'A' + ((buffer[i] - 'A' + shift_key) % 26);
        }
    }

    // Write encrypted content to new file
    char *new_file_name = malloc(FILE_NAME_SIZE);
    sprintf(new_file_name, "%s_encrypted", file_name);
    FILE *new_file = fopen(new_file_name, "w");
    fwrite(buffer, 1, file_size, new_file);

    // Clean up and close files
    fclose(file);
    fclose(new_file);
    free(buffer);
    free(new_file_name);

    printf("Encryption Successful: %s_encrypted created.\n", file_name);
    return 0;
}