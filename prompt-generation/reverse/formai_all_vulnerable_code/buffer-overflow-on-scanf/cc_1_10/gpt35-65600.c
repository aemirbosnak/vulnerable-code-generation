//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
    char expiry_date[20];
};

void add_medicine(struct medicine arr[], int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", arr[*size].name);
    printf("Enter the name of the manufacturer: ");
    scanf("%s", arr[*size].manufacturer);
    printf("Enter the price of the medicine (in rupees): ");
    scanf("%f", &arr[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &arr[*size].quantity);
    printf("Enter the expiry date of the medicine (in dd/mm/yyyy format): ");
    scanf("%s", arr[*size].expiry_date);
    (*size)++;
    printf("\nMedicine added successfully!\n\n");
}

void sell_medicine(struct medicine arr[], int *size) {
    char med_name[50];
    int med_quantity = 0;
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", med_name);
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &med_quantity);

    for (int i = 0; i < *size; i++) {
        if (strcmp(med_name, arr[i].name) == 0) {
            if (arr[i].quantity >= med_quantity) {
                arr[i].quantity -= med_quantity;
                printf("\nMedicine sold successfully!\n\n");
                return;
            } else {
                printf("\nMedicine stock not sufficient!\n");
                return;
            }
        }
    }
    printf("\nMedicine not found!\n\n");
}

void display_stock(struct medicine arr[], int size) {
    if (size == 0) {
        printf("\nNo medicines in stock!\n\n");
        return;
    }
    printf("\n%-20s%-20s%-20s%-20s%s\n", "Name", "Manufacturer", "Price (Rs)", "Quantity", "Expiry Date");
    for (int i = 0; i < size; i++) {
        printf("%-20s%-20s%-20.2f%-20d%s\n", arr[i].name, arr[i].manufacturer, arr[i].price, arr[i].quantity, arr[i].expiry_date);
    }
    printf("\n");
}

void display_menu() {
    printf("Welcome to the Medical Store Management System!\n\n");
    printf("1. Add a new medicine to the stock\n");
    printf("2. Sell a medicine from the stock\n");
    printf("3. Display current stock of medicines\n");
    printf("4. Exit\n\n");
}

int main() {
    struct medicine arr[50];
    int size = 0;
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_medicine(arr, &size);
                break;
            case 2:
                sell_medicine(arr, &size);
                break;
            case 3:
                display_stock(arr, size);
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}