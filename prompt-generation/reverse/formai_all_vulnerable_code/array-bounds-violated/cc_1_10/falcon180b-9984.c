//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float cost;
    int quantity;
} item;

int main() {
    int choice, i, j;
    float total_cost = 0.0, cost;
    char filename[50];
    FILE *fp;
    item items[MAX_ITEMS];

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter a filename to save your expenses: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not create file.\n");
        exit(1);
    }

    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (i >= MAX_ITEMS) {
                printf("Error: maximum number of items reached.\n");
                break;
            }
            printf("Enter item name: ");
            scanf("%s", items[i].name);
            printf("Enter item cost: ");
            scanf("%f", &items[i].cost);
            printf("Enter item quantity: ");
            scanf("%d", &items[i].quantity);
            total_cost += items[i].cost * items[i].quantity;
            i++;
            break;

        case 2:
            if (i == 0) {
                printf("No expenses added yet.\n");
            } else {
                printf("\nItem\tCost\tQuantity\n");
                for (j = 0; j < i; j++) {
                    cost = items[j].cost * items[j].quantity;
                    printf("%s\t%.2f\t%d\n", items[j].name, items[j].cost, items[j].quantity);
                    total_cost += cost;
                }
                printf("\nTotal cost: %.2f\n", total_cost);
            }
            break;

        case 3:
            fprintf(fp, "Total cost: %.2f\n", total_cost);
            fclose(fp);
            printf("Expenses saved successfully.\n");
            exit(0);

        case 4:
            printf("Exiting without saving...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}