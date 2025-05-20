//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct inventory{
    int item_id;
    char item_name[50];
    float item_price;
    int item_quantity;
};

struct inventory item[100];
int items_count=0;

//Function prototypes
void add_item();
void display_items();
void search_item();
void update_item();
void delete_item();

int main(){
    int choice;
    while(1){
        printf("Welcome to the Warehouse Management System!\n");
        printf("\nEnter your choice:\n1. Add new item\n2. Display all items\n3. Search item\n4. Update item\n5. Delete item\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_item();
                    break;
            case 2: display_items();
                    break;
            case 3: search_item();
                    break;
            case 4: update_item();
                    break;
            case 5: delete_item();
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void add_item(){
    printf("Enter the following details of the item:\n");
    printf("Item ID: ");
    scanf("%d",&item[items_count].item_id);
    printf("Item name: ");
    scanf("%s",item[items_count].item_name);
    printf("Item price: ");
    scanf("%f",&item[items_count].item_price);
    printf("Item quantity: ");
    scanf("%d",&item[items_count].item_quantity);
    items_count++;
    printf("Item added successfully!\n");
}

void display_items(){
    printf("-------------------------------------------------\n");
    printf("Item ID\tItem Name\tItem Price\tItem Quantity\n");
    printf("-------------------------------------------------\n");
    for(int i=0;i<items_count;i++){
        printf("%d\t%s\t%.2f\t\t%d\n",item[i].item_id,item[i].item_name,item[i].item_price,item[i].item_quantity);
    }
    printf("-------------------------------------------------\n");
}

void search_item(){
    int id;
    printf("Enter the Item ID: ");
    scanf("%d",&id);
    int flag=0;
    for(int i=0;i<items_count;i++){
        if(item[i].item_id==id){
            printf("-------------------------------------------------\n");
            printf("Item ID\tItem Name\tItem Price\tItem Quantity\n");
            printf("-------------------------------------------------\n");
            printf("%d\t%s\t%.2f\t\t%d\n",item[i].item_id,item[i].item_name,item[i].item_price,item[i].item_quantity);
            printf("-------------------------------------------------\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Item not found!\n");
    }
}

void update_item(){
    int id, flag=0;
    printf("Enter the Item ID: ");
    scanf("%d",&id);
    for(int i=0;i<items_count;i++){
        if(item[i].item_id==id){
            printf("Enter the updated details of the item:\n");
            printf("Item name: ");
            scanf("%s",item[i].item_name);
            printf("Item price: ");
            scanf("%f",&item[i].item_price);
            printf("Item quantity: ");
            scanf("%d",&item[i].item_quantity);
            printf("Item updated successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Item not found!\n");
    }
}

void delete_item(){
    int id, flag=0;
    printf("Enter the Item ID: ");
    scanf("%d",&id);
    for(int i=0;i<items_count;i++){
        if(item[i].item_id==id){
            for(int j=i;j<items_count-1;j++){
                item[j]=item[j+1];
            }
            items_count--;
            printf("Item deleted successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Item not found!\n");
    }
}