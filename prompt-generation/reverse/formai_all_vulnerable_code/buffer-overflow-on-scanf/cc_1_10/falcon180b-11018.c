//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[20];
    int count;
    float total;
} category;

category categories[MAX_CATEGORIES];

void add_category(char name[20]) {
    int i;
    for (i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, "") == 0) {
            strcpy(categories[i].name, name);
            categories[i].count = 0;
            categories[i].total = 0;
            return;
        }
    }
}

void add_expense(char category_name[20], char description[50], float amount) {
    int i;
    for (i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, category_name) == 0) {
            categories[i].count++;
            categories[i].total += amount;
            return;
        }
    }
}

void print_categories() {
    int i;
    for (i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, "")!= 0) {
            printf("Category: %s\n", categories[i].name);
            printf("Count: %d\n", categories[i].count);
            printf("Total: $%.2f\n", categories[i].total);
            printf("\n");
        }
    }
}

int main() {
    char category_name[20];
    char description[50];
    float amount;
    int choice;

    do {
        printf("Enter 1 to add a category\n");
        printf("Enter 2 to add an expense\n");
        printf("Enter 3 to print categories\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter category name: ");
            scanf("%s", category_name);
            add_category(category_name);
            break;
        case 2:
            printf("Enter category name: ");
            scanf("%s", category_name);
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter amount: ");
            scanf("%f", &amount);
            add_expense(category_name, description, amount);
            break;
        case 3:
            print_categories();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}