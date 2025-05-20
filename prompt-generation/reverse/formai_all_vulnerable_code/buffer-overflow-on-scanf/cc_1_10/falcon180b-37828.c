//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char category[50];
    char description[100];
    float amount;
    int date;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }
    Entry new_entry;
    printf("Category: ");
    scanf("%s", new_entry.category);
    printf("Description: ");
    scanf("%s", new_entry.description);
    printf("Amount: ");
    scanf("%f", &new_entry.amount);
    printf("Date (YYYY-MM-DD): ");
    scanf("%d", &new_entry.date);
    entries[num_entries] = new_entry;
    num_entries++;
    printf("Entry added successfully.\n");
}

void view_entries() {
    printf("Category\tDescription\tAmount\tDate\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%.2f\t%d\n", entries[i].category, entries[i].description, entries[i].amount, entries[i].date);
    }
}

void delete_entry() {
    printf("Category: ");
    char category[50];
    scanf("%s", category);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(category, entries[i].category) == 0) {
            found = 1;
            for (int j = i; j < num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            num_entries--;
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    } else {
        printf("Entry deleted successfully.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
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
            delete_entry();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}