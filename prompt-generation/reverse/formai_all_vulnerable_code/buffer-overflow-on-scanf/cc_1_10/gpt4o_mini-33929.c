//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define FILENAME "gratitude.txt"

void write_gratitude(const char *entry);
void read_gratitude();
void display_welcome_message();

int main() {
    int choice;
    char entry[MAX_LENGTH];

    display_welcome_message();

    while (1) {
        printf("\nWelcome to the Gratitude Journal!\n");
        printf("1. Write a new gratitude entry\n");
        printf("2. Read all gratitude entries\n");
        printf("3. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Please enter your gratitude entry: ");
                fgets(entry, MAX_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = 0; // Remove newline character
                write_gratitude(entry);
                printf("Thank you for your beautiful entry!\n");
                break;
            case 2:
                printf("Here are your entries:\n");
                read_gratitude();
                break;
            case 3:
                printf("Thank you for using the Gratitude Journal! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void write_gratitude(const char *entry) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }
    fprintf(file, "%s\n", entry);
    fclose(file);
}

void read_gratitude() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }
    
    char buffer[MAX_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("- %s", buffer);
    }
    
    fclose(file);
}

void display_welcome_message() {
    printf("=================================\n");
    printf("   Welcome to Your Gratitude     \n");
    printf("           Journal                \n");
    printf("=================================\n");
    printf("Here, you can jot down what you're grateful for and cherish those moments.\n");
}