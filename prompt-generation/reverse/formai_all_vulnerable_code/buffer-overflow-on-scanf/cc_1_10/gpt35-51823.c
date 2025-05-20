//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Alan Touring
// This is a simple Medical Store Management System written in Alan Touring Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    int age;
    int phone_number;
};

int main() {
    struct medicine medical_store[100];
    struct customer cust_list[100];
    int option;
    int med_count = 0;
    int cust_count = 0;
    int i;
    float total_cost = 0;

    do {
        printf("\n\nWelcome to the Medical Store Management System\n");
        printf("\nSelect an option:\n");
        printf("\n1. Add Medicine");
        printf("\n2. Add Customer");
        printf("\n3. Sell Medicine");
        printf("\n4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the details of the medicine\n");
                printf("\nName: ");
                scanf("%s", medical_store[med_count].name);
                printf("\nQuantity: ");
                scanf("%d", &medical_store[med_count].quantity);
                printf("\nPrice: ");
                scanf("%f", &medical_store[med_count].price);

                med_count++;

                printf("\nMedicine added successfully!");
                break;

            case 2:
                printf("\nEnter the details of the customer\n");
                printf("\nName: ");
                scanf("%s", cust_list[cust_count].name);
                printf("\nAge: ");
                scanf("%d", &cust_list[cust_count].age);
                printf("\nPhone Number: ");
                scanf("%d", &cust_list[cust_count].phone_number);

                cust_count++;

                printf("\nCustomer added successfully!");
                break;

            case 3:
                printf("\nList of available medicines\n");
                printf("NAME\tQUANTITY\tPRICE\n");

                for (i = 0; i < med_count; i++) {
                    printf("%s\t%d\t\t%.2f\n", medical_store[i].name, medical_store[i].quantity, medical_store[i].price);
                }

                char med_name[50];
                int med_qty;
                float med_price = 0;

                printf("\nEnter the name of the medicine you want to sell: ");
                scanf("%s", med_name);

                printf("\nEnter the quantity you want to purchase: ");
                scanf("%d", &med_qty);

                for (i = 0; i < med_count; i++) {
                    if (strcmp(medical_store[i].name, med_name) == 0) {
                        if (medical_store[i].quantity >= med_qty) {
                            medical_store[i].quantity -= med_qty;
                            med_price = medical_store[i].price * med_qty;
                            total_cost += med_price;
                        } else {
                            printf("\nInsufficient quantity of medicine in stock!");
                        }
                    }
                }

                printf("\nMedicine sold successfully! Total cost: %.2f", med_price);
                break;

            case 4:
                printf("\nThank you for using the Medical Store Management System!");
                break;
            
            default:
                printf("\nInvalid option selected!");
        }
    } while (option != 4);

    return 0;
}