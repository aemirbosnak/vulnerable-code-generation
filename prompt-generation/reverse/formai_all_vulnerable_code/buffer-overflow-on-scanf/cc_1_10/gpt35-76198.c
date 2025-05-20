//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include<stdio.h>
#include<string.h>

struct menu{
    char name[20];
    int price;
}m[20];

void printMenu(){
    printf("Cafe Menu\n");
    printf("-----------------------------\n");
    printf("Item Name\t\tPrice\n");
    printf("-----------------------------\n");

    for(int i=0;i<3;i++){
        printf("%s\t\t\t%d\n", m[i].name, m[i].price);
    }
}

void generateBill(int quantity[], int order[]){
    int total = 0;
    printf("\n\n");
    printf("-----------------------------\n");
    printf("Your Order Details\n");
    printf("-----------------------------\n");
    printf("Item\t\tQuantity\tPrice\n");

    for(int i=0;i<3;i++){
        if(quantity[i] > 0){
            total += quantity[i] * m[i].price;
            printf("%s\t\t%d\t\t%d\n", m[i].name, quantity[i], order[i]);
        }
    }

    printf("-----------------------------\n");
    printf("Total\t\t\t\t%d\n", total);
    printf("-----------------------------\n");

    if(total > 0){
        printf("Your bill has been generated, please pay to the counter\n");
    }
    else{
        printf("You have not purchased anything, please order something\n");
    }
}

int main(){
    strcpy(m[0].name, "Latte");
    m[0].price = 120;
    strcpy(m[1].name, "Cappuccino");
    m[1].price = 100;
    strcpy(m[2].name, "Mocha");
    m[2].price = 150;

    int quantity[3] = {0, 0, 0};
    int order[3] = {0, 0, 0};
    char choice;
    int itemCode, qty, amount;
    printf("\n\n");

    printf("Welcome to our Cafe!\n");
    printf("-----------------------------\n");
    printf("Do you want to see the Cafe Menu? (y/n): ");
    scanf("%c", &choice);

    if(choice == 'y' || choice == 'Y')
        printMenu();

    do{
        printf("\n\n");
        printf("-----------------------------\n");
        printf("What do you want to order? Enter the Item Code and Quantity: ");
        scanf("%d %d", &itemCode, &qty);

        switch(itemCode){
            case 1:
                quantity[0] += qty;
                order[0] += m[0].price * qty;
                break;
            case 2:
                quantity[1] += qty;
                order[1] += m[1].price * qty;
                break;
            case 3:
                quantity[2] += qty;
                order[2] += m[2].price * qty;
                break;
            default:
                printf("Invalid Item Code\n");
                break;
        }

        printf("Do you want to order anything else? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');

    generateBill(quantity, order);

    return 0;
}