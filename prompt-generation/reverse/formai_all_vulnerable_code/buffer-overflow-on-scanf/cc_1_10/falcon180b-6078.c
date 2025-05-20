//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void add_item(void *arg) {
    int id = *(int *) arg;
    printf("Enter name of item %d: ", id);
    scanf("%s", items[id].name);
    printf("Enter price of item %d: ", id);
    scanf("%d", &items[id].price);
    printf("Enter quantity of item %d: ", id);
    scanf("%d", &items[id].quantity);
    num_items++;
}

void update_item(void *arg) {
    int id = *(int *) arg;
    printf("Enter new name of item %d: ", id);
    scanf("%s", items[id].name);
    printf("Enter new price of item %d: ", id);
    scanf("%d", &items[id].price);
    printf("Enter new quantity of item %d: ", id);
    scanf("%d", &items[id].quantity);
}

void delete_item(void *arg) {
    int id = *(int *) arg;
    printf("Item %d deleted.\n", id);
    num_items--;
}

void display_items(void *arg) {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - $%d - %d in stock\n", i + 1, items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, (void *) add_item, (void *) &i);
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Use items
    display_items(NULL);

    return 0;
}