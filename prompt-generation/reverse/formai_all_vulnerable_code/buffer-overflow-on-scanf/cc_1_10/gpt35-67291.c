//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

struct diary_entry {
    char date[20];
    char content[1000];
};

struct diary_entry diary[MAX_ENTRIES];

int entry_count = 0;

void add_entry() {
    printf("Enter today's date (mm/dd/yyyy): ");
    scanf("%s", diary[entry_count].date);
    printf("Enter today's entry content: ");
    scanf(" %[^\n]s", diary[entry_count].content);
    entry_count++;
    printf("Entry added to diary!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Date\t\tContent\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].content);
    }
}

void export_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    FILE *fptr;
    fptr = fopen("diary.txt", "w");
    fprintf(fptr, "Date\t\tContent\n");
    for (int i = 0; i < entry_count; i++) {
        fprintf(fptr, "%s\t%s\n", diary[i].date, diary[i].content);
    }
    fclose(fptr);
    printf("Entries exported to diary.txt!\n");
}

void menu() {
    int choice;
    while (1) {
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Export entries to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                export_entries();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}