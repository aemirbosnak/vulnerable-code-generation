//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char room[50];
    int price;
} Customer;

int main() {
    Customer customers[100];
    int num_customers = 0;

    printf("Welcome to the Hotel Management System!\n");

    while (1) {
        char choice;
        printf("1. Add customer\n");
        printf("2. Remove customer\n");
        printf("3. Display customers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter customer name: ");
                scanf("%s", customers[num_customers].name);
                printf("Enter room number: ");
                scanf("%s", customers[num_customers].room);
                printf("Enter price: ");
                scanf("%d", &customers[num_customers].price);
                num_customers++;
                break;
            case '2':
                printf("Enter customer name: ");
                scanf("%s", customers[num_customers].name);
                printf("Customer removed successfully.\n");
                break;
            case '3':
                printf("Customers:\n");
                for (int i = 0; i < num_customers; i++) {
                    printf("Name: %s\nRoom: %s\nPrice: %d\n", customers[i].name, customers[i].room, customers[i].price);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}