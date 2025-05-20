//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100 //maximum size of the stock
#define MAX_NAME 50 //maximum size of the medicine name
#define MAX_PURCHASES 10 //maximum size of the purchase record

//structure to store the details of a medicine
struct medicine {
    char name[MAX_NAME];
    int quantity;
    int price;
};

//global variables
struct medicine stock[MAX_STOCK]; //array to store the medicine stock
int num_stock = 0; //current number of medicines in stock
int purchases[MAX_PURCHASES]; //array to store the purchase record
int num_purchases = 0; //current number of purchases

//function to add a medicine to the stock
void add_medicine() {
    if (num_stock == MAX_STOCK) {
        printf("Unable to add medicine, stock is full.\n");
        return;
    }
    struct medicine med;
    printf("Enter the name of the medicine: ");
    fgets(med.name, MAX_NAME, stdin);
    med.name[strcspn(med.name, "\n")] = '\0'; //remove newline character
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med.quantity);
    printf("Enter the price of the medicine: ");
    scanf("%d", &med.price);
    getchar(); //consume newline character
    stock[num_stock] = med;
    num_stock++;
    printf("Medicine added successfully.\n");
}

//function to display the stock
void display_stock() {
    printf("Medicine Stock:\n");
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_stock; i++) {
        printf("%s\t\t%d\t\t%d\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

//function to purchase a medicine
void purchase_medicine() {
    if (num_stock == 0) {
        printf("Unable to purchase medicine, stock is empty.\n");
        return;
    }
    char med_name[MAX_NAME];
    printf("Enter the name of the medicine: ");
    fgets(med_name, MAX_NAME, stdin);
    med_name[strcspn(med_name, "\n")] = '\0'; //remove newline character
    int quantity;
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);
    getchar(); //consume newline character
    int med_index = -1;
    for (int i = 0; i < num_stock; i++) {
        if (strcmp(med_name, stock[i].name) == 0) {
            med_index = i;
            break;
        }
    }
    if (med_index == -1) {
        printf("Unable to purchase medicine, medicine not found.\n");
        return;
    }
    if (stock[med_index].quantity < quantity) {
        printf("Unable to purchase medicine, insufficient quantity.\n");
        return;
    }
    int total_price = quantity * stock[med_index].price;
    stock[med_index].quantity -= quantity;
    purchases[num_purchases] = total_price;
    num_purchases++;
    printf("Medicine purchased successfully, total price is %d.\n", total_price);
}

//function to display the purchase record
void display_purchases() {
    printf("Purchase Record:\n");
    printf("Total Price\n");
    for (int i = 0; i < num_purchases; i++) {
        printf("%d\n", purchases[i]);
    }
}

int main() {
    int choice;
    do {
        printf("Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Stock\n");
        printf("3. Purchase Medicine\n");
        printf("4. Display Purchase Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //consume newline character
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_stock();
                break;
            case 3:
                purchase_medicine();
                break;
            case 4:
                display_purchases();
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 5);
    return 0;
}