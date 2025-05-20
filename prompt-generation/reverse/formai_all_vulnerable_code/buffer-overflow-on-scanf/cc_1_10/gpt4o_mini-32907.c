//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct MenuItem {
    char name[50];
    float price;
};

// Function declarations
void displayMenu(struct MenuItem menu[], int count);
float calculateTotal(struct MenuItem menu[], int order[], int count, int size);
void takeOrder(struct MenuItem menu[], int count);
void generateBill(float total);

int main() {
    struct MenuItem menu[MAX_ITEMS] = {
        {"Espresso", 2.50},
        {"Cappuccino", 3.00},
        {"Latte", 3.50},
        {"Mocha", 4.00},
        {"Tea", 1.50},
        {"Sandwich", 4.50},
        {"Cake", 2.00},
        {"Cookies", 1.00}
    };
    int menuCount = 8;

    printf("Welcome to the C Cafe!\n");
    printf("----------------------\n");
    
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. View Menu\n");
        printf("2. Place an Order\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMenu(menu, menuCount);
                break;
            case 2:
                takeOrder(menu, menuCount);
                break;
            case 3:
                printf("Thank you for visiting C Cafe! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void displayMenu(struct MenuItem menu[], int count) {
    printf("\n------ Cafe Menu ------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-----------------------\n");
}

void takeOrder(struct MenuItem menu[], int count) {
    int order[100];
    int orderCount = 0;

    printf("\nEnter the item numbers you wish to order (0 to finish):\n");
    
    while (1) {
        int itemNumber;
        scanf("%d", &itemNumber);
        
        if (itemNumber == 0) {
            break;
        } else if (itemNumber < 1 || itemNumber > count) {
            printf("Invalid item number! Please try again.\n");
        } else {
            order[orderCount++] = itemNumber - 1; // Store the index
        }
    }

    float total = calculateTotal(menu, order, count, orderCount);
    generateBill(total);
}

float calculateTotal(struct MenuItem menu[], int order[], int count, int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += menu[order[i]].price;
    }
    return total;
}

void generateBill(float total) {
    printf("\n------ Your Bill ------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("-----------------------\n");
    printf("Thank you for your order!\n");
}