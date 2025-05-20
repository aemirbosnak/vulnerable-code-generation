//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int cur_size;
struct medicine {
    char name[50];
    int quantity;
    float price;
} stock[MAX_SIZE];

// Function to display the options menu
void display_options() {
    printf("1. Add medicine\n");
    printf("2. Sell medicine\n");
    printf("3. Check medicine stock\n");
    printf("4. View sales report\n");
    printf("5. Exit\n");
}

// Function to calculate total sales amount
float calculate_sales() {
    float total_sales = 0;
    for(int i=0; i<cur_size; i++) {
        total_sales += stock[i].price * stock[i].quantity;
    }
    return total_sales;
}

// Function to add medicine to stock
void add_medicine() {
    printf("Enter medicine name: ");
    scanf("%s", stock[cur_size].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &stock[cur_size].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &stock[cur_size].price);
    printf("%s added successfully!\n", stock[cur_size].name);
    cur_size++;
}

// Function to sell medicine
void sell_medicine() {
    char medicine_name[50];
    int sell_quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", medicine_name);
    printf("Enter quantity to sell: ");
    scanf("%d", &sell_quantity);
    for(int i=0; i<cur_size; i++) {
        if(strcmp(stock[i].name, medicine_name) == 0) {
            if(stock[i].quantity >= sell_quantity) {
                stock[i].quantity -= sell_quantity;
                printf("%d %s sold for $%.2f each\n", sell_quantity, medicine_name, stock[i].price);
                return;
            } else {
                printf("Insufficient stock!\n");
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

// Function to check medicine stock
void check_stock() {
    printf("Medicine stock:\n");
    printf("Name \t Quantity \t Price\n");
    for(int i=0; i<cur_size; i++) {
        printf("%s \t %d \t\t $%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

// Function to view sales report
void view_report() {
    printf("Sales report:\n");
    printf("Name \t Quantity \t Price \t Total\n");
    for(int i=0; i<cur_size; i++) {
        float total_sales = stock[i].price * stock[i].quantity;
        printf("%s \t %d \t\t $%.2f \t $%.2f\n", stock[i].name, stock[i].quantity, stock[i].price, total_sales);
    }
    printf("Total sales: $%.2f\n", calculate_sales());
}

int main() {
    cur_size = 0;
    int option;
    while(option != 5) {
        display_options();
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_medicine();
                break;
            case 2:
                sell_medicine();
                break;
            case 3:
                check_stock();
                break;
            case 4:
                view_report();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}