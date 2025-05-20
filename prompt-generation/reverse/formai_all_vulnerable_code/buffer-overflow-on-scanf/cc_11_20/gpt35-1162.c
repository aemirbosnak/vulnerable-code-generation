//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include<stdio.h>
#include<stdlib.h>

void main(){
    int choice=0, quantity=0, subtotal=0, total=0, discount=0, grandTotal=0;
    printf("Welcome to the Curious Cafe Bill System!\n");

    do{
        printf("Please choose an item from our menu:\n");
        printf("1. Espresso\t\t120\n");
        printf("2. Cappuccino\t\t150\n");
        printf("3. Latte\t\t180\n");
        printf("4. Mocha\t\t200\n");
        printf("5. Americano\t\t100\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                subtotal = quantity * 120;
                printf("\nSubtotal: %d\n", subtotal);
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                subtotal = quantity * 150;
                printf("\nSubtotal: %d\n", subtotal);
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                subtotal = quantity * 180;
                printf("\nSubtotal: %d\n", subtotal);
                break;
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                subtotal = quantity * 200;
                printf("\nSubtotal: %d\n", subtotal);
                break;
            case 5:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                subtotal = quantity * 100;
                printf("\nSubtotal: %d\n", subtotal);
                break;
            case 6:
                printf("Thank you for visiting the Curious Cafe!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        total += subtotal;
        printf("\nTotal: %d\n", total);

        if(total >= 500 && total < 1000){
            discount = total * 0.05;
            printf("Discount: %d\n", discount);
            grandTotal = total - discount;
            printf("Grand Total: %d\n", grandTotal);
        } else if(total >= 1000){
            discount = total * 0.1;
            printf("Discount: %d\n", discount);
            grandTotal = total - discount;
            printf("Grand Total: %d\n", grandTotal);
        }

    } while(choice != 6);
}