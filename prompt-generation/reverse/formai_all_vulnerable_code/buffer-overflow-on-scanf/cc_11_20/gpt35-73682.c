//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int choice, quantity, price, total = 0, item_no = 1;
    char item[20];

    printf("***************************************************\n");
    printf("*           WELCOME TO CAFE APOCALYPSE            *\n");
    printf("***************************************************\n");

    while(1){
        printf("\n");
        printf("***************************************************\n");
        printf("*                   MENU                          *\n");
        printf("***************************************************\n");
        printf("*  ITEM             |      PRICE                  *\n");
        printf("***************************************************\n");
        printf("*  1. Coffee        |      50 Rs.                 *\n");
        printf("*  2. Tea           |      40 Rs.                 *\n");
        printf("*  3. Sandwich      |      80 Rs.                 *\n");
        printf("*  4. Noodles       |      100 Rs.                *\n");
        printf("*  5. Soup          |      60 Rs.                 *\n");
        printf("*  6. Bill          |                              *\n");
        printf("*  7. Exit          |                              *\n");
        printf("***************************************************\n");    

        // user input for choice
        printf("\nEnter your choice (1-7) : ");
        scanf("%d", &choice);

        // checking for valid input
        if(choice<1 || choice>7){
            printf("\nInvalid Input! Please enter a valid option.\n");
            continue;
        }

        // exit option
        if(choice==7){
            printf("\nThank you for your visit!\n");
            break;
        }

        if(choice != 6){
            // user input for quantity
            printf("\nEnter the quantity : ");
            scanf("%d", &quantity);
        }   

        // updating total price
        switch(choice){
            case 1:
                price = 50;
                strcpy(item, "Coffee");
                break;

            case 2:
                price = 40;
                strcpy(item, "Tea");
                break;

            case 3:
                price = 80;
                strcpy(item, "Sandwich");
                break;

            case 4:
                price = 100;
                strcpy(item, "Noodles");
                break;

            case 5:
                price = 60;
                strcpy(item, "Soup");
                break;

            default:
                break;
        }

        if(choice != 6 && choice != 7){
            printf("\n**** SUMMARY ****\n");
            printf("Item no. : %d\n", item_no);
            printf("Item : %s\n", item);
            printf("Quantity : %d\n", quantity);
            printf("Price : %d Rs.\n", price);
            total += price * quantity;
            item_no++;
        }

        if(choice == 6){
            printf("\n**** BILL ****\n");
            printf("Total : %d Rs.\n", total);
        }
    }

    return 0;
}