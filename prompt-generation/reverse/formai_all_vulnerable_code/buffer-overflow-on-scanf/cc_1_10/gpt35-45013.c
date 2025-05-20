//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CafeItem{
    char name[20];
    int price;
};

struct OrderItem{
    char name[20];
    int quantity;
};

struct CafeItem menu[] = {
    {"Coffee", 50},
    {"Tea", 30},
    {"Sandwich", 70},
    {"Burger", 100},
    {"Maggie", 60}
};

int calculateBill(struct OrderItem order[], int count){
    int totalBill = 0;
    for(int i=0;i<count;i++){
        for(int j=0;j<5;j++){
            if(strcmp(order[i].name, menu[j].name)==0){
                totalBill += order[i].quantity * menu[j].price;
            }
        }
    }
    return totalBill;
}

void displayMenu(){
    printf("******* Cafe Menu *******\n\n");
    printf("1. Coffee - Rs. 50\n");
    printf("2. Tea - Rs. 30\n");
    printf("3. Sandwich - Rs. 70\n");
    printf("4. Burger - Rs. 100\n");
    printf("5. Maggie - Rs. 60\n\n");
}

void makeOrder(struct OrderItem order[], int *count){
    char itemName[20];
    int itemQuantity;
    printf("Enter the name of the item you want to order: ");
    scanf("%s", itemName);
    printf("Enter the quantity: ");
    scanf("%d", &itemQuantity);

    strcpy(order[*count].name, itemName);
    order[*count].quantity = itemQuantity;

    (*count)++;
}

void printBill(struct OrderItem order[], int count){
    printf("\n\n******* Your Bill *******\n\n");
    for(int i=0;i<count;i++){
        printf("%d x %s - Rs. %d\n", order[i].quantity, order[i].name, order[i].quantity*menu[i].price);
    }
    printf("\nTotal: Rs. %d\n\n", calculateBill(order, count));
}

int main(){

    printf("\n\n********** Welcome to Happy Cafe! **********\n\n");

    int choice;
    struct OrderItem order[20];
    int count = 0;

    printf("Please select an option:\n");
    printf("1. Display Menu\n");
    printf("2. Make an Order\n");
    printf("3. Print Bill\n");
    printf("4. Exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayMenu();
                break;
            case 2:
                makeOrder(order, &count);
                break;
            case 3:
                printBill(order, count);
                break;
            case 4:
                printf("\n\n********** Thank you for visiting Happy Cafe! **********\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    }while(choice!=4);

    return 0;
}