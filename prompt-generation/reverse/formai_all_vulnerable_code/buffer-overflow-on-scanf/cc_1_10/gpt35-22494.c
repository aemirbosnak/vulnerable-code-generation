//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include<stdio.h>

// Global variables
int menu[] = {0, 50, 70, 80, 60}; // storing prices of different items in the menu
int quantity[5] = {0, 0, 0, 0, 0}; // Initializing with 0, to keep track of quantity ordered
int total_items = 0;
float total_bill = 0.0;


void display_menu(){
    printf("\n\t\t\tWelcome to C Cafe\n");
    printf("\nMenu:\n");
    printf("1. Espresso - Rs.50\n");
    printf("2. Cappuccino - Rs.70\n");
    printf("3. Latte - Rs.80\n");
    printf("4. Hot Chocolate - Rs.60\n");
    printf("Press 0 to exit\n");
    printf("\n");
}


void order(){
    int item_number, item_quantity;
    do{
        printf("Enter item number (0 to exit): ");
        scanf("%d", &item_number);
        if(item_number <0 || item_number >4){
            printf("Invalid input. Please enter a valid item number!\n");
        }else if(item_number !=0){
            printf("Enter quantity: ");
            scanf("%d", &item_quantity);
            quantity[item_number] += item_quantity; //keeping track of quantity of each item ordered
            total_items += item_quantity; // keeping track of total number of items ordered
        }
    }while(item_number !=0);
}


void generate_bill(){
    printf("\n\n\t\t\tBill\n");
    printf("\n******************************");
    printf("\nItem\tQuantity\tPrice");
    printf("\n******************************");
    for(int i=1; i<5; i++){
        if(quantity[i]>0){
            printf("\n%d\t%d\t\tRs. %.2f", i, quantity[i], menu[i]*(float)quantity[i]);
            total_bill += (float)menu[i]*quantity[i]; // Keeping track of total bill amount
        }
    }
    printf("\n******************************");
    printf("\nTotal Items: %d\n", total_items);
    printf("Total Bill: Rs. %.2f\n", total_bill);
    printf("******************************\n\n");
}


int main(){
    display_menu();
    order();
    generate_bill();
    printf("Thank you for choosing C Cafe. Visit again!\n");
    return 0;
}