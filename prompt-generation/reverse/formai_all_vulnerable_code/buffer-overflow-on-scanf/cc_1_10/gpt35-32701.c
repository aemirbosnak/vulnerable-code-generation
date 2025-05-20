//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SIZE 100
#define MIN_SIZE 1
#define COFFEE_PRICE 80
#define TEA_PRICE 50
#define PASTRY_PRICE 70
#define TAX_RATE 0.12

typedef struct order{
    int id;
    char item[20];
    int quantity;
    int price;
} Order;

typedef struct bill{
    char customerName[50];
    time_t orderTime;
    Order orders[MAX_SIZE];
    int numItems;
    float subtotal;
    float tax;
    float total;
} Bill;

void printHeader(){
    printf("\n**************************************************\n");
    printf("*   WELCOME TO TECH CAFE BILLING SYSTEM  *");
    printf("\n**************************************************\n\n");
}

void printMenu(){
    printf("Coffee          - Rs. %d\n", COFFEE_PRICE);
    printf("Tea             - Rs. %d\n", TEA_PRICE);
    printf("Pastry          - Rs. %d\n", PASTRY_PRICE);
    printf("\n");
}

void printOrder(Order order){
    printf("%-2d %-10s %-2d %-2d\n", order.id, order.item, order.quantity, order.price);
}

void printBill(Bill bill){
    printf("\n");
    printf("**************************************************\n");
    printf("*                 TECH CAFE BILL                 *\n");
    printf("**************************************************\n");
    
    printf("\n");
    printf("Customer Name: %s\n", bill.customerName);
    printf("Order Time: %s", ctime(&bill.orderTime));
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|  ID |   Item   | Quantity |  Price  |\n");
    printf("--------------------------------------------------\n");
    for(int i=0; i<bill.numItems; i++){
        printOrder(bill.orders[i]);
    }
    printf("--------------------------------------------------\n");
    printf("|                                      | Total: Rs. %-6.2f |\n", bill.total);
    printf("**************************************************\n\n");
}

float calculateTotal(Bill bill){
    float subtotal = 0;
    for(int i=0; i<bill.numItems; i++){
        subtotal += bill.orders[i].price;
    }
    bill.subtotal = subtotal;
    bill.tax = subtotal * TAX_RATE;
    bill.total = subtotal + bill.tax;
    return bill.total;
}

Bill processOrder(char customerName[], int coffeeQty, int teaQty, int pastryQty){
    Bill bill;
    bill.orderTime = time(NULL);
    strcpy(bill.customerName, customerName);
    bill.numItems = 0;

    if(coffeeQty > 0){
        bill.orders[bill.numItems].id = bill.numItems+1;
        strcpy(bill.orders[bill.numItems].item, "Coffee");
        bill.orders[bill.numItems].quantity = coffeeQty;
        bill.orders[bill.numItems].price = COFFEE_PRICE*coffeeQty;
        bill.numItems++;
    }

    if(teaQty > 0){
        bill.orders[bill.numItems].id = bill.numItems+1;
        strcpy(bill.orders[bill.numItems].item, "Tea");
        bill.orders[bill.numItems].quantity = teaQty;
        bill.orders[bill.numItems].price = TEA_PRICE*teaQty;
        bill.numItems++;
    }

    if(pastryQty > 0){
        bill.orders[bill.numItems].id = bill.numItems+1;
        strcpy(bill.orders[bill.numItems].item, "Pastry");
        bill.orders[bill.numItems].quantity = pastryQty;
        bill.orders[bill.numItems].price = PASTRY_PRICE*pastryQty;
        bill.numItems++;
    }

    calculateTotal(bill);
    return bill;
}

int main(){
    printHeader();

    int coffeeQty, teaQty, pastryQty;
    char customerName[50];
    printf("Enter customer name: ");
    scanf("%[^\n]%*c", customerName);

    printf("\n");
    printf("Menu:\n");
    printMenu();
    
    printf("Enter quantity of Coffees: ");
    scanf("%d", &coffeeQty);
    printf("Enter quantity of Teas: ");
    scanf("%d", &teaQty);
    printf("Enter quantity of Pastries: ");
    scanf("%d", &pastryQty);

    if(coffeeQty <= MIN_SIZE && teaQty <= MIN_SIZE && pastryQty <= MIN_SIZE){
        printf("\nNo orders placed. Goodbye!\n");
        exit(0);
    }

    Bill bill = processOrder(customerName, coffeeQty, teaQty, pastryQty);
    printBill(bill);

    return 0;
}