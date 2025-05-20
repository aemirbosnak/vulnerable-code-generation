//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, qty, amount = 0, total = 0;
    
    printf("\n\n\t\t\tWelcome to the Cafe Billing System\n\n");
    
    printf("\t\t*Menu*\n");
    printf("\t1. Black Coffee\t\t$2\n");
    printf("\t2. Cappuccino\t\t$3\n");
    printf("\t3. Latte\t\t$4\n");
    printf("\t4. Espresso\t\t$5\n");
    printf("\t5. Exit\n\n");
    
    do
    {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                amount = qty * 2;
                printf("%d Black Coffee(s) @ $2 = $%d\n", qty, amount);
                total += amount;
                break;
                
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                amount = qty * 3;
                printf("%d Cappuccino(s) @ $3 = $%d\n", qty, amount);
                total += amount;
                break;
                
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                amount = qty * 4;
                printf("%d Latte(s) @ $4 = $%d\n", qty, amount);
                total += amount;
                break;
                
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                amount = qty * 5;
                printf("%d Espresso(s) @ $5 = $%d\n", qty, amount);
                total += amount;
                break;
                
            case 5:
                printf("Total bill is $%d. Thank you for visiting us!\n\n", total);
                break;
                
            default:
                printf("Please enter a valid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}