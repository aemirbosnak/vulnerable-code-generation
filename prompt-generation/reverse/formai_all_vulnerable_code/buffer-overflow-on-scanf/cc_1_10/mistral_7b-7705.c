//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 20

typedef struct Transaction {
    char description[50];
    float amount;
    int category_index;
} Transaction;

typedef struct Category {
    char name[20];
    float total_spent;
} Category;

Category categories[MAX_CATEGORIES] = {{".", 0.0}};
Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0, num_categories = 1;

void add_transaction(char *desc, float amt, int category) {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Cannot add transaction.\n");
        return;
    }

    strcpy(transactions[num_transactions].description, desc);
    transactions[num_transactions].amount = amt;
    transactions[num_transactions].category_index = category;

    num_transactions++;
}

int get_category_index(char *name) {
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            return i;
        }
    }

    for (int i = 0; i < num_categories && strcmp(categories[i].name, ".") == 0; i++) {
        strcpy(categories[i].name, name);
        return i;
    }

    num_categories++;
    strcpy(categories[num_categories - 1].name, name);

    return num_categories - 1;
}

void print_report() {
    printf("\n--------- Personal Finance Report -----------\n\n");

    printf("%-20s %-15s %-10s\n", "Category", "Total Spent", "Avg Spending");
    printf("-----------------------------------------------");
    printf("-----------------------------------------------");

    for (int i = 0; i < num_categories; i++) {
        float avg_spending = num_transactions > 0 ? categories[i].total_spent / num_transactions : 0;
        printf("\n%-20s %-15.2f %-10.2f", categories[i].name, categories[i].total_spent, avg_spending);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add transaction\n2. Print report\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char desc[50], cat[20];
                float amt;

                printf("Enter transaction description: ");
                scanf("%s", desc);
                printf("Enter transaction amount: ");
                scanf("%f", &amt);
                printf("Enter category name (or '.' for new category): ");
                scanf("%s", cat);

                add_transaction(desc, amt, get_category_index(cat));
                break;
            }
            case 2: {
                print_report();
                break;
            }
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}