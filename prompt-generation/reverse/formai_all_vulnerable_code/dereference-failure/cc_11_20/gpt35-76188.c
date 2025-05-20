//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    int stock;
    float price;
};

int main() {
    int choice, i, n, id;
    float totalPrice;
    struct Medicine *meds;

    printf("Enter the number of medicines: ");
    scanf("%d", &n);

    meds = (struct Medicine*) malloc(n * sizeof(struct Medicine));

    printf("Enter the details of medicines: \n");
    for(i=0; i<n; i++) {
        meds[i].id = i + 1;
        printf("\nMedicine %d: \n", i+1);
        printf("Name: ");
        scanf("%s", &meds[i].name);
        printf("Price: ");
        scanf("%f", &meds[i].price);
        printf("Stock: ");
        scanf("%d", &meds[i].stock);
    }

    do {
        printf("\n\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. List all medicines\n");
        printf("2. Check Stock\n");
        printf("3. Purchase Medicine\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\nID\tName\t\tPrice\t\tStock\n");
                for(i=0; i<n; i++) {
                    printf("%d\t%s\t\t%.2f\t\t%d\n", meds[i].id, meds[i].name, meds[i].price, meds[i].stock);
                }
                break;

            case 2:
                printf("\nEnter the ID of medicine: ");
                scanf("%d", &id);
                for(i=0; i<n; i++) {
                    if(meds[i].id == id) {
                        printf("\nStock of %s: %d", meds[i].name, meds[i].stock);
                        break;
                    }
                }
                if(i == n) {
                    printf("\nInvalid ID!");
                }
                break;

            case 3:
                printf("\nEnter the ID of medicine to purchase: ");
                scanf("%d", &id);
                for(i=0; i<n; i++) {
                    if(meds[i].id == id) {
                        if(meds[i].stock == 0) {
                            printf("\n%s is out of stock!", meds[i].name);
                            break;
                        } else {
                            printf("\nEnter the quantity: ");
                            int quantity;
                            scanf("%d", &quantity);
                            if(quantity > meds[i].stock) {
                                printf("\nSorry, only %d units of %s is available", meds[i].stock, meds[i].name);
                            } else {
                                totalPrice = meds[i].price * quantity;
                                printf("\nTotal price of %s (Qty: %d): %.2f", meds[i].name, quantity, totalPrice);
                                meds[i].stock -= quantity;
                                break;
                            }
                        }
                    }
                }
                if(i == n) {
                    printf("\nInvalid ID!");
                }
                break;

            case 4:
                printf("\nThank you for using the Medical Store Management System.");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.");
                break;
        }
    } while(choice != 4);

    free(meds);

    return 0;
}