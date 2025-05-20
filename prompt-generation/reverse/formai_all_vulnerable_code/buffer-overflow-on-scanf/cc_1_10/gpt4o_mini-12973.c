//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void writeDiaryEntry(const char* entry) {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }
    fprintf(file, "%s\n", entry);
    fclose(file);
}

void readDiaryEntries() {
    char buffer[MAX_LENGTH];
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }
    printf("\n=== Your Diary Entries ===\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteDiaryEntries() {
    if (remove("diary.txt") == 0) {
        printf("Diary entries deleted successfully.\n");
    } else {
        perror("Error deleting diary entries.");
    }
}

int main() {
    int choice;
    char entry[MAX_LENGTH];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter your diary entry: ");
                fgets(entry, sizeof(entry), stdin);
                entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
                writeDiaryEntry(entry);
                printf("Diary entry added successfully.\n");
                break;
            case 2:
                readDiaryEntries();
                break;
            case 3:
                deleteDiaryEntries();
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}