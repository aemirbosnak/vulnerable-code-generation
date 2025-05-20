//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100 // maximum capacity of the medical store

typedef struct Medicine {
    int code; // unique code for each medicine
    char name[50]; // name of the medicine
    float price; // price of the medicine
    int quantity; // quantity available in stock
} Medicine;

Medicine stock[MAX_STOCK]; // array to hold the medicine stock
int stock_count = 0; // current count of medicine in stock

void add_medicine() {
    Medicine new_medicine;
    printf("Enter medicine code: ");
    scanf("%d", &new_medicine.code);
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine.quantity);
    
    if (stock_count < MAX_STOCK) { // check if stock is not full
        stock[stock_count] = new_medicine;
        stock_count++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Sorry, stock is full, cannot add medicine.\n");
    }
}

void view_stock() {
    printf("\nCode\tName\tPrice\tQuantity\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", stock[i].code, stock[i].name, stock[i].price, stock[i].quantity);
    }
    printf("\n");
}

void search_medicine() {
    int medicine_code;
    printf("Enter medicine code: ");
    scanf("%d", &medicine_code);
    
    for (int i = 0; i < stock_count; i++) {
        if (stock[i].code == medicine_code) {
            printf("\nCode\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n\n", stock[i].code, stock[i].name, stock[i].price, stock[i].quantity);
            return;
        }
    }
    
    printf("Sorry, medicine with code %d was not found.\n", medicine_code);
}

void sell_medicine() {
    int medicine_code, quantity;
    printf("Enter medicine code: ");
    scanf("%d", &medicine_code);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < stock_count; i++) {
        if (stock[i].code == medicine_code) {
            if (stock[i].quantity >= quantity) { // check if there's enough stock to sell
                stock[i].quantity -= quantity;
                printf("%d %s sold for %.2f each for a total of %.2f.\n", quantity, stock[i].name, stock[i].price, quantity * stock[i].price);
                printf("Remaining stock: %d\n", stock[i].quantity);
                return;
            } else {
                printf("Sorry, only %d %s available in stock.\n", stock[i].quantity, stock[i].name);
                return;
            }
        }
    }
    
    printf("Sorry, medicine with code %d was not found.\n", medicine_code);
}

int main() {
    int choice;
    while (1) {
        printf("1. Add medicine\n");
        printf("2. View stock\n");
        printf("3. Search medicine\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_stock();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                sell_medicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}