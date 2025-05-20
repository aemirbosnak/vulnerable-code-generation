//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct item{
    int id;
    char name[50];
    int quantity;
    int price;
};

struct item warehouse[MAX];
int n=0;

void add_item(){
    printf("\nEnter the ID of the item: ");
    scanf("%d",&warehouse[n].id);

    printf("\nEnter the name of the item: ");
    scanf("%s",warehouse[n].name);

    printf("\nEnter the quantity of the item: ");
    scanf("%d",&warehouse[n].quantity);

    printf("\nEnter the price of the item: ");
    scanf("%d",&warehouse[n].price);

    n++;
}

void display_item(){
    printf("\nID\tName\tQuantity\tPrice");
    for(int i=0;i<n;i++){
        printf("\n%d\t%s\t%d\t%d",warehouse[i].id,warehouse[i].name,warehouse[i].quantity,warehouse[i].price);
    }
}

void search_item(){
    printf("\nEnter the ID of the item to search: ");
    int id;
    scanf("%d",&id);

    for(int i=0;i<n;i++){
        if(warehouse[i].id==id){
            printf("\nID\tName\tQuantity\tPrice");
            printf("\n%d\t%s\t%d\t%d",warehouse[i].id,warehouse[i].name,warehouse[i].quantity,warehouse[i].price);
        }
    }
}

void update_item(){
    printf("\nEnter the ID of the item to update: ");
    int id;
    scanf("%d",&id);

    for(int i=0;i<n;i++){
        if(warehouse[i].id==id){
            printf("\nEnter the new quantity of the item: ");
            scanf("%d",&warehouse[i].quantity);

            printf("\nEnter the new price of the item: ");
            scanf("%d",&warehouse[i].price);

            printf("\nItem updated successfully!");
        }
    }
}

void delete_item(){
    printf("\nEnter the ID of the item to delete: ");
    int id;
    scanf("%d",&id);

    for(int i=0;i<n;i++){
        if(warehouse[i].id==id){
            for(int j=i;j<n-1;j++){
                warehouse[j]=warehouse[j+1];
            }
            n--;

            printf("\nItem deleted successfully!");
        }
    }
}

int main(){
    int choice;

    do{
        printf("\n\nWarehouse Management System\n");
        printf("\n1.Add item");
        printf("\n2.Display items");
        printf("\n3.Search item");
        printf("\n4.Update item");
        printf("\n5.Delete item");
        printf("\n6.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_item();
                break;

            case 2:
                display_item();
                break;

            case 3:
                search_item();
                break;

            case 4:
                update_item();
                break;

            case 5:
                delete_item();
                break;

            case 6:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=6);

    return 0;
}