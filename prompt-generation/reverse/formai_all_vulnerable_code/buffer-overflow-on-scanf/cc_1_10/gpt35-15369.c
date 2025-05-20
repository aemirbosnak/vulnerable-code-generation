//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to validate user input
int validateInput(char input[]){
    int length = strlen(input);

    // Iterate over each character of input to check if it's a digit
    for(int i=0;i<length;i++){
        if(!isdigit(input[i])){
            return 0; // If non-digit character is encountered, return 0
        }
    }

    return 1; // If all characters are digits, return 1
}

int main(){
    char choice[100];
    int qty, totalPrice, totalQty = 0, billNo = 1001;

    while(1){
        printf("\n\nWelcome to The Puzzling Cafe!");
        printf("\n\n1. Place Order");
        printf("\n2. Generate Bill");
        printf("\n3. Exit");
        printf("\nEnter Your Choice: ");

        scanf("%s", choice);

        // Validate user input
        if(!validateInput(choice)){
            printf("\nInvalid Choice!\n");
            continue;
        }

        // Convert choice string to integer
        int option = atoi(choice);

        switch(option){
            case 1:
                printf("\nEnter Quantity: ");
                scanf("%d", &qty);

                // Validate quantity input
                if(qty <= 0){
                    printf("\nInvalid Quantity!\n");
                    continue;
                }

                totalQty += qty; // Add quantity to total quantity

                printf("\nOrder Placed Successfully!\n");
                break;

            case 2:
                if(totalQty == 0){
                    printf("\nNo Orders Placed Yet!\n");
                    continue;
                }

                totalPrice = totalQty * 50; // Calculate total price

                printf("\nPrinting Bill...");
                printf("\n\n---------------------------------------");
                printf("\n           The Puzzling Cafe           ");
                printf("\n              Bill No: %d              ", billNo++);
                printf("\n---------------------------------------");
                printf("\nItem                     Qty    Price  ");
                printf("\n---------------------------------------");
                printf("\nCoffee                   %d     %d     ", totalQty, totalPrice);
                printf("\n---------------------------------------");
                printf("\nThanks for Visiting The Puzzling Cafe!");

                totalQty = 0; // Reset total quantity
                break;

            case 3:
                printf("\nThanks for Visiting The Puzzling Cafe!");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}