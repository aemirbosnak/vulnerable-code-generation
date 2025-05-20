//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

// Function to read data from a file
void read_file(char *filename, char *buffer) {
    FILE *file;
    long file_size;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum file size allowed\n");
        exit(1);
    }

    fread(buffer, 1, file_size, file);
    fclose(file);
}

// Function to write data to a file
void write_file(char *filename, char *buffer, int size) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    fwrite(buffer, 1, size, file);

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_FILE_SIZE];
    int buffer_size, option, i;
    char backup_file[MAX_FILENAME_LENGTH];

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Backup file contents to a separate file before modifying
    snprintf(backup_file, sizeof(backup_file), "%s.bak", filename);
    read_file(filename, buffer);
    write_file(backup_file, buffer, strlen(buffer));

    // Get option from user
    printf("Enter option:\n1. Delete a byte\n2. Insert a byte\n");
    scanf("%d", &option);

    // Delete a byte from file
    if (option == 1) {
        printf("Enter byte index to delete: ");
        scanf("%d", &i);

        read_file(filename, buffer);
        buffer_size = strlen(buffer);

        if (i < 0 || i >= buffer_size) {
            printf("Error: Byte index out of range\n");
            exit(1);
        }

        // Shift bytes in buffer
        for (; i < buffer_size - 1; i++) {
            buffer[i] = buffer[i+1];
        }
        buffer[buffer_size-1] = 0;

        write_file(filename, buffer, strlen(buffer));
        printf("Byte deleted successfully\n");
    }

    // Insert a byte into file
    else if (option == 2) {
        printf("Enter byte index to insert: ");
        scanf("%d", &i);

        read_file(filename, buffer);
        buffer_size = strlen(buffer);

        if (i < 0 || i > buffer_size) {
            printf("Error: Byte index out of range\n");
            exit(1);
        }

        // Shift bytes in buffer
        for (int j = buffer_size; j > i; j--) {
            buffer[j] = buffer[j-1];
        }

        printf("Enter byte to insert (as a character): ");
        char byte;
        scanf(" %c", &byte); // Leave a space before %c to consume the newline character

        buffer[i] = byte;
        buffer[buffer_size + 1] = 0;

        write_file(filename, buffer, strlen(buffer));
        printf("Byte inserted successfully\n");
    }

    else {
        printf("Invalid option\n");
    }

    return 0;
}