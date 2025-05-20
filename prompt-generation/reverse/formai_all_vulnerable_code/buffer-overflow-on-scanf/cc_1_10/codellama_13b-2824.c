//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10
#define MAX_ADDRESS_LENGTH 50
#define MAX_STOCK_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int stock[MAX_STOCK_LENGTH];
} Store;

void print_store(Store store) {
    printf("Name: %s\n", store.name);
    printf("Phone: %s\n", store.phone);
    printf("Address: %s\n", store.address);
    printf("Stock: %d\n", store.stock);
}

void add_store(Store *store) {
    printf("Enter the store name: ");
    scanf("%s", store->name);
    printf("Enter the store phone: ");
    scanf("%s", store->phone);
    printf("Enter the store address: ");
    scanf("%s", store->address);
    printf("Enter the store stock: ");
    scanf("%d", &store->stock);
}

void update_store(Store *store) {
    printf("Enter the store name: ");
    scanf("%s", store->name);
    printf("Enter the store phone: ");
    scanf("%s", store->phone);
    printf("Enter the store address: ");
    scanf("%s", store->address);
    printf("Enter the store stock: ");
    scanf("%d", &store->stock);
}

void remove_store(Store *store) {
    printf("Enter the store name: ");
    scanf("%s", store->name);
    printf("Enter the store phone: ");
    scanf("%s", store->phone);
    printf("Enter the store address: ");
    scanf("%s", store->address);
    printf("Enter the store stock: ");
    scanf("%d", &store->stock);
}

int main() {
    Store store;
    add_store(&store);
    print_store(store);
    update_store(&store);
    print_store(store);
    remove_store(&store);
    print_store(store);
    return 0;
}