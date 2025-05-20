//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

unsigned int calculate_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return 0;
    }

    unsigned int checksum = 0;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    fclose(file);
    return checksum;
}

void write_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not create file");
        return;
    }

    char input[BUFFER_SIZE];
    printf("Enter text to write to %s (type 'exit' to finish):\n", filename);

    while (1) {
        fgets(input, BUFFER_SIZE, stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        fputs(input, file);
    }

    fclose(file);
    printf("Content written to %s\n", filename);
}

void display_menu() {
    printf("Simple File Manager\n");
    printf("1. Write to a new file\n");
    printf("2. Calculate checksum of a file\n");
    printf("3. Exit\n");
}

void handle_choice(int choice) {
    char filename[MAX_FILENAME];
    
    switch (choice) {
        case 1:
            printf("Enter the filename to create: ");
            scanf("%s", filename);
            getchar(); // to consume the newline character
            write_to_file(filename);
            break;
        case 2:
            printf("Enter the filename to calculate checksum: ");
            scanf("%s", filename);
            getchar(); // to consume the newline character
            unsigned int checksum = calculate_checksum(filename);
            if (checksum) {
                printf("Checksum of %s: %u\n", filename, checksum);
            }
            break;
        case 3:
            printf("Exiting the program...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character
        handle_choice(choice);
    }

    return 0;
}