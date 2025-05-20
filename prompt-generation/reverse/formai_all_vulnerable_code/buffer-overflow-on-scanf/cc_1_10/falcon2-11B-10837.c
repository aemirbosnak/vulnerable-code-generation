//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
    char name[50];
    int price;
};

struct Medicine medicine1 = {"Paracetamol", 100};
struct Medicine medicine2 = {"Aspirin", 150};
struct Medicine medicine3 = {"Ibuprofen", 200};

struct Medicine* getMedicine(int price) {
    if (price < medicine1.price) {
        return &medicine1;
    } else if (price < medicine2.price) {
        return &medicine2;
    } else {
        return &medicine3;
    }
}

int main() {
    int choice, price;
    printf("Welcome to the Medical Store Management System!\n");
    printf("Please enter your choice:\n");
    printf("1. View Medicine List\n");
    printf("2. Add New Medicine\n");
    printf("3. Update Medicine Price\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Medicine List:\n");
                printf("Name   Price\n");
                printf("--------------------------------------------------\n");
                printf("%s  %d\n", medicine1.name, medicine1.price);
                printf("%s  %d\n", medicine2.name, medicine2.price);
                printf("%s  %d\n", medicine3.name, medicine3.price);
                break;
            case 2:
                printf("Enter the name of the medicine: ");
                scanf("%s", medicine1.name);
                printf("Enter the price of the medicine: ");
                scanf("%d", &price);
                medicine1.price = price;
                printf("Medicine added successfully!\n");
                break;
            case 3:
                printf("Enter the name of the medicine: ");
                scanf("%s", medicine1.name);
                printf("Enter the new price of the medicine: ");
                scanf("%d", &price);
                medicine1.price = price;
                printf("Medicine price updated successfully!\n");
                break;
            case 4:
                printf("Enter the name of the medicine: ");
                scanf("%s", medicine1.name);
                printf("Are you sure you want to delete %s? (y/n): ", medicine1.name);
                scanf(" %c", &choice);
                if (choice == 'y') {
                    medicine1.price = 0;
                    printf("Medicine deleted successfully!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
        printf("Please enter your choice:\n");
        printf("1. View Medicine List\n");
        printf("2. Add New Medicine\n");
        printf("3. Update Medicine Price\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
    }
    printf("Thank you for using the Medical Store Management System!\n");
    return 0;
}