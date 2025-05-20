//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

typedef struct {
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int size) {
    printf("\nWelcome to the Tranquil Café!\n");
    printf("Here is our delightful menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\nPlease select the items you wish to order (1 to %d, 0 to finish):\n", size);
}

float calculateTotal(int choices[], MenuItem menu[], int size) {
    float total = 0.0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (choices[i] > 0 && choices[i] <= size) {
            total += menu[choices[i] - 1].price;
        }
    }
    return total;
}

void generateReceipt(int choices[], MenuItem menu[], int size, float total) {
    printf("\n--- Receipt ---\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (choices[i] > 0 && choices[i] <= size) {
            printf("%s - $%.2f\n", menu[choices[i] - 1].name, menu[choices[i] - 1].price);
        }
    }
    printf("----------------\n");
    printf("Total: $%.2f\n", total);
    printf("Thank you for visiting the Tranquil Café! We hope to see you again soon.\n");
}

int main() {
    MenuItem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Sandwich", 5.00},
        {"Salad", 4.50},
        {"Juice", 3.00}
    };

    int choices[MAX_ITEMS] = {0};
    int input;
    int count = 0;

    displayMenu(menu, sizeof(menu) / sizeof(menu[0]));

    while (count < MAX_ITEMS) {
        printf("Your choice (0 to complete the order): ");
        scanf("%d", &input);
        
        if (input == 0) {
            break;
        } else if (input > 0 && input <= sizeof(menu) / sizeof(menu[0])) {
            choices[count] = input;
            count++;
        } else {
            printf("Please select a valid menu item.\n");
        }
    }

    float total = calculateTotal(choices, menu, sizeof(menu) / sizeof(menu[0]));
    
    generateReceipt(choices, menu, sizeof(menu) / sizeof(menu[0]), total);

    return 0;
}