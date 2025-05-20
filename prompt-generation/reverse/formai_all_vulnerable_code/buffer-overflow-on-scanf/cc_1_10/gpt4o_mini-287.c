//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SIZE 256

void add_entry(const char *filename);
void view_entries(const char *filename);
void delete_diary(const char *filename);
void show_menu();

int main() {
    const char *filename = "diary.txt";
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after entering choice

        switch (choice) {
            case 1:
                add_entry(filename);
                break;
            case 2:
                view_entries(filename);
                break;
            case 3:
                delete_diary(filename);
                break;
            case 4:
                printf("Thank you for using the Diary Application. Have a wonderful day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void show_menu() {
    printf("\n--- Welcome to Your Happy Diary! ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary\n");
    printf("4. Exit\n");
}

void add_entry(const char *filename) {
    FILE *file = fopen(filename, "a"); // Open for appending
    if (file == NULL) {
        perror("Could not open diary file");
        return;
    }
  
    char entry[MAX_SIZE];
    printf("Write your diary entry (max %d characters): ", MAX_SIZE - 1);
    fgets(entry, MAX_SIZE, stdin);
  
    // Remove newline character if present
    size_t len = strlen(entry);
    if (len > 0 && entry[len - 1] == '\n') {
        entry[len - 1] = '\0';
    }
    
    fprintf(file, "%s\n", entry);
    printf("Your entry has been added! 😊\n");
  
    fclose(file);
}

void view_entries(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No diary entries found. 📖\n");
        return;
    }
  
    char entry[MAX_SIZE];
    printf("\n--- Your Diary Entries ---\n");
    while (fgets(entry, MAX_SIZE, file) != NULL) {
        printf("- %s", entry);
    }
  
    fclose(file);
}

void delete_diary(const char *filename) {
    if (remove(filename) == 0) {
        printf("Your diary has been deleted! 🌟\n");
    } else {
        printf("Error deleting diary. Maybe it doesn't exist? 😢\n");
    }
}