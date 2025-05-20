//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_DESC_SIZE 50

typedef struct {
    char desc[MAX_DESC_SIZE];
    double amount;
} Entry;

Entry entries[MAX_ENTRIES];
int count = 0;

void add_entry(const char *description, double amount) {
    if (count < MAX_ENTRIES) {
        strncpy(entries[count].desc, description, MAX_DESC_SIZE - 1);
        entries[count].desc[MAX_DESC_SIZE - 1] = '\0'; // Ensure null termination
        entries[count].amount = amount;
        count++;
    } else {
        printf("Maximum entries reached!\n");
    }
}

void display_entries() {
    printf("\nYour Financial Entries:\n");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, entries[i].desc, entries[i].amount);
    }
    printf("-------------------------\n");
}

double total_expenses() {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += entries[i].amount;
    }
    return total;
}

void sort_entries() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (entries[i].amount > entries[j].amount) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

void menu() {
    int choice = 0;
    char desc[MAX_DESC_SIZE];
    double amt;

    while (1) {
        printf("\nPersonal Finance Planner Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Entries\n");
        printf("3. Total Expenses\n");
        printf("4. Sort Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number!\n");
            while(getchar() != '\n'); // clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf(" %[^\n]%*c", desc); // Get full line input
                printf("Enter amount: $");
                scanf("%lf", &amt);
                add_entry(desc, amt);
                break;
                
            case 2:
                display_entries();
                break;
                
            case 3:
                printf("Total Expenses: $%.2f\n", total_expenses());
                break;

            case 4:
                sort_entries();
                printf("Entries sorted by amount.\n");
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}