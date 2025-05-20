//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 50
#define MAX_MEDICINE 10

typedef struct {
    char name[30];
    int stock;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINE];
    int count;
} Store;

void initStore(Store *store) {
    store->count = 0;
}

void addMedicine(Store *store, const char *name, int stock) {
    if (store->count >= MAX_MEDICINE) {
        printf("Store is full.\n");
        return;
    }
    strcpy(store->medicines[store->count].name, name);
    store->medicines[store->count].stock = stock;
    store->count++;
}

void displayInventory(const Store *store) {
    printf("\nCurrent inventory:\n");
    for (int i = 0; i < store->count; i++) {
        printf("%s: %d\n", store->medicines[i].name, store->medicines[i].stock);
    }
}

int main() {
    Store myStore;
    initStore(&myStore);

    printf("Welcome to the Post-Apocalyptic Medical Store.\n");
    printf("Please bring us medicines and help us heal the survivors.\n");

    while (1) {
        char command[10];
        int arg;

        printf("\nEnter command (add <name> <stock> or exit): ");
        scanf("%s%s%d", command, command+5, &arg);

        if (strcmp(command, "add") == 0) {
            addMedicine(&myStore, command+5, arg);
        } else if (strcmp(command, "display") == 0) {
            displayInventory(&myStore);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Thank you for helping us. Goodbye!\n");

    return 0;
}