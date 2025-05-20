//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Function prototypes
void DisplayMenu();
void GetItemDetails();
void CalculatePrice();
void DisplayBill();

// Variable declarations
int choice, quantity;
float price, total_amount = 0;

int main(){
    printf("Welcome to the C Cafe Billing System!\n\n");
    DisplayMenu();
    GetItemDetails();
    CalculatePrice();
    DisplayBill();
    return 0;
}

// Function to display the menu
void DisplayMenu(){
    printf("Menu\n");
    printf("----\n");
    printf("1. Coffee    - Rs. 50.00\n");
    printf("2. Tea       - Rs. 20.00\n");
    printf("3. Sandwich  - Rs. 100.00\n");
    printf("4. Cake      - Rs. 150.00\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
}

// Function to get the item details
void GetItemDetails(){
    if(choice >= 1 && choice <= 4){
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
    }
}

// Function to calculate the price
void CalculatePrice(){
    switch(choice){
        case 1:
            price = 50.00;
            total_amount = price * quantity;
            break;
        case 2:
            price = 20.00;
            total_amount = price * quantity;
            break;
        case 3:
            price = 100.00;
            total_amount = price * quantity;
            break;
        case 4:
            price = 150.00;
            total_amount = price * quantity;
            break;
        case 5:
            printf("\nThank you for using C Cafe Billing System!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
            DisplayMenu();
            GetItemDetails();
            CalculatePrice();
    }
}

// Function to display the bill
void DisplayBill(){
    printf("\nBill\n");
    printf("----\n");
    switch(choice){
        case 1:
            printf("Coffee\t\t%.2f x %d\t= Rs. %.2f\n", price, quantity, total_amount);
            break;
        case 2:
            printf("Tea\t\t%.2f x %d\t= Rs. %.2f\n", price, quantity, total_amount);
            break;
        case 3:
            printf("Sandwich\t%.2f x %d\t= Rs. %.2f\n", price, quantity, total_amount);
            break;
        case 4:
            printf("Cake\t\t%.2f x %d\t= Rs. %.2f\n", price, quantity, total_amount);
            break;
    }
    printf("\nTotal Amount\t\t\t= Rs. %.2f", total_amount);
    printf("\n\nThank you for using C Cafe Billing System!");
}