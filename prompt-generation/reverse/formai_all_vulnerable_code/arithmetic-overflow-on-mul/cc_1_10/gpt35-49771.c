//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include<stdio.h>
#include<string.h>

struct item{
    char name[100];
    int price;
};

int main(){
    // Initializing the menu items
    struct item menu[]={
        {"Coffee",30},
        {"Tea",20},
        {"Sandwich",50},
        {"Burger",70},
        {"French Fries",40},
        {"Muffin",25},
        {"Cake",80}
    };
    
    int option = 0, quantity = 0;
    int total = 0;
    char choice = 'y';

    // Welcome message
    printf("\n Welcome to the Cafe Billing System! \n");

    while(choice == 'y'){
        // Displaying the menu
        printf("\n Menu: \n");
        for(int i=0; i<7; i++){
            printf("%d. %s - Rs.%d\n", i+1, menu[i].name, menu[i].price);
        }

        // Asking the user for order details
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        //Adding the order to the bill
        total += menu[option-1].price * quantity;
        printf("\nTotal bill so far: Rs.%d", total);

        // Asking the user if they want to add more to the bill
        printf("\nDo you want to add more items to the bill? (y/n)");
        scanf(" %c", &choice);
    }

    // Displaying the final bill
    printf("\n Your total bill is Rs.%d\n", total);
    printf("Thank you for visiting the cafe. Have a nice day!");

    return 0;
}