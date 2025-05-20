//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESCRIPTION_SIZE 256

typedef struct {
    char description[DESCRIPTION_SIZE];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Entry;

Entry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Maximum entry limit reached!\n");
        return;
    }
    Entry new_entry;
    printf("Enter description: ");
    scanf(" %[^\n]", new_entry.description); // Read string with spaces
    printf("Enter amount: ");
    scanf("%f", &new_entry.amount);
    printf("Enter type (i for income, e for expense): ");
    scanf(" %c", &new_entry.type); 
    if (new_entry.type != 'i' && new_entry.type != 'e') {
        printf("Invalid entry type! Use 'i' for income or 'e' for expense.\n");
        return;
    }
    entries[entry_count++] = new_entry;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }
    printf("\n--- List of Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d. Description: %s, Amount: %.2f, Type: %c\n", i + 1, entries[i].description, entries[i].amount, entries[i].type);
    }
    printf("-----------------------\n");
}

float calculate_total(char type) {
    float total = 0.0;
    for (int i = 0; i < entry_count; i++) {
        if (entries[i].type == type) {
            total += entries[i].amount;
        }
    }
    return total;
}

void view_summary() {
    float total_income = calculate_total('i');
    float total_expense = calculate_total('e');
    float balance = total_income - total_expense;

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Current Balance: %.2f\n", balance);
    printf("-------------------------\n");
}

void save_entries_to_file() {
    FILE *file = fopen("finance_entries.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s %.2f %c\n", entries[i].description, entries[i].amount, entries[i].type);
    }
    fclose(file);
    printf("Entries saved to finance_entries.txt\n");
}

void load_entries_from_file() {
    FILE *file = fopen("finance_entries.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading! Perhaps no file exists.\n");
        return;
    }
    while (fscanf(file, " %[^\n] %f %c\n", entries[entry_count].description, &entries[entry_count].amount, &entries[entry_count].type) != EOF) {
        if (entry_count >= MAX_ENTRIES) {
            printf("Reached maximum entry limit while loading!\n");
            break;
        }
        entry_count++;
    }
    fclose(file);
    printf("Entries loaded successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. View Summary\n");
        printf("4. Save Entries to File\n");
        printf("5. Load Entries from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                view_summary();
                break;
            case 4:
                save_entries_to_file();
                break;
            case 5:
                load_entries_from_file();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}