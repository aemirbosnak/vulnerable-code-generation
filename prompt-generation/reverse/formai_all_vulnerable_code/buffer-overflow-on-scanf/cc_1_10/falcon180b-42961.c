//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>

// Function to calculate total bill amount
float calculateBill(int items, float price) {
    float bill = 0.0;
    for(int i=1; i<=items; i++) {
        bill += price;
    }
    return bill;
}

// Function to display menu
void displayMenu() {
    printf("\nWelcome to the C Cafe!\n");
    printf("Our menu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.75\n");
    printf("3. Sandwich - $4.25\n");
    printf("4. Cake - $3.50\n");
    printf("5. Exit\n");
}

// Function to take order
void takeOrder() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou ordered a coffee for $2.50.\n");
            break;
        case 2:
            printf("\nYou ordered a tea for $1.75.\n");
            break;
        case 3:
            printf("\nYou ordered a sandwich for $4.25.\n");
            break;
        case 4:
            printf("\nYou ordered a cake for $3.50.\n");
            break;
        case 5:
            printf("\nThank you for visiting the C Cafe! Have a nice day!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
}

// Main function
int main() {
    int choice, items;
    float price, bill;

    do {
        displayMenu();
        takeOrder();

        if(choice!= 5) {
            printf("\nHow many %s do you want? ", (choice==1)?"coffee":"item");
            scanf("%d", &items);
            price = (choice==1)?2.50:4.25; // Assuming cake and sandwich have same price
            bill = calculateBill(items, price);
            printf("\nYour total bill is $%.2f.\n", bill);
        }
    } while(choice!= 5);

    return 0;
}