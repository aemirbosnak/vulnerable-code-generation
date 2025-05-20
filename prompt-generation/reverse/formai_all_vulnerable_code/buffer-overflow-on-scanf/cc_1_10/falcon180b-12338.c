//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

//structure for billing system
struct bill{
    char name[50];
    int quantity;
    float price;
    float discount;
    float total;
};

//function to calculate total
float calculate_total(struct bill b){
    float total;
    total = (b.quantity*b.price*(1-b.discount/100));
    return total;
}

//function to display bill
void display_bill(struct bill b){
    printf("\nname: %s",b.name);
    printf("\nquantity: %d",b.quantity);
    printf("\nprice: $%.2f",b.price);
    printf("\ndiscount: %d%%",b.discount);
    printf("\ntotal: $%.2f",b.total);
}

//main function
int main(){
    int choice;
    struct bill b;
    char name[50];
    int quantity;
    float price,discount;

    //menu driven program
    do{
        printf("\nwelcome to cafe billing system\n");
        printf("\n1.enter customer details\n");
        printf("2.display bill\n");
        printf("3.exit\n");
        printf("\nenter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nenter customer name: ");
                scanf("%s",b.name);
                printf("\nenter quantity: ");
                scanf("%d",&b.quantity);
                printf("\nenter price per unit: $");
                scanf("%f",&price);
                printf("\nenter discount percentage: ");
                scanf("%d",&discount);
                b.price = price;
                b.discount = discount;
                b.total = calculate_total(b);
                break;

            case 2:
                display_bill(b);
                break;

            case 3:
                printf("\nthank you for using cafe billing system\n");
                break;

            default:
                printf("\ninvalid choice\n");
        }

    }while(choice!=3);

    return 0;
}