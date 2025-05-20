//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct Product{
    int p_id;
    char p_name[20];
    float p_price;
    int p_stock;
};

int main(){
    int total_products = 0;
    printf("Enter the number of products in the inventory: ");
    scanf("%d",&total_products);

    struct Product* inventory = (struct Product*)malloc(sizeof(struct Product)*total_products);

    printf("Enter the details of %d products:\n",total_products);

    for(int i = 0;i<total_products;i++){
        printf("Product %d:\n",i+1);
        printf("Product ID: ");
        scanf("%d",&inventory[i].p_id);
        printf("Product Name: ");
        scanf("%s",inventory[i].p_name);
        printf("Product Price: ");
        scanf("%f",&inventory[i].p_price);
        printf("Product Stock: ");
        scanf("%d",&inventory[i].p_stock);
    }

    printf("\n\nThe Inventory Details:\n");
    printf("------------------------\n");

    printf("Product ID\tProduct Name\tPrice\tStock\n");
    printf("-------------------------------------------------------\n");

    for(int i = 0;i<total_products;i++){
        printf("%d\t\t%s\t\t%.2f\t%d\n",inventory[i].p_id,inventory[i].p_name,inventory[i].p_price,inventory[i].p_stock);
    }

    int total_stock = 0;
    for(int i = 0;i<total_products;i++){
        total_stock += inventory[i].p_stock;
    }

    printf("-------------------------------------------------------\n");
    printf("Total Stock:\t%d\n",total_stock);

    free(inventory);
    return 0;
}