//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

void main(){
    int table_num, food_choice, quantity, total_amount = 0;
    char food_name[50];
    
    printf("Welcome to Cafe Billing System\n");
    printf("Please enter your table number:\n");
    scanf("%d", &table_num);
    
    while(1){
        printf("\n");
        printf("Please select a food item:\n");
        printf("1. Coffee - Rs 50\n");
        printf("2. Sandwich - Rs 75\n");
        printf("3. Salad - Rs 100\n");
        printf("4. Pasta - Rs 120\n");
        printf("5. Exit\n");
        scanf("%d", &food_choice);
        
        if(food_choice == 5){
            printf("\n");
            printf("Your total amount is Rs %d\n", total_amount);
            printf("Thank you for using our Cafe Billing System\n");
            break;
        }
        
        printf("Please enter the quantity:\n");
        scanf("%d", &quantity);
        
        switch(food_choice){
            case 1:
                total_amount += 50 * quantity;
                strcpy(food_name, "Coffee");
                break;
            case 2:
                total_amount += 75 * quantity;
                strcpy(food_name, "Sandwich");
                break;
            case 3:
                total_amount += 100 * quantity;
                strcpy(food_name, "Salad");
                break;
            case 4:
                total_amount += 120 * quantity;
                strcpy(food_name, "Pasta");
                break;
            default:
                printf("Invalid food choice selected. Please try again.\n");
                continue;
        }
        
        printf("%d x %s added to your bill.\n", quantity, food_name);
    }
}