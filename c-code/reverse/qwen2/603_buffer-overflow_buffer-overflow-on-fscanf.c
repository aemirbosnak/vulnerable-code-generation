#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 1024

void addEntry() {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry (type 'exit' to stop):\n");
    while (1) {
        fgets(entry, sizeof(entry), stdin);
        if (strcmp(entry, "exit\n") == 0) break;
        fputs(entry, file);
    }
    fclose(file);
}

void readEntries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No entries found.\n");
        return;
    }
    char entry[MAX_ENTRY_LENGTH];
    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\nDiary Application\n");
        printf("1. Add Entry\n");
        printf("2. Read Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                readEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
