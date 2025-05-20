#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 128

void handle_file_upload(const char* filename, const char* content) {
    char local_filename[MAX_FILENAME_LENGTH];
    char* ptr;

    // Simulate reading the filename from user input
    if (strlen(filename) > MAX_FILENAME_LENGTH - 1) {
        fprintf(stderr, "Filename too long\n");
        return;
    }
    strcpy(local_filename, filename);

    // Vulnerable gets call
    printf("Enter new content: ");
    gets(ptr = local_filename + strlen(local_filename));

    // Simulate saving the file
    FILE* file = fopen(local_filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fputs(content, file);
    fclose(file);

    printf("File '%s' uploaded successfully.\n", local_filename);
}

int main() {
    const char* filename = "example.txt";
    const char* content = "This is some example content.";

    handle_file_upload(filename, content);

    return 0;
}
