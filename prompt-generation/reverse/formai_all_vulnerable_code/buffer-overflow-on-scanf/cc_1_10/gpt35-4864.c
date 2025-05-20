//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char item_name[50];
    int price;
}item;

//Function to print the menu
void print_menu(item *menu, int menu_size){
    printf("------------------------\n");
    printf("Welcome to Happy Cafe!\n");
    printf("------------------------\n");
    printf("Menu:\n");
    for(int i=0; i<menu_size; i++){
        printf("%s \t\t $%d\n",menu[i].item_name,menu[i].price);
    }
    printf("\n");
}

//Function to search for an item in the menu
int search_menu(item *menu, int menu_size, char *item_name){
    for(int i=0; i<menu_size; i++){
        if(strcmp(menu[i].item_name,item_name)==0)
            return i;
    }
    return -1;
}

int main(){
    //Initialize the menu items
    item menu[] = {{"Coffee", 2}, {"Tea", 1}, {"Sandwich", 3}, {"Muffin", 2}, {"Cookies", 1}};

    //Get the menu size
    int menu_size = sizeof(menu)/sizeof(menu[0]);

    //Print the menu
    print_menu(menu, menu_size);

    //Initialize variables
    int choice, quantity;
    char item_name[50];
    int total_bill = 0;

    //Loop to take orders
    while(1){
        //Get user choice
        printf("Enter your choice [1-%d] (0 to exit):",menu_size);
        scanf("%d",&choice);

        //Exit condition
        if(choice==0) break;

        //Get user input for item and quantity
        printf("\nEnter your item name:");
        scanf("%s",item_name);
        printf("Enter quantity:");
        scanf("%d",&quantity);

        //Search for item in the menu
        int index = search_menu(menu, menu_size, item_name);

        //If item is not found, notify the user
        if(index==-1){
            printf("\nSorry, %s is not on the menu\n",item_name);
        }
        //If item is found, calculate the cost and add it to the total bill
        else{
            int item_price = menu[index].price;
            int cost = item_price*quantity;
            total_bill += cost;
            printf("\nAdded %d %s to your cart. Cost:$%d\n\n",quantity,item_name,cost);
        }
    }

    //Print the total bill
    printf("Your total bill is:$%d\n",total_bill);
    printf("\nThank you for choosing Happy Cafe. Have a nice day!\n");

    return 0;
}