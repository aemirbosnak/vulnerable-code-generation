//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include<stdio.h>
#include<string.h>

// Function to calculate the total bill
float calculateBill(int quantity, float price){
    float amount = quantity * price;
    if(amount>=5000){
        return amount - (amount*0.1);
    }
    else if(amount>=2000){
        return amount - (amount*0.05);
    }
    else{
        return amount;
    }
}

int main(){
    char itemName[30];
    int quantity;
    float price, totalBill = 0;
    char choice[5];
    
    printf("\t ---------- C CAFE BILLING SYSTEM ---------- \n\n");
    
    do{
        printf("Enter the name of the item: ");
        scanf("%s", itemName);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        printf("Enter the price per unit: ");
        scanf("%f", &price);
        
        // Calculation of total bill
        float itemBill = calculateBill(quantity, price);
        totalBill += itemBill;
        
        printf("\n%s x %d = Rs. %.2f\n\n", itemName, quantity, itemBill);
        
        printf("Do you want to add more items to the bill? (Y/N): ");
        scanf("%s", choice);
    }
    while(strcmp(choice, "Y")==0 || strcmp(choice, "y")==0);
    
    printf("\n\t ********** BILL ********** \n\n");
    printf("Total Bill : Rs. %.2f\n\n", totalBill);
    
    printf("\t --------------- Thank You! --------------- \n\n");
    return 0;
}