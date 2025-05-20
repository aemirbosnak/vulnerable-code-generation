//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int age;
    float balance;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];
int num_customers = 0;
int num_items = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[num_customers].age);
    customers[num_customers].balance = 0;
    num_customers++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void print_menu() {
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void place_order(int customer_index, int item_index) {
    printf("\nOrder placed by %s for %s\n", customers[customer_index].name, items[item_index].name);
    customers[customer_index].balance -= items[item_index].price;
}

int main() {
    int choice;
    do {
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. Add customer\n2. Add item\n3. Place order\n4. Print menu\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_item();
                break;
            case 3:
                printf("Enter customer index: ");
                scanf("%d", &choice);
                printf("Enter item index: ");
                scanf("%d", &choice);
                place_order(choice-1, choice-1);
                break;
            case 4:
                print_menu();
                break;
            case 5:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}