//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[100];
    int quantity;
    float price;
};

int main() {
    struct medicine m[100];
    int num_medicines, choice, num, i;
    char search[100];

    printf("Welcome to the C Medical Store Management System!\n");
    printf("Enter the number of medicines in the store: ");
    scanf("%d", &num_medicines);

    // Loop to input details for each medicine
    for(i=0; i<num_medicines; i++) {
        printf("\nFor medicine %d: \n", i+1);
        printf("Enter the name: ");
        scanf("%s", m[i].name);
        printf("Enter the quantity: ");
        scanf("%d", &m[i].quantity);
        printf("Enter the price: ");
        scanf("%f", &m[i].price);
    }

    // Menu
    while (1) {
        printf("\nEnter your choice: \n1. Display all medicines\n2. Search for a medicine\n3. Exit\n Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHere is the list of all medicines:\n Medicine Name \t Quantity \t Price\n");
                for(i=0; i<num_medicines; i++) {
                    printf("%-15s %5d %10.2f\n", m[i].name, m[i].quantity, m[i].price);
                }
                break;

            case 2:
                printf("\nEnter the name of the medicine you want to search: ");
                scanf("%s", search);
                for(i=0; i<num_medicines; i++) {
                    if(strcmp(search, m[i].name) == 0) {
                        printf("\nMedicine found! Here are the details: \n");
                        printf("Medicine Name: %s\nQuantity: %d\nPrice: %.2f\n", m[i].name, m[i].quantity, m[i].price);
                        break;
                    }
                }
                if(i == num_medicines) {
                    printf("\nMedicine not found!\n");
                }
                break;

            case 3:
                printf("\nThank you for using the C Medical Store Management System!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}