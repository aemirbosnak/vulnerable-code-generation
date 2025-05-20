//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 256
#define DIARY_FILE "happy_diary.txt"

void write_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        perror("Unable to open diary file for writing");
        return;
    }

    char entry[MAX_ENTRY_LENGTH];
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("Write your happy thoughts! (Max %d characters) \n", MAX_ENTRY_LENGTH - 1);
    fgets(entry, sizeof(entry), stdin);

    // Remove newline character from the input if present
    size_t len = strlen(entry);
    if (len > 0 && entry[len - 1] == '\n') {
        entry[len - 1] = '\0';
    }

    fprintf(file, "%s - %s", entry, asctime(tm_info));
    fclose(file);
    printf("Your happy entry was added to the diary! 🎉\n");
}

void read_entries() {
    char buffer[MAX_ENTRY_LENGTH + 30];
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("No diary entries found! Why not add your first happy thought? 😊\n");
        return;
    }

    printf("Here are your happy diary entries: \n\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void display_menu() {
    printf("\n--- Happy Diary Menu ---\n");
    printf("1. Write a new entry\n");
    printf("2. Read diary entries\n");
    printf("3. Exit\n");
    printf("------------------------\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                write_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                printf("Thank you for using Happy Diary! May your days be filled with joy! 🌈\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}