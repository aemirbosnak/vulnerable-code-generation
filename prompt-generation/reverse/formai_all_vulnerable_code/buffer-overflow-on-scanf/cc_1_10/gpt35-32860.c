//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product{
    int id;
    char name[20];
    int quantity;
};

struct warehouse{
    struct product products[MAX_PRODUCTS];
    int size;
};

void add_product(struct warehouse *w, int id, char* name, int quantity){
    if(w->size >= MAX_PRODUCTS){
        printf("Warehouse is full\n");
        return;
    }
    struct product p;
    p.id = id;
    strcpy(p.name, name);
    p.quantity = quantity;
    w->products[w->size++] = p;
    printf("Product added successfully\n");
}

void remove_product(struct warehouse *w, int id){
    int index = -1;
    for(int i=0; i<w->size; i++){
        if(w->products[i].id == id){
            index = i;
            break;
        }
    }
    if(index==-1){
        printf("Product not found\n");
        return;
    }
    for(int i=index; i<w->size-1; i++){
        w->products[i] = w->products[i+1];
    }
    w->size--;
    printf("Product removed successfully\n");   
}

void display_products(struct warehouse *w){
    if(w->size == 0){
        printf("Warehouse is empty\n");
        return;
    }
    printf("%-5s %-20s %-10s\n", "ID", "Name", "Quantity");
    printf("--------------------------------------\n");
    for(int i=0; i<w->size; i++){
        printf("%-5d %-20s %-10d\n", w->products[i].id, w->products[i].name, w->products[i].quantity);
    }
}

int main(){
    struct warehouse w;
    w.size = 0;
    int choice, id, quantity;
    char name[20];
    printf("Welcome to Warehouse Management System!\n");
    do{
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_product(&w, id, name, quantity);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                remove_product(&w, id);
                break;
            case 3:
                display_products(&w);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}