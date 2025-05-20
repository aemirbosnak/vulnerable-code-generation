//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PRODUCTS 100
#define MAX_THREADS 10

typedef struct {
    char name[50];
    int quantity;
    int price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void *update_product_quantity(void *arg) {
    int i = *(int *) arg;
    while (1) {
        sleep(1);
        products[i].quantity--;
        if (products[i].quantity == 0) {
            printf("Product %s is out of stock.\n", products[i].name);
            exit(0);
        }
    }
    return NULL;
}

void *add_new_product(void *arg) {
    char name[50];
    int quantity, price;
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%d", &price);

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    products[num_products].price = price;
    num_products++;

    printf("Product %s added successfully.\n", name);
    exit(0);
}

void *display_products(void *arg) {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("Product %d: %s (%d left) - $%d\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
    exit(0);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < num_products; i++) {
        pthread_create(&threads[i], NULL, update_product_quantity, (void *) i);
    }

    while (1) {
        printf("Enter option:\n1. Add new product\n2. Display products\n3. Exit\n");
        scanf("%d", &i);

        switch(i) {
            case 1:
                pthread_create(&threads[num_products], NULL, add_new_product, NULL);
                num_products++;
                break;
            case 2:
                for (i = 0; i < num_products; i++) {
                    pthread_create(&threads[i], NULL, display_products, NULL);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}