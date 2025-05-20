//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct warehouse{
    int id;
    char item[50];
    int quantity;
    double price;
};

void addNewItem(struct warehouse[], int);
void displayAllItems(struct warehouse[], int);
void updateItem(struct warehouse[], int);
void deleteItem(struct warehouse[], int);
void searchItem(struct warehouse[], int);

int main(){
    int choice, n, i;
    printf("Enter the initial number of items in the warehouse: ");
    scanf("%d", &n);
    struct warehouse w[n];
    printf("\nEnter the details of the items in the warehouse: \n");
    for(i=0; i<n; i++){
        printf("Enter the id of item %d: ", i+1);
        scanf("%d",&w[i].id);
        printf("Enter the name of item %d: ", i+1);
        scanf("%s",w[i].item);
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d",&w[i].quantity);
        printf("Enter the price of item %d: ", i+1);
        scanf("%lf",&w[i].price);
    }
    do{
        printf("\n************Warehouse Management System************\n");
        printf("1. Add new item to the warehouse.\n");
        printf("2. Display all items in the warehouse.\n");
        printf("3. Update quantity of an item.\n");
        printf("4. Delete an item.\n");
        printf("5. Search an item by its ID.\n");
        printf("6. Exit.\n");
        printf("Enter your choice (1-6): ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addNewItem(w,n);
                    n++;
                    break;
            case 2: displayAllItems(w,n);
                    break;
            case 3: updateItem(w,n);
                    break;
            case 4: deleteItem(w,n);
                    n--;
                    break;
            case 5: searchItem(w,n);
                    break;
            case 6: exit(0);
            default:printf("Invalid choice! Try again.\n");
        }
    }while(choice!=6);

    return 0;
}

void addNewItem(struct warehouse w[], int n){
    printf("\nEnter the details of the new item: \n");
    printf("Enter the id of item: ");
    scanf("%d",&w[n].id);
    printf("Enter the name of item: ");
    scanf("%s",w[n].item);
    printf("Enter the quantity of item: ");
    scanf("%d",&w[n].quantity);
    printf("Enter the price of item: ");
    scanf("%lf",&w[n].price);
    printf("\nItem added successfully.\n");
}

void displayAllItems(struct warehouse w[], int n){
    int i;
    printf("\n************All Items in the Warehouse************\n");
    for(i=0; i<n; i++){
        printf("ID            :%d\n",w[i].id);
        printf("Name          :%s\n",w[i].item);
        printf("Quantity      :%d\n",w[i].quantity);
        printf("Price         :%.2lf\n",w[i].price);
        printf("---------------------------------------\n");
    }
}

void updateItem(struct warehouse w[], int n){
    int id, i, qty;
    printf("\nEnter the id of the item to update Quantity: ");
    scanf("%d",&id);
    for(i=0; i<n; i++){
        if(w[i].id==id){
            printf("Enter the quantity to add or remove (negative to remove): ");
            scanf("%d",&qty);
            w[i].quantity+=qty;
            printf("\nQuantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");

}

void deleteItem(struct warehouse w[], int n){
    int id, i, j;
    printf("\nEnter the id of the item to delete: ");
    scanf("%d",&id);
    for(i=0; i<n; i++){
        if(w[i].id==id){
            for(j=i+1; j<n; j++){
                w[j-1]=w[j];
            }
            printf("\nItem deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void searchItem(struct warehouse w[], int n){
    int id, i;
    printf("\nEnter the id of the item to search: ");
    scanf("%d",&id);
    for(i=0; i<n; i++){
        if(w[i].id==id){
            printf("\nItem Found!!\n");
            printf("ID            :%d\n",w[i].id);
            printf("Name          :%s\n",w[i].item);
            printf("Quantity      :%d\n",w[i].quantity);
            printf("Price         :%.2lf\n",w[i].price);
            printf("---------------------------------------\n");
            return;
        }
    }
    printf("Item not found.\n");
}