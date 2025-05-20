//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

struct entry {
    int month;
    int day;
    int year;
    char message[70];
};

void addEntry(struct entry diary[], int *numEntries);
void viewEntries(struct entry diary[], int numEntries);

int main() {
    struct entry diary[MAX_ENTRIES];
    int numEntries = 0;
    int choice;

    printf("Welcome to your digital diary.\n");

    do {
        printf("Menu:\n");
        printf("1. Add an Entry\n");
        printf("2. View Entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                viewEntries(diary, numEntries);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void addEntry(struct entry diary[], int *numEntries) {
    if (*numEntries < MAX_ENTRIES) {
        // get input for new entry
        printf("Enter entry date (MM/DD/YYYY): ");
        scanf("%d/%d/%d", &diary[*numEntries].month, &diary[*numEntries].day, &diary[*numEntries].year);
        printf("Enter message (max 70 characters): ");
        fflush(stdin);
        fgets(diary[*numEntries].message, 70, stdin);

        // increment number of entries
        *numEntries += 1;
    } else {
        printf("Digital diary is full. Cannot add new entry.\n");
    }
}

void viewEntries(struct entry diary[], int numEntries) {
    if (numEntries == 0) {
        printf("Digital diary is empty.\n");
    } else {
        printf("Date            Message\n");
        printf("===============================\n");
        for (int i = 0; i < numEntries; i++) {
            printf("%02d/%02d/%04d     %s\n", diary[i].month, diary[i].day, diary[i].year, diary[i].message);
        }
    }
}