//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void displayMenu();
void placeOrder(int order[]);
void calculateBill(int order[]);

int main() {
    int order[5] = {0, 0, 0, 0, 0}; // array to store order count
    
    printf("*** Welcome to C Cafe ***\n");
    displayMenu(); // display menu options
    
    int choice;
    do {
        printf("\nEnter a choice (0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("\nGoodbye! Thank you for visiting C Cafe.\n");
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                placeOrder(order); // place order
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != 0);
    
    return 0;
}

// function to display menu options
void displayMenu() {
    printf("\nMenu\n");
    printf("1. Espresso - Rs. 100\n");
    printf("2. Cappuccino - Rs. 120\n");
    printf("3. Latte - Rs. 140\n");
    printf("4. Mocha - Rs. 160\n");
    printf("5. Hot Chocolate - Rs. 80\n");
    printf("Enter 0 to exit.\n");
}

// function to place order
void placeOrder(int order[]) {
    int n;
    printf("\nEnter the number of cups: ");
    scanf("%d", &n);
    if(n < 1) {
        printf("\nInvalid input. Please try again.\n");
    }
    else {
        int choice;
        do {
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    order[0] += n;
                    break;
                case 2:
                    order[1] += n;
                    break;
                case 3:
                    order[2] += n;
                    break;
                case 4:
                    order[3] += n;
                    break;
                case 5:
                    order[4] += n;
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
            
        } while(choice < 1 || choice > 5);
    }
}

// function to calculate and display bill
void calculateBill(int order[]) {
    int total = 0;
    printf("\nBill\n");
    if(order[0] > 0) {
        printf("Espresso      x%d   Rs. %d\n", order[0], order[0]*100);
        total += order[0]*100;
    }
    if(order[1] > 0) {
        printf("Cappuccino    x%d   Rs. %d\n", order[1], order[1]*120);
        total += order[1]*120;
    }
    if(order[2] > 0) {
        printf("Latte         x%d   Rs. %d\n", order[2], order[2]*140);
        total += order[2]*140;
    }
    if(order[3] > 0) {
        printf("Mocha         x%d   Rs. %d\n", order[3], order[3]*160);
        total += order[3]*160;
    }
    if(order[4] > 0) {
        printf("Hot Chocolate x%d   Rs. %d\n", order[4], order[4]*80);
        total += order[4]*80;
    }
    printf("\nTotal bill: Rs. %d\n", total);
}