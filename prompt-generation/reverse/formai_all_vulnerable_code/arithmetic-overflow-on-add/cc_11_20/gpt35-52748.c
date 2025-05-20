//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: random
#include<stdio.h>

struct cafeItem {
    char itemName[50];
    int itemPrice;
    int itemQuantity;
};

int main() {
    struct cafeItem menu[10] = {{"Coffee", 50, 0}, {"Tea", 30, 0}, {"Sandwich", 70, 0},
                                {"Burger", 100, 0}, {"Pizza", 200, 0}, {"French Fries", 50, 0},
                                {"Coke", 40, 0}, {"Mojito", 80, 0}, {"Cheese Cake", 120, 0}, 
                                {"Brownie", 80, 0}};
    int choice = 0;
    int totalAmt = 0;
    printf("Welcome to Cafe Java!\n");
    printf("************************\n");
    do {
        printf("\nMenu:\n");
        printf("No.\tItem Name\tItem Price\tItem Quantity\n");
        for (int i=0; i<10; i++) {
            printf("%d.\t%s\t%d\t\t%d\n", i+1, menu[i].itemName, menu[i].itemPrice, menu[i].itemQuantity);
        }
        printf("\nPlease select an option:\n");
        printf("1. Add Item to Order\n");
        printf("2. Remove Item from Order\n");
        printf("3. View Order\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter Item No. to Add: ");
                int itemNo;
                scanf("%d", &itemNo);
                if (itemNo<1 || itemNo>10) {
                    printf("Invalid Item Number.");
                }
                else {
                    printf("Enter Item Quantity: ");
                    int qty;
                    scanf("%d", &qty);
                    menu[itemNo-1].itemQuantity += qty;
                    printf("%d x %s added to Order.", qty, menu[itemNo-1].itemName);
                }
                break;
            case 2:
                printf("Enter Item No. to Remove: ");
                int rmItemNo;
                scanf("%d", &rmItemNo);
                if (rmItemNo<1 || rmItemNo>10 || menu[rmItemNo-1].itemQuantity == 0) {
                    printf("Invalid Item Number or Item not Found in Order.");
                }
                else {
                    printf("%d x %s removed from Order.", menu[rmItemNo-1].itemQuantity, menu[rmItemNo-1].itemName);
                    menu[rmItemNo-1].itemQuantity = 0;
                }
                break;
            case 3:
                printf("Current Order:\n");
                printf("Item Name\tItem Quantity\tItem Price\tTotal Price\n");
                for (int i=0; i<10; i++) {
                    int qty = menu[i].itemQuantity;
                    if (qty > 0) {
                        int price = menu[i].itemPrice;
                        int totalPrice = qty * price;
                        printf("%s\t%d\t\t%d\t\t%d\n", menu[i].itemName, qty, price, totalPrice);
                        totalAmt += totalPrice;
                    }
                }
                if (totalAmt>0) {
                    printf("\nTotal Amount Payable: %d\n", totalAmt);
                }
                else {
                    printf("\nYou have not ordered anything yet!");
                }
                break;
            case 4:
                printf("Thank you for choosing Cafe Java!");
                break;
            default:
                printf("Invalid Choice!");
                break;
        }
    } while (choice!=4);
    return 0;
}