//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_FILE_SIZE 104857600 // 100MB

int main(int argc, char const *argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE *file_ptr = fopen(filename, "rb");
    if (!file_ptr) {
        perror("Error opening file");
        exit(1);
    }
    
    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    if (file_size > MAX_FILE_SIZE) {
        printf("Warning: file is larger than %d bytes. Proceed with caution.\n", MAX_FILE_SIZE);
    }
    
    fseek(file_ptr, 0, SEEK_SET);
    char *file_contents = malloc(file_size);
    if (!file_contents) {
        perror("Error allocating memory");
        exit(1);
    }
    
    fread(file_contents, 1, file_size, file_ptr);
    fclose(file_ptr);
    
    // Analyze file contents
    int num_spaces = 0;
    int num_newlines = 0;
    int num_tabs = 0;
    
    for (int i = 0; i < file_size; i++) {
        if (file_contents[i] == ' ') {
            num_spaces++;
        } else if (file_contents[i] == '\n') {
            num_newlines++;
        } else if (file_contents[i] == '\t') {
            num_tabs++;
        }
    }
    
    printf("File analysis for %s\n", filename);
    printf("Total file size is %ld bytes\n", file_size);
    printf("Number of spaces: %d\n", num_spaces);
    printf("Number of newlines: %d\n", num_newlines);
    printf("Number of tabs: %d\n", num_tabs);
    
    memset(file_contents, 0, file_size); // zero out memory
    free(file_contents);
    
    return 0;
}