//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char date[10];
    char category[20];
    float amount;
};

void add_entry(struct entry *entries, int count, char date[], char category[], float amount) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum entries (%d) reached\n", MAX_ENTRIES);
        return;
    }

    strcpy(entries[count].date, date);
    strcpy(entries[count].category, category);
    entries[count].amount = amount;

    count++;
}

void display_entries(struct entry entries[], int count) {
    printf("Date\tCategory\tAmount\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\n", entries[i].date, entries[i].category, entries[i].amount);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char date[10];
                char category[20];
                float amount;

                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);

                printf("Enter category: ");
                scanf("%s", category);

                printf("Enter amount: ");
                scanf("%f", &amount);

                add_entry(entries, count, date, category, amount);
                break;
            }

            case 2: {
                display_entries(entries, count);
                break;
            }

            case 3: {
                exit(0);
            }

            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}