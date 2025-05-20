//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_EX Expenses_Count(10)
typedef struct Expense {
    char category[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void Expenses_Init() {
    head = NULL;
}

Expenses_Count(int size) {
    Expense *temp = malloc(sizeof(Expense) * size);
    for (int i = 0; i < size; i++) {
        temp[i].next = NULL;
    }
    return (Expense *)temp;
}

void Add_Expense(char *category, float amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    strcpy(newExpense->category, category);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void Display_Expenses() {
    Expense *temp = head;
    printf("\nExpense Tracker\n");
    printf("------------------------\n");
    printf("| Category          | Amount |\n");
    printf("------------------------\n");
    while (temp != NULL) {
        printf("| %-49s | %10.2f |\n", temp->category, temp->amount);
        temp = temp->next;
    }
}

int main() {
    Expenses_Init();
    char category[50];
    float amount;
    int choice = 0;

    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Delete Last Expense\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Category: ");
                scanf("%s", category);
                printf("Enter Amount: ");
                scanf("%f", &amount);
                Add_Expense(category, amount);
                break;
            case 2:
                Display_Expenses();
                break;
            case 3:
                // Calculate Total Expenses
                break;
            case 4:
                // Delete Last Expense
                if (head != NULL) {
                    Expense *temp = head;
                    while (temp->next != NULL) {
                        head = temp;
                        temp = temp->next;
                    }
                    free(temp);
                    head = NULL;
                }
                break;
            case 5:
                // Exit
                free(head);
                return 0;
            default:
                printf("Invalid Option!\n");
                break;
        }
    }

    return 0;
}