//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the C Cafe\n\n");

    int choice, quantity;
    float itemPrice, total = 0;

    printf("Menu:\n");
    printf("1. Coffee - Rs. 50\n");
    printf("2. Tea - Rs. 20\n");
    printf("3. Sandwich - Rs. 70\n");
    printf("4. Pizza - Rs. 150\n");
    printf("5. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5){
            printf("Total: %0.2f\n", total);
            printf("Thank you for visiting C Cafe!\n");
            exit(0);
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        switch(choice){
            case 1:
                itemPrice = 50 * quantity;
                printf("Coffee x %d: %0.2f\n", quantity, itemPrice);
                break;
            case 2:
                itemPrice = 20 * quantity;
                printf("Tea x %d: %0.2f\n", quantity, itemPrice);
                break;
            case 3:
                itemPrice = 70 * quantity;
                printf("Sandwich x %d: %0.2f\n", quantity, itemPrice);
                break;
            case 4:
                itemPrice = 150 * quantity;
                printf("Pizza x %d: %0.2f\n", quantity, itemPrice);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        total += itemPrice;
    }

    return 0;
}