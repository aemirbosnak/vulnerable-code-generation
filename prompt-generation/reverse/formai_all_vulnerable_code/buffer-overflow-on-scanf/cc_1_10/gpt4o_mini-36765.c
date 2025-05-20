//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to create file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "This is a sample file created for file handling demonstration.\n");
    fprintf(file, "Feel free to modify this text.\n");
    fclose(file);
}

void append_to_file(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Unable to open file for appending");
        exit(EXIT_FAILURE);
    }
    
    char input[MAX_LINE_LENGTH];
    printf("Enter text to append to the file (or type 'exit' to stop):\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        fputs(input, file);
    }
    
    fclose(file);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_LINE_LENGTH];
    printf("\nContents of %s:\n", filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

void delete_file(const char *filename) {
    if (remove(filename) != 0) {
        perror("Unable to delete file");
    } else {
        printf("File %s deleted successfully.\n", filename);
    }
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    int choice;

    printf("Enter the name of the file to work with: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the newline character

    while (1) {
        printf("\nFile Handling Menu:\n");
        printf("1. Create File\n");
        printf("2. Append to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                create_file(filename);
                printf("File created successfully: %s\n", filename);
                break;
            case 2:
                append_to_file(filename);
                break;
            case 3:
                read_file(filename);
                break;
            case 4:
                delete_file(filename);
                break;
            case 5:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}