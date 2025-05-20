//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int id;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

int main() {
    int choice, num_items = 0, num_customers = 0;
    char ch;
    Customer customers[MAX_CUSTOMERS];
    Item items[MAX_ITEMS];

    do {
        printf("\n\nWelcome to the Cafe Billing System!\n\n");
        printf("Please choose an option:\n");
        printf("1. Add customer\n2. View customers\n3. Add item\n4. View items\n5. Generate bill\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter customer name: ");
            scanf("%s", customers[num_customers].name);
            customers[num_customers].id = num_customers + 1;
            num_customers++;
            break;
        case 2:
            printf("Customers:\n");
            for (int i = 0; i < num_customers; i++) {
                printf("%d. %s\n", customers[i].id, customers[i].name);
            }
            break;
        case 3:
            if (num_items >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item price: ");
                scanf("%f", &items[num_items].price);
                num_items++;
            }
            break;
        case 4:
            printf("Items:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
            }
            break;
        case 5:
            printf("Enter customer ID: ");
            scanf("%d", &ch);
            printf("Customer name: %s\n", customers[ch - 1].name);
            printf("Items ordered:\n");
            do {
                printf("Enter item number (0 to exit): ");
                scanf("%d", &ch);
                if (ch > 0 && ch <= num_items) {
                    printf("%d. %s - $%.2f\n", ch, items[ch - 1].name, items[ch - 1].price);
                }
            } while (ch > 0 && ch <= num_items);
            break;
        case 6:
            printf("Thank you for using the Cafe Billing System!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}