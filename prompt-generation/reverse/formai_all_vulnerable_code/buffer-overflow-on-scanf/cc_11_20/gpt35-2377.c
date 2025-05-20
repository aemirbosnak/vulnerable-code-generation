//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[20];
    int quantity;
    float price;
} Medicine;

typedef struct {
    char name[20];
    Medicine cart[MAX_MEDICINES];
    int num_of_meds;
    float total_cost;
} Customer;

int main() {
    int choice;
    Medicine inventory[MAX_MEDICINES];
    Customer customers[MAX_CUSTOMERS];
    int num_of_meds = 0;
    int num_of_customers = 0;

    printf("Welcome to the Medical Store Management System!\n");

    do {
        printf("\n1. Add medicine to inventory\n");
        printf("2. Show inventory\n");
        printf("3. Add customer to database\n");
        printf("4. Show customer database\n");
        printf("5. Make a sale\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[20];
                int quantity;
                float price;

                printf("Enter the name of the medicine to add: ");
                scanf("%s", name);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                printf("Enter the price: ");
                scanf("%f", &price);

                Medicine med = { .quantity = quantity, .price = price };
                strcpy(med.name, name);
                inventory[num_of_meds++] = med;

                printf("%s added to inventory!\n", name);
                break;
            }
            case 2: {
                printf("Inventory:\n");
                printf("Medicine Name\tQuantity\tPrice\n");

                for(int i = 0; i < num_of_meds; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }

                break;
            }
            case 3: {
                char name[20];

                printf("Enter the name of the customer to add: ");
                scanf("%s", name);

                Customer cust = { .num_of_meds = 0, .total_cost = 0.0 };
                strcpy(cust.name, name);
                customers[num_of_customers++] = cust;

                printf("%s added to the customer database!\n", name);
                break;
            }
            case 4: {
                printf("Customer Database:\n");
                printf("Name\t\tNumber of Drugs\tTotal Cost\n");

                for(int i = 0; i < num_of_customers; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", customers[i].name, customers[i].num_of_meds, customers[i].total_cost);
                }

                break;
            }
            case 5: {
                char name[20];
                char med_name[20];
                int quantity;

                printf("Enter the name of the customer: ");
                scanf("%s", name);

                Customer *cust = NULL;

                for(int i = 0; i < num_of_customers; i++) {
                    if(strcmp(customers[i].name, name) == 0) {
                        cust = &customers[i];
                        break;
                    }
                }

                if(cust == NULL) {
                    printf("Customer not found in database!\n");
                    break;
                }

                printf("Enter the name of the medicine to sell: ");
                scanf("%s", med_name);

                Medicine *med = NULL;

                for(int i = 0; i < num_of_meds; i++) {
                    if(strcmp(inventory[i].name, med_name) == 0) {
                        med = &inventory[i];
                        break;
                    }
                }

                if(med == NULL) {
                    printf("Medicine not found in inventory!\n");
                    break;
                }

                printf("Enter the quantity to sell: ");
                scanf("%d", &quantity);

                if(quantity > med->quantity) {
                    printf("Insufficient quantity in inventory to sell!\n");
                    break;
                }

                float total_cost = med->price * quantity;

                cust->cart[cust->num_of_meds++] = *med;
                cust->total_cost += total_cost;

                med->quantity -= quantity;

                printf("Sale successful! Total cost: %.2f\n", total_cost);

                break;
            }
            case 0: {
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }

    } while(choice != 0);

    return 0;
}