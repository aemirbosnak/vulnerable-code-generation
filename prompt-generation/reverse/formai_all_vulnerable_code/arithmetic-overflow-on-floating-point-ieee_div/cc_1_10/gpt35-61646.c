//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// function to capitalize the input string
void capitalize(char* str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}

// function to update the stock price
void update_price(float* price){
    float change, percentage;
    printf("Enter today's change in price: ");
    scanf("%f", &change);
    percentage = (change / *price) * 100;
    *price += change;
    printf("Today's price change: %.2f (%.2f%%)\n", change, percentage);
}

// function to display the stock information
void display_info(char* name, float price){
    printf("Stock Name: %s\n", name);
    printf("Price: $%.2f\n", price);
}

int main(){
    char name[20];
    float price;
    
    printf("Enter name of the stock: ");
    scanf("%s", name);
    capitalize(name);
    
    printf("Enter the initial price: ");
    scanf("%f", &price);
    
    printf("\n");
    display_info(name, price);
    
    int choice;
    do{
        printf("\n1. Update Price\n");
        printf("2. Display Information\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                update_price(&price);
                break;
            
            case 2:
                display_info(name, price);
                break;
                
            case 3:
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 3);
    
    return 0;
}