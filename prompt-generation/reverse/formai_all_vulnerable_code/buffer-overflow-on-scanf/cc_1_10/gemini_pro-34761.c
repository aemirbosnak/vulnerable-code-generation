//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char category[50];
    float price;
    int quantity;
} medicine;

void add_medicine(medicine *stock, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", stock[*count].name);

    printf("Enter medicine category: ");
    scanf("%s", stock[*count].category);

    printf("Enter medicine price: ");
    scanf("%f", &stock[*count].price);

    printf("Enter medicine quantity: ");
    scanf("%d", &stock[*count].quantity);

    *count = *count + 1;
}

void sell_medicine(medicine *stock, int *count) {
    char name[50];
    int quantity;

    printf("Enter medicine name to sell: ");
    scanf("%s", name);

    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < *count; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            if (stock[i].quantity < quantity) {
                printf("Insufficient quantity in stock\n");
            } else {
                stock[i].quantity = stock[i].quantity - quantity;
                printf("Medicine sold successfully\n");
            }
            break;
        }
    }
}

void display_stock(medicine *stock, int count) {
    printf("\nMedical Store Stock:\n");
    printf("---------------------------------------------------------\n");
    printf("%-25s %-25s %-10s %-10s\n", "Name", "Category", "Price", "Quantity");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-25s %-25s $%-10.2f %-10d\n", stock[i].name, stock[i].category, stock[i].price, stock[i].quantity);
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    medicine stock[100];
    int count = 0;

    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("---------------------------------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Sell Medicine\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");
        printf("---------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(stock, &count);
                break;
            case 2:
                sell_medicine(stock, &count);
                break;
            case 3:
                display_stock(stock, count);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}