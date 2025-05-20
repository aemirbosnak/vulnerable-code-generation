//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char date[20];
    char item[50];
    float price;
};

void addExpense(struct expense array[], int *count);
void viewExpenses(struct expense array[], int count);
void deleteExpense(struct expense array[], int *count);

int main() {
    int count = 0, choice;
    struct expense expenses[100];
    printf("***Expense Tracker***\n");

    do {
        printf("\nMenu\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, &count);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void addExpense(struct expense array[], int *count) {
    char date[20], item[50];
    float price;
    fflush(stdin);
    printf("\nEnter the date (dd/mm/yyyy): ");
    scanf("%s", date);
    fflush(stdin);
    printf("Enter the item name: ");
    scanf("%[^\n]", item);
    fflush(stdin);
    printf("Enter the price: ");
    scanf("%f", &price);

    struct expense newExpense;
    strcpy(newExpense.date, date);
    strcpy(newExpense.item, item);
    newExpense.price = price;

    array[*count] = newExpense;
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(struct expense array[], int count) {
    if (count == 0) {
        printf("There are no expenses to display.\n");
        return;
    }

    printf("\nExpenses\n");
    printf("Date\t\tItem\t\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\n", array[i].date, array[i].item, array[i].price);
    }
}

void deleteExpense(struct expense array[], int *count) {
    if (*count == 0) {
        printf("There are no expenses to delete.\n");
        return;
    }

    int index, found = 0;
    char date[20];
    printf("\nEnter the date of the expense to delete (dd/mm/yyyy): ");
    scanf("%s", date);

    for (int i = 0; i < *count; i++) {
        if (strcmp(array[i].date, date) == 0) {
            index = i;
            found = 1;
            break;
        }
    }

    if (found) {
        for (int i = index; i < *count - 1; i++) {
            array[i] = array[i+1];
        }
        (*count)--;
        printf("Expense deleted successfully!\n");
    } else {
        printf("Expense not found.\n");
    }
}