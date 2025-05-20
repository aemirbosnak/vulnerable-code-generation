//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define VIRUS_PATTERN "virus.exe"

int is_infected(char *file_content, int file_size) {
    if (strstr(file_content, VIRUS_PATTERN)!= NULL) {
        printf("Virus detected in %s\n", file_content);
        return 1;
    }
    return 0;
}

int main() {
    char file_name[100];
    FILE *file;
    char *file_content = NULL;
    int file_size = 0;

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file
    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    // Check file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        exit(1);
    }

    // Allocate memory for file content
    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Read file content
    rewind(file);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    // Scan for virus
    if (is_infected(file_content, file_size)) {
        exit(1);
    }

    // Print file content
    printf("File content:\n%s\n", file_content);

    // Free memory
    free(file_content);

    // Close file
    fclose(file);

    return 0;
}