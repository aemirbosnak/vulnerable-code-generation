//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include<stdio.h>

int main()
{
    //Declare Variables
    double total_bill;
    double discount;
    double tax;
    int bill_items;
    
    //Read in total bill amount
    printf("Please enter the total bill amount: ");
    scanf("%lf", &total_bill);
    
    //Calculate discount
    if (total_bill > 1000) {
        discount = total_bill * 0.10;
        total_bill = total_bill - discount;
    }
    
    //Calculate tax
    tax = total_bill * 0.08;
    total_bill = total_bill + tax;
    
    //Display bill breakdown
    printf("Bill Breakdown:\n");
    printf("Total bill amount: %.2lf\n", total_bill);
    printf("Discount applied: %.2lf\n", discount);
    printf("Tax amount: %.2lf\n", tax);
    printf("Final bill amount: %.2lf\n", total_bill);
    
    //Read in number of bill items
    printf("Please enter the number of bill items: ");
    scanf("%d", &bill_items);
    
    //Display bill items
    printf("Bill Items:\n");
    for (int i = 0; i < bill_items; i++) {
        printf("Item %d: %.2lf\n", i+1, total_bill / bill_items);
    }
    
    //Calculate and display bill summary
    printf("Bill Summary:\n");
    printf("Total bill amount: %.2lf\n", total_bill);
    printf("Discount applied: %.2lf\n", discount);
    printf("Tax amount: %.2lf\n", tax);
    printf("Final bill amount: %.2lf\n", total_bill);
    
    return 0;
}