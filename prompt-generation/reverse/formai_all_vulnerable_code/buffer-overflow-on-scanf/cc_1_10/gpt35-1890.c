//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void display_medicine(struct medicine med) {
    printf("\nMedicine Name: %s\n", med.name);
    printf("Quantity Available: %d\n", med.quantity);
    printf("Price per Unit: $%.2f\n", med.price);
}

int search_medicine(struct medicine meds[], char name[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void update_medicine(struct medicine *med) {
    int choice, new_quantity;
    float new_price;
    printf("What do you want to do?\n");
    printf("1. Update Quantity\n");
    printf("2. Update Price\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter new Quantity: ");
            scanf("%d", &new_quantity);
            med->quantity = new_quantity;
            printf("Quantity Updated Successfully!\n");
            break;
        case 2:
            printf("Enter new Price: $");
            scanf("%f", &new_price);
            med->price = new_price;
            printf("Price Updated Successfully!\n");
            break;
        default:
            printf("Invalid Choice!");
            break;
    }
}

int main() {
    int i, size, choice, pos;
    char name[50];
    struct medicine meds[100];
    
    printf("Welcome to Medical Store Management System\n");
    printf("How many medicines you want to enter? ");
    scanf("%d", &size);
    
    for (i = 0; i < size; i++) {
        printf("\nEnter Medicine %d Details:\n", i+1);
        printf("Name: ");
        scanf("%s", meds[i].name);
        printf("Quantity Available: ");
        scanf("%d", &meds[i].quantity);
        printf("Price per Unit: $");
        scanf("%f", &meds[i].price);
    }
    
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Display Medicine Details\n");
        printf("2. Update Medicine Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter Medicine Name: ");
                scanf("%s", name);
                pos = search_medicine(meds, name, size);
                if (pos == -1) {
                    printf("Medicine Not Found!");
                } else {
                    display_medicine(meds[pos]);
                }
                break;
            case 2:
                printf("\nEnter Medicine Name: ");
                scanf("%s", name);
                pos = search_medicine(meds, name, size);
                if (pos == -1) {
                    printf("Medicine Not Found!");
                } else {
                    update_medicine(&meds[pos]);
                }
                break;
            case 3:
                printf("Thanks for using our System. Goodbye!");
                exit(0);
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}