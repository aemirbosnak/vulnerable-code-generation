//FormAI DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct Entry {
    char date[11];
    char time[6];
    char title[50];
    char content[1000]; 
} diary[100];

int num_entries = 0;

void add_entry() {
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", diary[num_entries].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", diary[num_entries].time);
    printf("Enter title: ");
    scanf(" %[^\n]", diary[num_entries].title);
    printf("Enter diary entry:\n");
    scanf(" %[^\n]", diary[num_entries].content);
    printf("Entry added successfully!\n");
    num_entries++;
}

void view_entries() {
    printf("DIARY ENTRIES:\n");
    if (num_entries == 0) {
        printf("No entries found.\n");
    } else {
        for (int i = 0; i < num_entries; i++) {
            printf("Entry %d: %s %s\n", i+1, diary[i].date, diary[i].time);
            printf("Title: %s\n", diary[i].title);
            printf("Content: %s\n\n", diary[i].content);
        }
    }
}

int main() {
    int choice;
    do {
        printf("DIARY MENU:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}