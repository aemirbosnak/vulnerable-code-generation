//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main() {
    int count=0, ch, i, qty;
    float amt, total=0, price;
    char cont;

    printf("\t\t=============================\n");
    printf("\t\t   Welcome to C Cafe Billing\n");
    printf("\t\t=============================\n\n");

    do {
        count++;
        printf("Enter item %d: ", count);
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                price=50;
                printf("Item: Cappuccino\nPrice: Rs. %.2f\n", price);
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amt=price*qty;
                printf("Amount: Rs. %.2f\n", amt);
                total+=amt;
                break;

            case 2:
                price=40;
                printf("Item: Espresso\nPrice: Rs. %.2f\n", price);
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amt=price*qty;
                printf("Amount: Rs. %.2f\n", amt);
                total+=amt;
                break;

            case 3:
                price=20;
                printf("Item: Tea\nPrice: Rs. %.2f\n", price);
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amt=price*qty;
                printf("Amount: Rs. %.2f\n", amt);
                total+=amt;
                break;

            case 4:
                price=30;
                printf("Item: Coffee\nPrice: Rs. %.2f\n", price);
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amt=price*qty;
                printf("Amount: Rs. %.2f\n", amt);
                total+=amt;
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you want to order another item? (y/n): ");
        scanf(" %c", &cont);
        printf("\n");

    } while(cont=='y' || cont=='Y');

    printf("------------------------------------------\n");
    printf("\t\tTotal bill: Rs. %.2f\n", total);
    printf("------------------------------------------\n");
    printf("\t\tThank you for visiting C Cafe!\n");
    printf("\t\tHave a nice day :)\n");

    return 0;
}