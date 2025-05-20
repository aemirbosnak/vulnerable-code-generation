//FormAI DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct expense {
    double amount;
    char description[50];
};

int num_entries = 0;
struct expense entries[MAX_ENTRIES];

void add_entry(double amount, char *description) {
    if(num_entries >= MAX_ENTRIES) {
        printf("Error: Entry limit exceeded\n");
        return;
    }

    entries[num_entries].amount = amount;
    strcpy(entries[num_entries].description, description);
    num_entries++;
    printf("Entry added successfully\n");
}

void print_report() {
    printf("Expense Report:\n");
    printf("================\n");
    double total = 0;

    for(int i = 0; i < num_entries; i++) {
        printf("%d. %s - $%.2f\n", i+1, entries[i].description, entries[i].amount);
        total += entries[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}

int main() {
    int choice = 0;

    while(choice != 3) {
        printf("\nSelect an option:\n");
        printf("1. Add expense\n");
        printf("2. Print report\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    double amount;
                    char description[50];
                    printf("\nEnter expense amount: $");
                    scanf("%lf", &amount);
                    printf("Enter expense description: ");
                    scanf("%s", description);
                    add_entry(amount, description);
                    break;
                }
            case 2:
                {
                    print_report();
                    break;
                }
            case 3:
                {
                    printf("\nExiting...\n");
                    break;
                }
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}