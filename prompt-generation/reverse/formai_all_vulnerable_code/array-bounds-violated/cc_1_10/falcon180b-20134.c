//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    int expenses[MAX_EXPENSES];
} Category;

void initCategory(Category* cat) {
    for (int i = 0; i < MAX_EXPENSES; i++) {
        cat->expenses[i] = 0;
    }
}

void printCategory(Category cat) {
    printf("Category: %s\n", cat.name);
    for (int i = 0; i < MAX_EXPENSES; i++) {
        printf("Expense %d: $%d\n", i+1, cat.expenses[i]);
    }
}

int main() {
    Category categories[MAX_CATEGORIES];
    int numCategories;

    printf("Enter number of categories: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter category name: ");
        scanf("%s", categories[i].name);
        initCategory(&categories[i]);
    }

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses by category\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter category name: ");
                scanf("%s", categories[0].name);
                printf("Enter expense amount: $");
                scanf("%d", &categories[0].expenses[0]);
                break;
            case 2:
                printf("Choose a category:\n");
                for (int i = 0; i < numCategories; i++) {
                    printf("%d. %s\n", i+1, categories[i].name);
                }
                scanf("%d", &choice);
                printCategory(categories[choice-1]);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}