//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include<stdio.h>
#include<string.h>

//initialize the global variables
float opening_price, closing_price, current_price;
char stock_name[20], change[10];

//function to calculate the change in percentage
float calculate_change(float opening, float closing){
    float change_in_price;
    change_in_price = closing - opening;
    float change_in_percentage;
    change_in_percentage = change_in_price/opening*100;
    return change_in_percentage;
}

int main(){
    //get the stock name
    printf("Enter the stock name: ");
    scanf("%s", stock_name);
    
    //get the opening price
    printf("Enter the opening price of %s: ", stock_name);
    scanf("%f", &opening_price);
    
    //get the current price
    printf("Enter the current price of %s: ", stock_name);
    scanf("%f", &current_price);
    
    //calculate the closing price based on current price
    closing_price = current_price;
    
    //calculate the change in percentage
    float change_in_percentage = calculate_change(opening_price, closing_price);
    
    //determine whether the change is positive or negative
    if(current_price > opening_price){
        strcpy(change, "positive");
    }
    else{
        strcpy(change, "negative");
    }
    
    //print the results
    printf("\n%s Stock Market Tracker\n\n", stock_name);
    printf("Opening Price: $%.2f\n", opening_price);
    printf("Current Price: $%.2f\n", current_price);
    printf("Closing Price: $%.2f\n", closing_price);
    printf("Change: %s %.2f%%\n", change, change_in_percentage);
    
    return 0;
}