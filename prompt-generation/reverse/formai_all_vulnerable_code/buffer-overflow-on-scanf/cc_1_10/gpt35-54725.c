//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

int main(){
    int ch;
    float amt, total = 0;

    while(1){
        printf("\n********** Welcome to Cafe ******************\n");
        printf("1. Sandwich Rs 50\n");
        printf("2. Coffee Rs 30\n");
        printf("3. Tea Rs 20\n");
        printf("4. Bill\n");
        printf("\nEnter your choice : ");
        
        scanf("%d", &ch);

        switch(ch){
            case 1:
                total += 50;
                printf("Sandwich added to your bill\n");
                break;
            case 2:
                total += 30;
                printf("Coffee added to your bill\n");
                break;
            case 3:
                total += 20;
                printf("Tea added to your bill\n");
                break;
            case 4:
                printf("Your bill is Rs %.2f\n", total);
                printf("Enter amount paid : ");
                scanf("%f", &amt);

                if(amt < total){
                    printf("Amount paid is less than the total bill\n");
                }else{
                    printf("Amount paid is Rs %.2f\n", amt);
                    printf("Change : Rs %.2f\n", amt - total);
                    printf("Thank you for visiting Cafe\n");

                    total = 0;
                    
                    //exit the program after the bill is paid
                    exit(0);
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}