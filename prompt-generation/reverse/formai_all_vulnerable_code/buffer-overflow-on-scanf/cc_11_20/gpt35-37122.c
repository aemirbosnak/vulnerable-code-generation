//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char brand[50];
    int quantity;
    float price;
};

int main() {
    int choice, i, n, found = 0, sum = 0;
    float total;
    char search[50];
    struct Medicine m[50];

    printf("Enter the number of medicines: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("\nMedicine %d\n", i+1);

        printf("Enter name: ");
        scanf("%s", m[i].name);

        printf("Enter brand: ");
        scanf("%s", m[i].brand);

        printf("Enter quantity: ");
        scanf("%d", &m[i].quantity);

        printf("Enter price: ");
        scanf("%f", &m[i].price);
    }

    do {
        printf("\n-------- Medical Store Management System Menu --------\n");
        printf("1. Display all medicines\n");
        printf("2. Search for a medicine\n");
        printf("3. Calculate total price\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n%-20s%-20s%-20s%s\n", "Name", "Brand", "Quantity", "Price");

                for(i=0; i<n; i++) {
                    printf("%-20s%-20s%-20d%.2f\n", m[i].name, m[i].brand, m[i].quantity, m[i].price);
                }

                break;

            case 2:
                printf("\nEnter name of medicine to search: ");
                scanf("%s", search);

                found = 0;

                for(i=0; i<n; i++) {
                    if(strcmp(m[i].name, search) == 0) {
                        printf("\nMedicine found!\n");
                        printf("%-20s%-20s%-20d%.2f\n", m[i].name, m[i].brand, m[i].quantity, m[i].price);
                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("\nMedicine not found.\n");
                }

                break;

            case 3:
                sum = 0;

                for(i=0; i<n; i++) {
                    sum += m[i].quantity * m[i].price;
                }

                total = sum * 1.18;

                printf("\nTotal price (including GST) is %.2f\n", total);

                break;

            case 4:
                printf("\nExiting program! Thank you.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}