//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Expense Struct
typedef struct {
    char category[50];
    float amount;
    struct Expense* next;
} Expense;

// Node Struct for Linked List
typedef struct Node {
    Expense expense;
    struct Node* next;
} Node;

// Global Variables
Expense currentExpense;
Node* head = NULL;
Node* currentNode = NULL;

void printMenu() {
    printf("\n---- Expense Tracker ----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Search Expense\n");
    printf("5. Total Expenses\n");
    printf("6. Exit\n");
}

void addExpense() {
    printf("Enter Expense Category: ");
    scanf("%s", currentExpense.category);
    printf("Enter Expense Amount: ");
    scanf("%f", &currentExpense.amount);

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = head;
    newNode->expense = currentExpense;

    if (head == NULL) {
        head = newNode;
    } else {
        currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    printf("Expense Added Successfully!\n");
}

void viewExpenses() {
    if (head == NULL) {
        printf("No Expenses Found!\n");
        return;
    }

    currentNode = head;
    while (currentNode != NULL) {
        printf("\nExpense Category: %s", currentNode->expense.category);
        printf("\nExpense Amount: %.2f", currentNode->expense.amount);
        currentNode = currentNode->next;
    }
}

void deleteExpense() {
    if (head == NULL) {
        printf("No Expenses Found!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Expense Deleted Successfully!\n");
        return;
    }

    currentNode = head;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    free(currentNode->next);
    currentNode->next = NULL;
    printf("Expense Deleted Successfully!\n");
}

void searchExpense() {
    char searchCategory[50];
    bool found = false;

    printf("Enter Expense Category to Search: ");
    scanf("%s", searchCategory);

    currentNode = head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->expense.category, searchCategory) == 0) {
            printf("\nExpense Category: %s", currentNode->expense.category);
            printf("\nExpense Amount: %.2f", currentNode->expense.amount);
            found = true;
            break;
        }
        currentNode = currentNode->next;
    }

    if (!found) {
        printf("Expense Not Found!\n");
    }
}

void totalExpenses() {
    float total = 0.0;
    currentNode = head;

    while (currentNode != NULL) {
        total += currentNode->expense.amount;
        currentNode = currentNode->next;
    }

    printf("Total Expenses: %.2f", total);
}

int main() {
    int choice;

    while (true) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                searchExpense();
                break;
            case 5:
                totalExpenses();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Option! Please Try Again!\n");
        }
    }

    return 0;
}