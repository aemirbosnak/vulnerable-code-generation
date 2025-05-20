//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "diary_entries.txt"

// Function to get the current timestamp as a string
void get_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

// Function to write an entry to the diary
void write_entry() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        fprintf(stderr, "Error opening diary file!\n");
        exit(EXIT_FAILURE);
    }
    
    char entry[MAX_LENGTH];
    printf("Enter your diary entry (max %d characters, type 'exit' to stop):\n", MAX_LENGTH - 1);
    
    while (1) {
        fgets(entry, sizeof(entry), stdin);
        entry[strcspn(entry, "\n")] = 0; // Remove newline
        
        if (strcmp(entry, "exit") == 0) {
            break;
        }
        
        char timestamp[20];
        get_timestamp(timestamp, sizeof(timestamp));
        
        fprintf(file, "[%s] %s\n", timestamp, entry);
    }
    
    fclose(file);
    printf("Diary entries saved successfully!\n");
}

// Function to read all entries from the diary
void read_entries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        fprintf(stderr, "Error opening diary file!\n");
        return;
    }
    
    char buffer[MAX_LENGTH + 50]; // Buffer to hold file lines
    
    printf("Your diary entries:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

// Function to display the menu
void display_menu() {
    printf("=== Digital Diary ===\n");
    printf("1. Write a new entry\n");
    printf("2. Read existing entries\n");
    printf("3. Exit\n");
    printf("=======================\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int option = 0;
    
    while (1) {
        display_menu();
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear invalid input from stdin
            while (getchar() != '\n');
            continue;
        }
        
        while (getchar() != '\n'); // Clear the input buffer

        switch (option) {
            case 1:
                write_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                printf("Exiting the diary. Have a great day!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}