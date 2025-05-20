//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char brand[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    char name[50];
    char address[100];
    char contact_number[20];
} Customer;

void add_medicine(Medicine *medicines, int *num_medicines) {
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter the brand of the medicine: ");
    scanf("%s", medicines[*num_medicines].brand);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[*num_medicines].price);
    (*num_medicines)++;
}

void sell_medicine(Medicine *medicines, int *num_medicines, Customer *customers, int *num_customers) {
    char medicine_name[50];
    int quantity;
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", medicine_name);
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(medicines[i].name, medicine_name) == 0) {
            if (medicines[i].quantity < quantity) {
                printf("Sorry, we don't have enough quantity of this medicine in stock.\n");
                return;
            }
            medicines[i].quantity -= quantity;
            printf("Medicine sold successfully.\n");
            printf("Enter the name of the customer: ");
            scanf("%s", customers[*num_customers].name);
            printf("Enter the address of the customer: ");
            scanf("%s", customers[*num_customers].address);
            printf("Enter the contact number of the customer: ");
            scanf("%s", customers[*num_customers].contact_number);
            (*num_customers)++;
            return;
        }
    }
    printf("Sorry, we don't have this medicine in stock.\n");
}

void display_medicines(Medicine *medicines, int num_medicines) {
    printf("Name\t\tBrand\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", medicines[i].name, medicines[i].brand, medicines[i].quantity, medicines[i].price);
    }
}

void display_customers(Customer *customers, int num_customers) {
    printf("Name\t\tAddress\t\tContact Number\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t\t%s\t\t%s\n", customers[i].name, customers[i].address, customers[i].contact_number);
    }
}

int main() {
    Medicine medicines[100];
    int num_medicines = 0;
    Customer customers[100];
    int num_customers = 0;
    int choice;
    do {
        printf("1. Add Medicine\n2. Sell Medicine\n3. Display Medicines\n4. Display Customers\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                sell_medicine(medicines, &num_medicines, customers, &num_customers);
                break;
            case 3:
                display_medicines(medicines, num_medicines);
                break;
            case 4:
                display_customers(customers, num_customers);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);
    return 0;
}