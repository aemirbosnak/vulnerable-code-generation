//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    int date;
} expense;

void add_expense(expense *list, int *size) {
    char input[MAX_NAME_LENGTH];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(list[*size].name, input);
    printf("Enter expense amount: ");
    scanf("%lf", &list[*size].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &list[*size].date);
    (*size)++;
}

void display_expenses(expense *list, int size) {
    printf("Expenses:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %.2lf - %d\n", list[i].name, list[i].amount, list[i].date);
    }
}

void sort_by_date(expense *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i].date > list[j].date) {
                expense temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int main() {
    expense list[MAX_ITEMS];
    int size = 0;
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Sort by date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_expense(list, &size);
                break;
            case '2':
                display_expenses(list, size);
                break;
            case '3':
                sort_by_date(list, size);
                printf("Sorted by date:\n");
                display_expenses(list, size);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}