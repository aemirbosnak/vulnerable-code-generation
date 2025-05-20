//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 256

// Function to read the contents of a file
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file for reading");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = malloc(length + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to write content to a file
void write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fputs(content, file);
    fclose(file);
}

// Function to synchronize two files
void synchronize_files(const char* source, const char* destination) {
    char* source_content = read_file(source);
    if (!source_content) {
        fprintf(stderr, "Failed to read source file: %s\n", source);
        return;
    }

    write_file(destination, source_content);
    
    printf("Darling, I’ve lovingly moved your whispers from %s to %s.\n", source, destination);
    
    free(source_content);
}

// Function to display menu
void display_menu() {
    printf("Welcome to the Dance of File Synchronization!\n");
    printf("1. Synchronize Files\n");
    printf("2. Exit\n");
    printf("Choose your romantic rendezvous (1-2): ");
}

// Main function
int main() {
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Until we meet again, dear user!\n");
            break;
        } else if (choice == 1) {
            char source[MAX_PATH], destination[MAX_PATH];
            printf("Please share the path of the source file: ");
            scanf("%s", source);
            printf("And now, the path of the destination file: ");
            scanf("%s", destination);

            synchronize_files(source, destination);
        } else {
            printf("Your choice was like a summer shower, unexpected and delightful!\n");
        }
    }

    return 0;
}