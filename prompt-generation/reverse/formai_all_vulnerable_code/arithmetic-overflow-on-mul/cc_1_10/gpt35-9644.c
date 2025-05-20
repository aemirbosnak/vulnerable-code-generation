//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main(){
    float principal_amount;
    float interest_rate;
    float monthly_payment;
    int years;

    //Get user input
    printf("Enter the principal amount: ");
    scanf("%f",&principal_amount);
    printf("Enter the interest rate: ");
    scanf("%f",&interest_rate);
    printf("Enter the monthly payment: ");
    scanf("%f",&monthly_payment);
    printf("Enter the number of years: ");
    scanf("%d",&years);

    //Calculate the monthly interest rate
    float monthly_interest_rate = interest_rate/1200;

    //Calculate the total number of payments
    int total_payments = years * 12;

    //Calculate the remaining balance after each payment
    while(total_payments > 0){
        float remaining_balance = principal_amount;
        for(int i = 1; i <= total_payments; i++){
            remaining_balance = remaining_balance * (1 + monthly_interest_rate) - monthly_payment;
            if(remaining_balance < 0){
                remaining_balance = 0;
            }
        }

        //Check if the remaining balance is close enough to zero
        if(fabs(remaining_balance) < 0.01){
            printf("You will pay off your loan in %d years\n",years);
            printf("Your monthly payment will be $%.2f\n",monthly_payment);

            //Calculate the total paid over the course of the loan
            float total_paid = monthly_payment * total_payments;
            printf("The total amount you will pay is $%.2f\n",total_paid);
            break;
        }

        //If the remaining balance is not close enough to zero, modify the monthly payment
        if(remaining_balance > 0){
            monthly_payment += 0.01;
        }
        else{
            monthly_payment -= 0.01;
        }

        //Recalculate the total payments
        total_payments = years * 12;
    }

    return 0;
}