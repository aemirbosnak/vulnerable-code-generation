//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#define MAX_ORDERS 100

struct MenuItems{
    char item_name[50];
    float item_price;
    int item_qty;
};

struct CafeOrders{
    int order_no;
    float total_due;
    struct MenuItems items[MAX_ORDERS];
};

float calculate_total(struct MenuItems *items, int num_items){
    float total = 0;
    for(int i=0; i<num_items; i++){
        total += items[i].item_price * items[i].item_qty;
    }
    return total;
}

void print_order(struct CafeOrders order){
    printf("\n---- Order No. %d ----\n", order.order_no);
    for(int i=0; i<MAX_ORDERS; i++){
        if(order.items[i].item_qty > 0){
            printf("%-20s$%.2f x %d\n", order.items[i].item_name, order.items[i].item_price, order.items[i].item_qty);
        }
    }
    printf("\nTotal Due: $%.2f\n", order.total_due);
}

int main(){
    struct CafeOrders orders[MAX_ORDERS];
    int num_orders = 0;

    int menu_choice = -1;
    while(menu_choice != 0){
        printf("Please select from the following options:\n");
        printf("1. Add new order\n");
        printf("2. View all orders\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice){
            case 1:{
                struct CafeOrders new_order;
                new_order.order_no = num_orders + 1;

                int num_items = 0;
                float total = 0.0;
                char answer = 'y';
                while(answer == 'y'){
                    printf("Enter item name: ");
                    scanf(" %[^\n]s", new_order.items[num_items].item_name);

                    printf("Enter item price: ");
                    scanf("%f", &new_order.items[num_items].item_price);

                    printf("Enter item quantity: ");
                    scanf("%d", &new_order.items[num_items].item_qty);

                    total += new_order.items[num_items].item_price * new_order.items[num_items].item_qty;

                    printf("Do you want to add another item? (y/n)\n");
                    scanf(" %c", &answer);

                    num_items++;
                }

                new_order.total_due = total;
                orders[num_orders++] = new_order;
                break;
            }
            case 2:{
                for(int i=0; i<num_orders; i++){
                    print_order(orders[i]);
                }
                break;
            }
            case 0:{
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            }
            default:{
                printf("Invalid selection! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}