//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>

struct item {
   char name[30];
   int quantity;
   float price;
} menu[10];

void printMenu(){
    printf("Menu\n");
    printf("-------------------------------------\n");
    printf("Name\t\tPrice\tQuantity\n");
    printf("-------------------------------------\n");
    for(int i = 0; i < 10; i++){
        printf("%s\t\t%.2f\t%d\n",menu[i].name, menu[i].price, menu[i].quantity);
    }
    printf("-------------------------------------\n");
}

void takeOrder(){
    int choice,qty;
    float total = 0;
    char ans = 'y';
    printf("Enter the item number and quantity\n");
    do{
        printf("Item Number: ");
        scanf("%d",&choice);
        if(choice > 10 || choice < 1){
            printf("Invalid Item Number. Try again.\n");
            continue;
        }
        printf("Quantity: ");
        scanf("%d",&qty);
        if(qty > menu[choice-1].quantity){
            printf("Insufficient Quantity. Try Again or enter another choice\n");
            continue;
        }
        printf("Do you want to add another item? (y/n)");
        fflush(stdin);
        scanf("%c",&ans);
        menu[choice-1].quantity -= qty;
        total += qty*menu[choice-1].price;
    }while(ans == 'y' || ans == 'Y');
    printf("Total Amount: %.2f\n",total);
}

void refillStock(){
    int choice,qty;
    printf("Enter the item number you want to refill: ");
    scanf("%d",&choice);
    printf("Enter the quantity: ");
    scanf("%d",&qty);
    menu[choice-1].quantity += qty;
    printf("Refilled successfully!\n");
}

int main(){
    for(int i=0; i < 10; i++){
        printf("Enter name of item %d: ",i+1);
        fflush(stdin);
        scanf("%[^\n]",&menu[i].name);
        printf("Enter the price: ");
        scanf("%f",&menu[i].price);
        printf("Enter the quantity: ");
        scanf("%d",&menu[i].quantity);
    }
    int choice;
    do{
        printf("Enter your choice:\n1. Print Menu\n2. Take Order\n3. Refill Stock\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printMenu();
                    break;
            case 2: takeOrder();
                    break;
            case 3: refillStock();
                    break;
            case 4: printf("Exiting...\n");
                    break;
            default: printf("Invalid Choice.\n");
        }
    }while(choice != 4);
    return 0;
}