//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *stock;
int stock_size = 0;

void add_medicine() {
    printf("Enter medicine name: ");
    scanf("%s", stock[stock_size].name);
    printf("Enter quantity: ");
    scanf("%d", &stock[stock_size].quantity);
    printf("Enter price: ");
    scanf("%f", &stock[stock_size].price);
    stock_size++;
}

void view_stock() {
    printf("Medicine Name\tQuantity\tPrice\n");
    for (int i = 0; i < stock_size; i++) {
        printf("%s\t%d\t%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < stock_size; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\n", stock[i].name);
            printf("Quantity: %d\n", stock[i].quantity);
            printf("Price: %.2f\n", stock[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < stock_size; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &stock[i].price);
            printf("Medicine updated.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void delete_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < stock_size; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            for (int j = i; j < stock_size - 1; j++) {
                stock[j] = stock[j + 1];
            }
            stock_size--;
            printf("Medicine deleted.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");
    int choice;
    while (1) {
        printf("\n1. Add Medicine\n2. View Stock\n3. Search Medicine\n4. Update Medicine\n5. Delete Medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}