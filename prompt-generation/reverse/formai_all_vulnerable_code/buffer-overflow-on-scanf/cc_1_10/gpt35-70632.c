//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10

struct Menu{
    char item_name[20];
    int price;
};

struct Order{
    char item_ordered[20];
    int quantity;
    int total_price;
};

int main(){
    struct Menu menu[MAX_SIZE];
    struct Order order[MAX_SIZE];
    int choice, count=0, quantity=0, total_price=0, i=0, j=0;
    char item_name[20];
    int flag=0;

    menu[0] = (struct Menu){"Coffee", 50};
    menu[1] = (struct Menu){"Tea", 40};
    menu[2] = (struct Menu){"Sandwich", 80};
    menu[3] = (struct Menu){"Burger", 100};

    printf("\t\tC Cafe Billing System\n\n");
    while(1){
        printf("1. Place Order\n");
        printf("2. View Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                flag=0;
                printf("\nEnter the item to be ordered: ");
                scanf("%s", item_name);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);

                for(i=0; i<MAX_SIZE; i++){
                    if(strcmp(menu[i].item_name, item_name)==0){
                        total_price = quantity * menu[i].price;
                        strcpy(order[j].item_ordered, item_name);
                        order[j].quantity = quantity;
                        order[j].total_price = total_price;
                        count++;
                        j++;
                        printf("\nOrder placed successfully!\n\n");
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    printf("\nItem not found in the menu.\n\n");
                }
                break;

            case 2:
                if(count==0){
                    printf("\nNo orders placed yet.\n\n");
                }
                else{
                    printf("\nOrder Details\n\n");
                    printf("S.No.\tItem\t\tQuantity\tPrice\n");
                    for(i=0; i<count; i++){
                        printf("%d\t%s\t\t%d\t\t%d\n", i+1, order[i].item_ordered, order[i].quantity, order[i].total_price);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\nThank you for using C Cafe Billing System.\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n\n");
        }
    }

    return 0;
}