//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for menu items
struct menu_item{
    char name[50];
    float price;
};

//Function to display menu
void display_menu(struct menu_item menu[],int size){
    printf("\nMenu:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s - $%.2f\n",i+1,menu[i].name,menu[i].price);
    }
}

//Function to place order
void place_order(struct menu_item menu[],int size,float total){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    if(choice>size || choice<1){
        printf("Invalid choice!\n");
        return;
    }
    total+=menu[choice-1].price;
    printf("\nYour order has been placed.\n");
    printf("Total amount: $%.2f\n",total);
}

//Function to generate bill
void generate_bill(struct menu_item menu[],int size,float total){
    printf("\nYour bill:\n");
    for(int i=0;i<size;i++){
        if(strcmp(menu[i].name,"")!=0){
            printf("%s - $%.2f\n",menu[i].name,menu[i].price);
        }
    }
    printf("\nTotal amount: $%.2f\n",total);
}

//Main function
int main(){
    int size;
    printf("Enter the number of items in the menu: ");
    scanf("%d",&size);

    //Defining menu items
    struct menu_item menu[size];
    for(int i=0;i<size;i++){
        printf("\nEnter item %d:\n",i+1);
        printf("Name: ");
        scanf("%s",menu[i].name);
        printf("Price: $");
        scanf("%f",&menu[i].price);
    }

    //Displaying menu
    display_menu(menu,size);

    //Placing order
    float total=0;
    place_order(menu,size,total);

    //Generating bill
    generate_bill(menu,size,total);

    return 0;
}