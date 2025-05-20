//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int price;
};

struct Customer {
    char name[50];
    int items[MAX_ITEMS];
    int num_items;
};

int main() {
    struct Item items[MAX_ITEMS];
    struct Customer customers[MAX_ITEMS];
    int num_items = 0;
    int num_customers = 0;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        char choice;
        printf("Enter your choice:\n");
        printf("a) Add new item\n");
        printf("b) Add new customer\n");
        printf("c) View items\n");
        printf("d) View customers\n");
        printf("e) Exit\n");

        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter the name of the item: ");
                scanf("%s", items[num_items].name);
                printf("Enter the price of the item: ");
                scanf("%d", &items[num_items].price);
                num_items++;
                break;
            case 'b':
                printf("Enter the name of the customer: ");
                scanf("%s", customers[num_customers].name);
                customers[num_customers].num_items = 0;
                num_customers++;
                break;
            case 'c':
                printf("Items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%s (%d)\n", items[i].name, items[i].price);
                }
                break;
            case 'd':
                printf("Customers:\n");
                for (int i = 0; i < num_customers; i++) {
                    printf("%s (%d items)\n", customers[i].name, customers[i].num_items);
                }
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}