//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <string.h>

//Struct to store the orders
struct Order{
    char name[50];
    int quantity;
    float price;
    float total;
};

//Function to calculate the total order cost
float calculateTotal(int quantity, float price){
    return quantity * price;
}

//Function to display the final invoice to the customer
void displayInvoice(struct Order orders[], int count, float totalBill){
    printf("\n\t\t\t\tCafe Billing System\n");
    printf("_______________________________________________________________________________\n");
    printf("|\t\t\t\t\t\t\t\t|\n");
    printf("|\t\tName\t\tQuantity\t\tPrice\t|\n");
    printf("|______________________________________________________________________________|\n");
    for(int i=0; i<count; i++){
        printf("|\t\t%s\t\t", orders[i].name);
        printf("%d\t\t", orders[i].quantity);
        printf("%.2f\t\t|\n", orders[i].price);
    }
    printf("|______________________________________________________________________________|\n");
    printf("|\t\t\t\t\t\tTotal Bill: %.2f\t|\n", totalBill);
    printf("|______________________________________________________________________________|\n");
}

int main(){
    int orderCount = 0;
    struct Order orders[100];
    float totalBill = 0;

    //Displaying the menu
    printf("Welcome to Cafe Billing System\n");
    printf("Please select your order:\n");
    printf("1. Coffee - Rs. 50\n2. Tea - Rs. 20\n3. Sandwich - Rs. 80\n4. Burger - Rs. 120\n5. Exit\n");

    //Taking the orders until the customer exits
    while(1){
        int choice, quantity;
        char name[50];

        //Taking user input for the selected order
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice == 5){
            break;
        }

        //Assigning the order name and price based on selection
        switch(choice) {
            case 1:
                strcpy(name, "Coffee");
                quantity = 0;
                printf("Enter the number of cups of Coffee: ");
                scanf("%d", &quantity);
                orders[orderCount].price = 50;
                break;
            case 2:
                strcpy(name, "Tea");
                quantity = 0;
                printf("Enter the number of cups of Tea: ");
                scanf("%d", &quantity);
                orders[orderCount].price = 20;
                break;
            case 3:
                strcpy(name, "Sandwich");
                quantity = 0;
                printf("Enter the number of Sandwiches: ");
                scanf("%d", &quantity);
                orders[orderCount].price = 80;
                break;
            case 4:
                strcpy(name, "Burger");
                quantity = 0;
                printf("Enter the number of Burgers: ");
                scanf("%d", &quantity);
                orders[orderCount].price = 120;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        //Storing the order details in the struct
        strcpy(orders[orderCount].name, name);
        orders[orderCount].quantity = quantity;
        orders[orderCount].total = calculateTotal(quantity, orders[orderCount].price);

        //Updating the total bill
        totalBill += orders[orderCount].total;

        //Incrementing the order count
        orderCount++;
    }

    //Displaying the final invoice to the customer
    displayInvoice(orders, orderCount, totalBill);

    return 0;
}