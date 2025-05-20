//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    char name[50];
    int stock;
    float price;
    struct Product *next;
};

struct Product *head=NULL;

void insertProduct(int position){
    struct Product *temp, *ptr;
    temp=(struct Product*)malloc(sizeof(struct Product));
    printf("Enter Product Name:");
    scanf("%s", &(temp->name));
    printf("Enter Stock:");
    scanf("%d",&(temp->stock));
    printf("Enter Price:");
    scanf("%f",&(temp->price));
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }else{
        if(position==0){
            temp->next=head;
            head=temp;
        }else{
            ptr=head;
            for(int i=0;i<position-1;i++){
                ptr=ptr->next;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
    }
}

void deleteProduct(int position){
    struct Product *temp, *ptr;
    if(head==NULL){
        printf("Inventory is empty\n");
        return;
    }else{
        if(position==0){
            temp=head;
            head=head->next;
        }else{
            ptr=head;
            for(int i=1;i<position;i++){
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("Invalid Position\n");
                    return;
                }
            }
            temp=ptr->next;
            ptr->next=temp->next;
        }
    }
    printf("Deleted Product %s\n",temp->name);
    free(temp);
}

void displayInventory(){
    struct Product *ptr;
    int count=1;
    ptr=head;
    printf("Product Inventory\n");
    printf("------------------\n");
    printf("Sl.No\tProduct\t\tStock\tPrice\n");
    printf("------------------\n");
    while(ptr!=NULL){
        printf("%d\t%s\t\t%d\t%.2f\n",count,ptr->name,ptr->stock,ptr->price);
        ptr=ptr->next;
        count++;
    }
    printf("------------------\n");
}

int main(){
    int choice, position;
    while(1){
        printf("Inventory System\n");
        printf("-----------------\n");
        printf("1. Insert Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("-----------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the position to insert:");
                    scanf("%d",&position);
                    insertProduct(position);
                    break;
            case 2: printf("Enter the position to delete:");
                    scanf("%d",&position);
                    deleteProduct(position);
                    break;
            case 3: displayInventory();
                    break;
            case 4: printf("Exiting the program...");
                    exit(0);
            default:printf("Invalid Choice\n");
                    break;
        }
    }
    return 0;
}