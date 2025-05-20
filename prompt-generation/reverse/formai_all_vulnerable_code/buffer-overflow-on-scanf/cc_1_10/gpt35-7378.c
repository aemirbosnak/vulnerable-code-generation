//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ENTRIES 100

int entry_number = 0;

struct Entry {
    int day;
    int month;
    int year;
    char entry[500];
};

struct Entry diary[MAX_ENTRIES];

void add_entry() {
    if (entry_number == MAX_ENTRIES) {
        printf("Sorry, your diary is full!\n");
        return;
    }

    struct Entry *e = &diary[entry_number++];

    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &e->day, &e->month, &e->year);

    printf("Enter your diary entry: \n");
    getchar();
    fgets(e->entry, 500, stdin);
}

void view_entries() {
    printf("\n");

    if (entry_number == 0) {
        printf("Your diary is empty!\n");
        return;
    }

    for (int i = 0; i < entry_number; i++) {
        printf("%d. [%d/%d/%d] %s\n", i + 1, diary[i].day, diary[i].month, diary[i].year, diary[i].entry);
    }
}

int main() {
    int option;
    do {
        printf("\nWelcome to your Digital Diary!\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}