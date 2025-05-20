//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include<stdio.h>
#include<string.h>

struct menu{
    int id;
    char item_name[20];
    float price;
};

struct order{
    int order_id;
    int menu_id;
    int quantity;
};

int main(){
    struct menu items[10];
    struct order orders[20];
    int option;
    int menu_count = 0, order_count = 0;

    printf(" Welcome to The Unique C Cafe Billing System! \n");
    printf("-----------------------------\n");
    printf("Choose an option: \n");
    printf("1. Add item to menu. \n");
    printf("2. Place order. \n");
    printf("3. View menu. \n");
    printf("4. View orders. \n");
    printf("5. Exit. \n");

    do{
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:{
                printf("Add item to menu\n");

                printf("Enter item id: ");
                scanf("%d", &items[menu_count].id);

                printf("Enter item name: ");
                scanf("%s", items[menu_count].item_name);

                printf("Enter item price: ");
                scanf("%f", &items[menu_count].price);

                printf("Item added successfully!\n");

                menu_count++;

                break;
            }

            case 2:{
                printf("Place order\n");

                int menu_id, order_quantity;
                float total_price = 0;

                printf("Enter order id: ");
                scanf("%d", &orders[order_count].order_id);

                printf("Enter menu id: ");
                scanf("%d", &orders[order_count].menu_id);

                printf("Enter quantity: ");
                scanf("%d", &orders[order_count].quantity);

                for(int i = 0; i < menu_count; i++){
                    if(items[i].id == orders[order_count].menu_id){
                        total_price = items[i].price * orders[order_count].quantity;
                        break;
                    } 
                }

                printf("Total Price: Rs. %.2f\n", total_price);

                order_count++;

                break;
            }

            case 3:{
                printf("Menu\n");

                if(menu_count == 0){
                    printf("No items in menu. \n");
                }

                else{
                    printf("ID  NAME                PRICE \n");
                    printf("--------------------------------------------- \n");
                    for(int i = 0; i < menu_count; i++){
                        printf("%-3d %-19s Rs.%.2f \n", items[i].id, items[i].item_name, items[i].price);
                    }
                }

                printf("\n");

                break;
            }

            case 4:{
                printf("Orders\n");

                if(order_count == 0){
                    printf("No orders placed yet. \n");
                }

                else{
                    printf("ORDER ID  MENU ID  QUANTITY \n");
                    printf("-------------------------------- \n");
                    for(int i = 0; i < order_count; i++){
                        printf("%-9d%-9d%-9d\n", orders[i].order_id, orders[i].menu_id, orders[i].quantity);
                    }
                }

                printf("\n");

                break;
            }

            case 5:{
                printf("Thank you for using The Unique C Cafe Billing System! \n");
                printf("Goodbye! \n");

                break;
            }

            default:{
                printf("Invalid option. Try again. \n");
            }
        }
    } while(option != 5);

    return 0;
}