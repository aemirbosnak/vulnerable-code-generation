//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include<stdio.h>
#include<string.h>
#define SIZE 50

struct Menu {
    char name[20];
    int price;
};

struct Order {
    char name[20];
    int quantity;
};

void displayMenu(struct Menu menu[], int size);
int calculateBill(struct Order orders[], struct Menu menu[], int size);

int main() {
    int choice, totalPrice = 0, items = 0;
    struct Menu menu[SIZE] = {
        {"Coffee", 50},
        {"Tea", 20},
        {"Hot chocolate", 40},
        {"Cold coffee", 60},
        {"Mango smoothie", 80},
        {"Pesto sandwich", 100},
        {"Chicken burger", 120},
        {"French fries", 60},
    };
    struct Order orders[SIZE];
    printf("------- Welcome to Cafe C -------\n\n");
    do {
        printf("What would you like to do?\n");
        printf("1. Display menu\n");
        printf("2. Place order\n");
        printf("3. View order\n");
        printf("4. Calculate total bill\n");
        printf("5. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayMenu(menu, SIZE);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", orders[items].name);
                printf("Enter quantity: ");
                scanf("%d", &orders[items].quantity);
                items++;
                break;
            case 3:
                printf("------ Orders ------\n");
                for(int i=0; i<items; i++) {
                    printf("%d. %s - %d\n", i+1, orders[i].name, orders[i].quantity);
                }
                printf("--------------------\n");
                break;
            case 4:
                totalPrice = calculateBill(orders, menu, items);
                printf("Total bill: %d\n", totalPrice);
                break;
            case 5:
                printf("Thank you for visiting Cafe C!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

void displayMenu(struct Menu menu[], int size) {
    printf("------- Menu -------\n");
    for(int i=0; i<size; i++) {
        printf("%d. %-20s %d\n", i+1, menu[i].name, menu[i].price);
    }
    printf("--------------------\n");
}

int calculateBill(struct Order orders[], struct Menu menu[], int size) {
    int total = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<SIZE; j++) {
            if(strcmp(orders[i].name, menu[j].name) == 0) {
                total += orders[i].quantity*menu[j].price;
                break;
            }
        }
    }
    return total;
}