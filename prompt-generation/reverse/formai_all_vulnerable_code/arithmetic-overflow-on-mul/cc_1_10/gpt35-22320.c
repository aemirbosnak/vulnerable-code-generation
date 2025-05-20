//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include<stdio.h>

void calcTotal(int *);
int calcPrice(int, int);

int main() {
    int choice, quantity, total = 0;
    char menu[5][25] = {"Cappuccino", "Latte", "Espresso", "Macchiato", "Americano"};
    int price[5] = {120, 100, 80, 130, 90}; // prices in rupees
    
    printf("Welcome to Cafe Billing System!\n\n\n");

    do {
        for(int i = 0; i < 5; i++) {
            printf("%d. %s - Rs. %d\n", i+1, menu[i], price[i]);
        }

        printf("6. Exit\n\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 5) {
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);
            total += calcPrice(price[choice-1], quantity);
        }
        else if(choice == 6) {
            printf("\nTotal bill: %d\n\n", total);
            calcTotal(&total);
        }
        else {
            printf("\nInvalid choice! Try again.\n\n");
        }

    } while(choice != 6);

    return 0;
}

int calcPrice(int item_price, int quantity) {
    int price = item_price * quantity;
    printf("\nPrice for selected item is Rs. %d\n\n", price);
    return price;
}

void calcTotal(int *total) {
    float tax, grand_total;
    tax = (*total * 0.1);
    grand_total = (*total + tax);

    printf("Total amount before tax: %d\n", *total);
    printf("Tax (10 percent): %.2f\n", tax);
    printf("Grand total: %.2f\n", grand_total);
}