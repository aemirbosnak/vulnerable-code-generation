//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} item_t;

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[num_items].name);

        printf("Enter item price: $");
        if (scanf("%lf", &items[num_items].price)!= 1) {
            printf("Invalid input. Please enter a valid price.\n");
            continue;
        }

        num_items++;
    }

    printf("Expense Tracker\n");
    printf("================\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Quit\n");

        int choice;
        if (scanf("%d", &choice)!= 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter expense name: ");
            scanf("%s", items[num_items].name);

            printf("Enter expense price: $");
            if (scanf("%lf", &items[num_items].price)!= 1) {
                printf("Invalid input. Please enter a valid price.\n");
                continue;
            }

            num_items++;
            printf("Expense added.\n");
            break;

        case 2:
            printf("Expenses:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%s: $%.2lf\n", items[i].name, items[i].price);
            }
            break;

        case 3:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}