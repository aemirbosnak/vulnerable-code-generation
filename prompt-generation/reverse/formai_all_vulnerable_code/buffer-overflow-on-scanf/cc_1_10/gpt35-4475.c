//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[20];
    int item_no;
    float price;
    int quantity;
};

struct product inv[50];
int num_products = 0;

void add_product(){
    printf("Enter Product Details -\n");
    printf("Name: ");
    scanf("%s", inv[num_products].name);
    printf("Item No.: ");
    scanf("%d", &inv[num_products].item_no);
    printf("Price: ");
    scanf("%f", &inv[num_products].price);
    printf("Quantity: ");
    scanf("%d", &inv[num_products].quantity);
    num_products++;
}

void search_product(){
    int flag = 0;
    int item_no;
    printf("Enter Item No.: ");
    scanf("%d", &item_no);
    for(int i=0; i<num_products; i++){
        if(inv[i].item_no == item_no){
            printf("Name: %s\n", inv[i].name);
            printf("Item No.: %d\n", inv[i].item_no);
            printf("Price: %.2f\n", inv[i].price);
            printf("Quantity: %d\n", inv[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

void update_product(){
    int flag = 0;
    int item_no;
    printf("Enter Item No.: ");
    scanf("%d", &item_no);
    for(int i=0; i<num_products; i++){
        if(inv[i].item_no == item_no){
            printf("Enter new details -\n");
            printf("Name: ");
            scanf("%s", inv[i].name);
            printf("Price: ");
            scanf("%f", &inv[i].price);
            printf("Quantity: ");
            scanf("%d", &inv[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

void delete_product(){
    int flag = 0;
    int item_no;
    printf("Enter Item No.: ");
    scanf("%d", &item_no);
    for(int i=0; i<num_products; i++){
        if(inv[i].item_no == item_no){
            for(int j=i; j<num_products-1; j++){
                strcpy(inv[j].name, inv[j+1].name);
                inv[j].item_no = inv[j+1].item_no;
                inv[j].price = inv[j+1].price;
                inv[j].quantity = inv[j+1].quantity;
            }
            num_products--;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

void display_products(){
    printf("Product Inventory -\n");
    for(int i=0; i<num_products; i++){
        printf("%s - Item No.: %d, Price: %.2f, Quantity: %d\n", inv[i].name, inv[i].item_no, inv[i].price, inv[i].quantity);
    }
}

int main(){
    int choice;
    while(1){
        printf("\nMenu -\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Display Products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                display_products();
                break;
            case 6:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}