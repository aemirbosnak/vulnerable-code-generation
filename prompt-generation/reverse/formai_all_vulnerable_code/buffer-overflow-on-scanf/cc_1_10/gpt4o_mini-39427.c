//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define LOVE_NOTE_LENGTH 256

typedef struct {
    char name[NAME_LENGTH];
    char loveNote[LOVE_NOTE_LENGTH];
} Entry;

void printLoveNotes(Entry entries[], int count) {
    printf("\n--- Love Notes ---\n");
    for (int i = 0; i < count; i++) {
        printf("From: %s\n", entries[i].name);
        printf("Note: %s\n", entries[i].loveNote);
        printf("----------------------\n");
    }
}

void addLoveNote(Entry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Sorry! The love notes jar is full.\n");
        return;
    }

    printf("Enter the name of your beloved: ");
    scanf(" %[^\n]%*c", entries[*count].name);

    printf("Write your love note: ");
    scanf(" %[^\n]%*c", entries[*count].loveNote);

    (*count)++;
    printf("Your love note has been added lovingly!\n");
}

void searchLoveNotes(Entry entries[], int count) {
    char target[NAME_LENGTH];
    printf("Whose love note do you wish to find? ");
    scanf(" %[^\n]%*c", target);

    int found = 0;
    printf("\n--- Searching for %s's Love Notes ---\n", target);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, target) == 0) {
            printf("Note: %s\n", entries[i].loveNote);
            found = 1;
        }
    }
    if (!found) {
        printf("No love notes found for %s.\n", target);
    }
}

void deleteLoveNote(Entry entries[], int *count) {
    char target[NAME_LENGTH];
    printf("Whose love note do you wish to delete? ");
    scanf(" %[^\n]%*c", target);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, target) == 0) {
            found = 1;
            printf("Love note from %s will be erased from memory.\n", entries[i].name);
            // Shift remaining entries to fill the gap
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            break;
        }
    }
    if (!found) {
        printf("Love note not found for %s.\n", target);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Welcoming to the Love Notes Database ---\n");
        printf("1. Add a Love Note\n");
        printf("2. View all Love Notes\n");
        printf("3. Search for a Love Note\n");
        printf("4. Delete a Love Note\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLoveNote(entries, &count);
                break;
            case 2:
                printLoveNotes(entries, count);
                break;
            case 3:
                searchLoveNotes(entries, count);
                break;
            case 4:
                deleteLoveNote(entries, &count);
                break;
            case 5:
                printf("Farewell, keep your love notes close to the heart!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}