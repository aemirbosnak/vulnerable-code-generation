//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
    char* message;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    DiaryEntry* entry = &diary[numEntries++];

    printf("Enter the date of the entry (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &entry->day, &entry->month, &entry->year);

    printf("Enter your message: ");
    fflush(stdin);

    entry->message = (char*)malloc(256 * sizeof(char));
    fgets(entry->message, 256, stdin);
}

void viewEntry() {
    if (numEntries == 0) {
        printf("No entries in diary!\n");
        return;
    }

    printf("Enter the date of the entry you want to view (dd/mm/yyyy): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

    for (int i = 0; i < numEntries; i++) {
        DiaryEntry* entry = &diary[i];

        if (entry->day == day && entry->month == month && entry->year == year) {
            printf("Date: %02d/%02d/%04d\n", entry->day, entry->month, entry->year);
            printf("Message: %s\n", entry->message);
            return;
        }
    }

    printf("No entry found for %02d/%02d/%04d", day, month, year);
}

void printMenu() {
    printf("\nDigital Diary\n");
    printf("==============\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char c;

    do {
        printMenu();

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;

        case 2:
            viewEntry();
            break;

        case 3:
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }

        printf("Press enter to continue...");
        fflush(stdin);
        c = getchar();

    } while (choice != 3);

    printf("Thank you for using Digital Diary!\n");
    return 0;
}