//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, i;
    char filename[50];
    FILE *fp;
    struct item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Medieval Expense Tracker!\n");
    printf("Please enter a filename to save your expenses: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
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
            if (num_items >= MAX_ITEMS) {
                printf("Error: too many items.\n");
                break;
            }
            printf("Enter item name: ");
            scanf("%s", items[num_items].name);
            printf("Enter item price: ");
            scanf("%f", &items[num_items].price);
            printf("Enter item quantity: ");
            scanf("%d", &items[num_items].quantity);
            num_items++;
            break;

        case 2:
            for (i = 0; i < num_items; i++) {
                printf("%s - $%.2f (%d)\n", items[i].name, items[i].price, items[i].quantity);
            }
            break;

        case 3:
            fclose(fp);
            exit(0);

        case 4:
            printf("Exiting without saving...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}