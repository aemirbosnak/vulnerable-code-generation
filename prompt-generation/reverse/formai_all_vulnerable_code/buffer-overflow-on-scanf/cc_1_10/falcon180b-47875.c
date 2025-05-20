//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

void display_menu(item menu[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

void add_item(item order[], int *size) {
    printf("Enter item name: ");
    scanf("%s", order[*size].name);
    printf("Enter quantity: ");
    scanf("%d", &order[*size].quantity);
    printf("Enter price per unit: $");
    scanf("%f", &order[*size].price);
    (*size)++;
}

void calculate_total(item order[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += (float)order[i].quantity * order[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int size = 0;
    item menu[] = {{"Coffee", 1, 3.50}, {"Tea", 1, 2.50}, {"Pastry", 1, 2.00}};
    item order[10];

    printf("Welcome to the Cafe!\n");
    display_menu(menu, 3);

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            add_item(order, &size);
        } else if (choice == 2) {
            calculate_total(order, size);
        } else if (choice == 3) {
            printf("Thank you for your visit!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}