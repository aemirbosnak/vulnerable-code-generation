//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for warehouse item
struct item{
    char name[20];
    int qty;
    float price;
};

//function to display menu
void display_menu(){
    printf("*****Warehouse Management System*****\n\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item Quantity\n");
    printf("4. View All Items\n");
    printf("5. Search Item\n");
    printf("6. Exit\n\n");
}

//function to add item in warehouse
void add_item(struct item warehouse[], int *num_items){
    if(*num_items<50){
        printf("Enter Item Name: ");
        scanf("%s",warehouse[*num_items].name);
        printf("Enter Item Quantity: ");
        scanf("%d",&warehouse[*num_items].qty);
        printf("Enter Item Price: ");
        scanf("%f",&warehouse[*num_items].price);
        (*num_items)++;
        printf("\nItem added successfully!\n");
    }
    else{
        printf("\nWarehouse is full! Cannot add more items.\n");
    }
}

//function to remove item from warehouse
void remove_item(struct item warehouse[], int *num_items){
    char item_name[20];
    int index=-1;
    printf("Enter Item Name to Remove: ");
    scanf("%s",item_name);
    for(int i=0; i<*num_items; i++){
        if(strcmp(warehouse[i].name, item_name)==0){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("\nItem not found!\n");
    }
    else{
        for(int i=index; i<*num_items-1; i++){
            warehouse[i]=warehouse[i+1];
        }
        (*num_items)--;
        printf("\nItem removed successfully!\n");
    }
}

//function to update quantity of existing item
void update_quantity(struct item warehouse[], int num_items){
    char item_name[20];
    int index=-1;
    printf("Enter Item Name to Update Quantity: ");
    scanf("%s",item_name);
    for(int i=0; i<num_items; i++){
        if(strcmp(warehouse[i].name, item_name)==0){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("\nItem not found!\n");
    }
    else{
        printf("Enter New Quantity: ");
        scanf("%d",&warehouse[index].qty);
        printf("\nQuantity updated successfully!\n");
    }
}

//function to view all items in warehouse
void view_all_items(struct item warehouse[], int num_items){
    printf("\n%-20s%-10s%-10s\n","Item Name","Quantity","Price");
    for(int i=0; i<num_items; i++){
        printf("%-20s%-10d%-10.2f\n",warehouse[i].name,warehouse[i].qty,warehouse[i].price);
    }
}

//function to search for an item
void search_item(struct item warehouse[], int num_items){
    char item_name[20];
    int index=-1;
    printf("Enter Item Name to Search: ");
    scanf("%s",item_name);
    for(int i=0; i<num_items; i++){
        if(strcmp(warehouse[i].name, item_name)==0){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("\nItem not found!\n");
    }
    else{
        printf("\n%-20s%-10s%-10s\n","Item Name","Quantity","Price");
        printf("%-20s%-10d%-10.2f\n",warehouse[index].name,warehouse[index].qty,warehouse[index].price);
    }
}

//main function
int main(){
    struct item warehouse[50];
    int num_items=0;
    int choice;

    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_item(warehouse,&num_items);
                break;
            case 2:
                remove_item(warehouse,&num_items);
                break;
            case 3:
                update_quantity(warehouse,num_items);
                break;
            case 4:
                view_all_items(warehouse,num_items);
                break;
            case 5:
                search_item(warehouse,num_items);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }while(choice!=6);

    return 0;
}