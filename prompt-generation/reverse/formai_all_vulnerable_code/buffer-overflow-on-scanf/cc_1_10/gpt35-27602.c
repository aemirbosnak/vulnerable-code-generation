//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM_NAME 20
#define MAX_ITEM_QUANTITY 50

struct item{
    char name[MAX_ITEM_NAME];
    int quantity;
};

struct item stock[MAX_ITEM_QUANTITY];
int count = 0;

void add_item(){
    if(count < MAX_ITEM_QUANTITY){
        printf("Enter the Name of the Item: ");
        scanf("%s", stock[count].name);

        printf("Enter the Quantity of the Item: ");
        scanf("%d", &stock[count].quantity);

        printf("Item Added Successfully!\n");
        count++;
    }
    else{
        printf("Maximum Capacity of the Store Reached.\n");
    }
}

void display_stock(){
    printf("Items in Stock: \n");
    printf("==============================================\n");
    printf("Name \t\t Quantity \n");
    printf("==============================================\n");
    for(int i=0; i<count; i++){
        printf("%-20s %d\n", stock[i].name, stock[i].quantity);
    }
    printf("==============================================\n");
}

void search_item(){
    char name[MAX_ITEM_NAME];
    printf("Enter the Name of the Item to Search: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0; i<count; i++){
        if(strcmp(name, stock[i].name) == 0){
            printf("%s is available in quantity %d\n", stock[i].name, stock[i].quantity);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("%s is not available in Stock.\n", name);
    }
}

int main(){
    int choice;

    do{
        printf("================ MENU ===============\n");
        printf("1. Add Item to Stock\n");
        printf("2. Display Stock\n");
        printf("3. Search Item\n");
        printf("4. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_item();
                    break;
            case 2: display_stock();
                    break;
            case 3: search_item();
                    break;
            case 4: printf("Goodbye!\n");
                    exit(0);
                    break;
            default: printf("Invalid Choice. Please Try Again.\n");
                     break;
        }

    }while(choice != 4);

    return 0;
}