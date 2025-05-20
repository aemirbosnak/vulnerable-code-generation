//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_RECORDS 100 // Maximum number of records
#define MAX_NAME_LENGTH 20 // Maximum length of name
#define MAX_CATEGORY_LENGTH 10 // Maximum length of category

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Record;

int menu_choice();
void add_record(Record records[], int *num_records);
void delete_record(Record records[], int *num_records);
void display_record(Record records[], int num_records);
int is_valid_category(char *category);
int is_valid_amount(char *amount);

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0, choice;

    while ((choice = menu_choice()) != 4) {
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                delete_record(records, &num_records);
                break;
            case 3:
                display_record(records, num_records);
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    printf("Thank you for using our Expense Tracker program!\n");

    return 0;
}

/**
 * Displays the menu and returns the user's choice
 */
int menu_choice() {
    int choice;

    printf("Expense Tracker\n");
    printf("===============\n");
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Display Records\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

/**
 * Adds a record to the expense tracker
 */
void add_record(Record records[], int *num_records) {
    char name[MAX_NAME_LENGTH], category[MAX_CATEGORY_LENGTH], amount_str[10];
    float amount;

    // Get name
    printf("Enter name: ");
    scanf("%s", name);

    // Get category
    while (1) {
        printf("Enter category (food, travel, shopping, etc.): ");
        scanf("%s", category);

        if (is_valid_category(category)) {
            break;
        }

        printf("Invalid category, please try again\n");
    }

    // Get amount
    while (1) {
        printf("Enter amount: ");
        scanf("%s", amount_str);

        if (is_valid_amount(amount_str)) {
            amount = atof(amount_str);
            break;
        }

        printf("Invalid amount, please try again\n");
    }

    // Add record to array
    strcpy(records[*num_records].name, name);
    strcpy(records[*num_records].category, category);
    records[*num_records].amount = amount;
    (*num_records)++;

    printf("Record added successfully!\n");
}

/**
 * Deletes a record from the expense tracker
 */
void delete_record(Record records[], int *num_records) {
    char name[MAX_NAME_LENGTH];
    int i, j, found = 0;

    // Get name
    printf("Enter name to delete: ");
    scanf("%s", name);

    // Find record with matching name and shift everything back in array
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;

            for (j = i; j < *num_records - 1; j++) {
                strcpy(records[j].name, records[j + 1].name);
                strcpy(records[j].category, records[j + 1].category);
                records[j].amount = records[j + 1].amount;
            }

            (*num_records)--;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Record not found\n");
    }
}

/**
 * Displays all records in the expense tracker
 */
void display_record(Record records[], int num_records) {
    int i;

    if (num_records == 0) {
        printf("No records found\n");
    } else {
        printf("%-20s %-10s %-10s\n", "Name", "Category", "Amount");
        printf("====================\n");

        for (i = 0; i < num_records; i++) {
            printf("%-20s %-10s %-10.2f\n", records[i].name, records[i].category, records[i].amount);
        }
    }
}

/**
 * Returns true if category is one of the valid ones
 */
int is_valid_category(char *category) {
    char valid_categories[][MAX_CATEGORY_LENGTH] = {
        "food",
        "travel",
        "shopping",
        "entertainment",
        "housing",
        "utilities",
        "education",
        "healthcare",
        "other"
    };

    int i;

    for (i = 0; i < sizeof(valid_categories) / sizeof(valid_categories[0]); i++) {
        if (strcmp(category, valid_categories[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

/**
 * Returns true if amount is a valid float
 */
int is_valid_amount(char *amount) {
    int i, decimal_found = 0;

    for (i = 0; i < strlen(amount); i++) {
        if (!isdigit(amount[i]) && amount[i] != '.') {
            return 0;
        }

        if (amount[i] == '.') {
            if (decimal_found) {
                return 0;
            } else {
                decimal_found = 1;
            }
        }
    }

    return 1;
}