//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include<stdio.h>

/* Struct for storing menu items */
typedef struct {
    char name[50];
    int price;
} MenuItem;

/* Function to display menu items */
void displayMenu(MenuItem menu[], int size){
    printf("Menu:\n");
    for(int i=0; i<size; i++){
        printf("%s \t $%d\n", menu[i].name, menu[i].price);
    }
}

/* Function for ordering menu items */
void orderItem(MenuItem menu[], int size, int quantity[], int orderSize){
    int orderNum, qty;
    printf("Enter the menu item number you want to order: ");
    scanf("%d", &orderNum);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for(int i=0; i<size; i++){
        if(i == orderNum-1){
            quantity[orderSize] = qty;
            printf("%d %s ordered\n", qty, menu[i].name);
        }
    }
}

/* Function to calculate bill */
void calculateBill(MenuItem menu[], int size, int quantity[], int orderSize){
    int total = 0;
    printf("Order Summary:\n");
    for(int i=0; i<orderSize; i++){
        printf("%d %s \t $%d\n", quantity[i], menu[i].name, menu[i].price);
        total += quantity[i] * menu[i].price;
    }
    printf("Total bill: $%d\n", total);
}

int main(){
    int choice, orderSize = 0;
    char repeat = 'y';
    MenuItem menu[] = {
        {"Coffee", 3},
        {"Tea", 2},
        {"Sandwich", 5},
        {"Muffin", 2},
        {"Cake", 6}
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int quantity[size];

    for(int i=0; i<size; i++){
        quantity[i] = 0;
    }

    printf("Welcome to Cafe Billing System!\n");

    do {
        printf("\n");
        displayMenu(menu, size);
        printf("\n1. Order Item\n2. Calculate Bill\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                orderItem(menu, size, quantity, orderSize);
                orderSize++;
                break;
            case 2:
                calculateBill(menu, size, quantity, orderSize);
                break;
            case 3:
                repeat = 'n';
                printf("Thank you for using Cafe Billing System!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(repeat == 'y');

    return 0;
}