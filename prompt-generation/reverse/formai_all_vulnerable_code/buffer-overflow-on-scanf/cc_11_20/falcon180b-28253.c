//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_TRANSACTIONS 100

struct item {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct customer {
    int id;
    char name[50];
    char address[100];
    int phone;
};

struct transaction {
    int id;
    int customer_id;
    struct item *items[MAX_ITEMS];
    int num_items;
    float total_price;
};

int main() {
    int choice;
    char ch;

    do {
        printf("\nWelcome to the Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Add customer\n");
        printf("6. View customers\n");
        printf("7. Update customer\n");
        printf("8. Delete customer\n");
        printf("9. Make transaction\n");
        printf("10. View transactions\n");
        printf("11. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &ch);
                break;

            case 2:
                printf("Enter item ID: ");
                scanf("%d", &ch);
                break;

            case 3:
                printf("Enter item ID: ");
                scanf("%d", &ch);
                break;

            case 4:
                printf("Enter item ID: ");
                scanf("%d", &ch);
                break;

            case 5:
                printf("Enter customer ID: ");
                scanf("%d", &ch);
                break;

            case 6:
                printf("Enter customer ID: ");
                scanf("%d", &ch);
                break;

            case 7:
                printf("Enter customer ID: ");
                scanf("%d", &ch);
                break;

            case 8:
                printf("Enter customer ID: ");
                scanf("%d", &ch);
                break;

            case 9:
                printf("Enter customer ID: ");
                scanf("%d", &ch);
                break;

            case 10:
                printf("Enter transaction ID: ");
                scanf("%d", &ch);
                break;

            case 11:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 11);

    return 0;
}