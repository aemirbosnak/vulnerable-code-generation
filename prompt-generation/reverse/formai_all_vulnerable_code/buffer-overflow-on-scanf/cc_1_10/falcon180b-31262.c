//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[11];
    char description[81];
    char category[21];
    double amount;
} Entry;

void add_entry(Entry entries[], int num_entries) {
    char date_str[11];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date_str);
    strcpy(entries[num_entries].date, date_str);

    printf("Enter description: ");
    scanf("%s", entries[num_entries].description);

    printf("Enter category: ");
    scanf("%s", entries[num_entries].category);

    printf("Enter amount: ");
    scanf("%lf", &entries[num_entries].amount);

    num_entries++;
}

void display_entries(Entry entries[], int num_entries) {
    printf("\nDate\tDescription\tCategory\tAmount\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%.2lf\n", entries[i].date, entries[i].description, entries[i].category, entries[i].amount);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("\n1. Add entry\n2. Display entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            display_entries(entries, num_entries);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}