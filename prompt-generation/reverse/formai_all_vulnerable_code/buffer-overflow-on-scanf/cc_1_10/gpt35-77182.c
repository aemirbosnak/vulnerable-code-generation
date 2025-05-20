//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Product* next;
} Product;

Product* head = NULL;
int last_id = 0;

int get_new_id(){
    return ++last_id;
}

void add_product(Product* new_product){
    if(head == NULL){
        head = new_product;
    }else{
        Product* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_product;
    }
}

void display_product(Product* prod){
    printf("ID: %d\n", prod->id);
    printf("Name: %s\n", prod->name);
    printf("Quantity: %d\n", prod->quantity);
    printf("Price: %.2f$\n", prod->price);
}

void list_products(){
    if(head == NULL){
        printf("No products found.\n");
    }else{
        Product* current = head;
        while(current != NULL){
            display_product(current);
            printf("---------------\n");
            current = current->next;
        }
    }
}

Product* find_product(int id){
    Product* current = head;
    while(current != NULL && current->id != id){
        current = current->next;
    }
    return current;
}

void delete_product(int id){
    Product *current = head;
    Product *previous = NULL;
    while(current != NULL && current->id != id){
        previous = current;
        current = current->next;
    }

    if(current != NULL){
        if(previous == NULL){
            head = current->next;
        }else{
            previous->next = current->next;
        }
        free(current);
    }else{
        printf("Product not found.\n");
    }
}

int main(){
    char choice;
    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("1 - Add a new product\n");
        printf("2 - List all products\n");
        printf("3 - Delete a product\n");
        printf("Q - Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        switch(choice){
            case '1':{
                Product* new_product = (Product*) malloc(sizeof(Product));
                new_product->id = get_new_id();
                printf("Enter product name: ");
                scanf("%s", new_product->name);
                printf("Enter product quantity: ");
                scanf("%d", &(new_product->quantity));
                printf("Enter product price: ");
                scanf("%f", &(new_product->price));
                new_product->next = NULL;
                add_product(new_product);
                printf("Product added successfully!\n");
                break;
            }
            case '2':{
                list_products();
                break;
            }
            case '3':{
                int id;
                printf("Enter product ID to delete: ");
                scanf("%d", &id);
                delete_product(id);
                break;
            }
            case 'Q':
            case 'q':{
                printf("Exiting...\n");
                break;
            }
            default:{
                printf("Invalid choice: %c\n", choice);
            }
        }
    }while(choice != 'Q' && choice != 'q');

    // Free memory used by products
    Product* current = head;
    Product* next = NULL;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}