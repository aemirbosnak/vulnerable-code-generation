//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    double amount;
    int due_date;
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);

    printf("Enter the amount: $");
    scanf("%lf", &items[num_items].amount);

    printf("Enter the due date (in days): ");
    scanf("%d", &items[num_items].due_date);

    num_items++;
}

void view_items() {
    printf("\nItem\tAmount\tDue Date\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2lf\t%d\n", items[i].name, items[i].amount, items[i].due_date);
    }
}

void remove_item() {
    printf("Enter the index of the item to remove: ");
    int index;
    scanf("%d", &index);

    if (index >= 0 && index < num_items) {
        printf("Removed item: %s\n", items[index].name);
        for (int i = index; i < num_items - 1; i++) {
            items[i] = items[i+1];
        }
        num_items--;
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Remove item\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                remove_item();
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}