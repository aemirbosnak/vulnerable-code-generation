//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include<stdio.h>
int main()
{
    printf("Welcome to Cafe Wacko!\n\n");
    printf("Menu\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Cake\n");
    printf("5. Exit\n\n");

    int option, coffee_qty = 0, tea_qty = 0, sandwich_qty = 0, cake_qty = 0;
    float coffee_price = 1.5, tea_price = 1.0, sandwich_price = 3.0, cake_price = 2.5;
    float total_bill = 0.0;

    do {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter quantity of coffee: ");
                scanf("%d", &coffee_qty);
                total_bill += coffee_qty * coffee_price;
                printf("Added %d cups of coffee to your bill!\n\n", coffee_qty);
                break;

            case 2:
                printf("Enter quantity of tea: ");
                scanf("%d", &tea_qty);
                total_bill += tea_qty * tea_price;
                printf("Added %d cups of tea to your bill!\n\n", tea_qty);
                break;

            case 3:
                printf("Enter quantity of sandwich: ");
                scanf("%d", &sandwich_qty);
                total_bill += sandwich_qty * sandwich_price;
                printf("Added %d sandwich to your bill!\n\n", sandwich_qty);
                break;

            case 4:
                printf("Enter quantity of cake: ");
                scanf("%d", &cake_qty);
                total_bill += cake_qty * cake_price;
                printf("Added %d pieces of cake to your bill!\n\n", cake_qty);
                break;

            case 5:
                printf("Thank you for visiting Cafe Wacko!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        } 

    } while(option != 5);

    printf("Total bill: $%.2f\n", total_bill);

    return 0;
}