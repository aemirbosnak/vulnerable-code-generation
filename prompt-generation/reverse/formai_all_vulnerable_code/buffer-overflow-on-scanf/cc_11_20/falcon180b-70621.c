//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 10
#define MAX_NAME 20
#define MAX_PRICE 10
#define QUANTITY_LIMIT 100

int main(){
    int choice, quantity;
    float price;
    char name[MAX_NAME];
    struct{
        char name[MAX_NAME];
        float price;
    }item[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Cafe Billing System\n");
    printf("1. Add an item\n");
    printf("2. View items\n");
    printf("3. Order an item\n");
    printf("4. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                if(num_items == MAX_ITEMS){
                    printf("Maximum number of items reached\n");
                    break;
                }

                printf("Enter the name of the item: ");
                scanf("%s", item[num_items].name);

                printf("Enter the price of the item: ");
                scanf("%f", &item[num_items].price);

                num_items++;
                break;
            }

            case 2:{
                printf("Items in the menu:\n");
                for(int i=0; i<num_items; i++){
                    printf("%s - %.2f\n", item[i].name, item[i].price);
                }
                break;
            }

            case 3:{
                printf("Enter the name of the item you want to order: ");
                scanf("%s", name);

                for(int i=0; i<num_items; i++){
                    if(strcmp(name, item[i].name) == 0){
                        printf("Enter the quantity of %s you want to order: ", name);
                        scanf("%d", &quantity);

                        if(quantity > QUANTITY_LIMIT){
                            printf("Quantity limit exceeded\n");
                            break;
                        }

                        float total_price = item[i].price * quantity;
                        printf("Total price for %d units of %s is %.2f\n", quantity, name, total_price);
                        break;
                    }
                }

                break;
            }

            case 4:{
                printf("Exiting...\n");
                exit(0);
            }

            default:{
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}