//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

// Item struct
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

// Global variables
Item items[MAX_ITEMS];
int num_items = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a new item to the system
void add_item(int id, char* name, int quantity) {
    pthread_mutex_lock(&mutex);
    // Check if item already exists
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            items[i].quantity += quantity;
            pthread_mutex_unlock(&mutex);
            return;
        }
    }
    // Add new item
    Item new_item;
    new_item.id = id;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    items[num_items] = new_item;
    num_items++;
    pthread_mutex_unlock(&mutex);
}

// Function to remove an item from the system
void remove_item(int id, int quantity) {
    pthread_mutex_lock(&mutex);
    // Find item
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    // Remove item or update quantity
    if (index != -1) {
        if (items[index].quantity >= quantity) {
            items[index].quantity -= quantity;
        } else {
            printf("Error: Not enough quantity.\n");
        }
    } else {
        printf("Error: Item not found.\n");
    }
    pthread_mutex_unlock(&mutex);
}

// Function to display all items in the system
void display_items() {
    pthread_mutex_lock(&mutex);
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t%d\n", items[i].id, items[i].name, items[i].quantity);
    }
    pthread_mutex_unlock(&mutex);
}

// Thread function to continuously prompt user for input
void* prompt_thread(void* arg) {
    bool running = true;
    while (running) {
        printf("Enter command (add/remove/display/quit): ");
        char command[MAX_NAME_LENGTH];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            int id, quantity;
            char name[MAX_NAME_LENGTH];
            printf("Enter item ID, name and quantity: ");
            scanf("%d %s %d", &id, name, &quantity);
            add_item(id, name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            int id, quantity;
            printf("Enter item ID and quantity: ");
            scanf("%d %d", &id, &quantity);
            remove_item(id, quantity);
        } else if (strcmp(command, "display") == 0) {
            display_items();
        } else if (strcmp(command, "quit") == 0) {
            running = false;
        } else {
            printf("Error: Invalid command.\n");
        }
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize items
    Item item1 = { 1, "Pencil", 10 };
    Item item2 = { 2, "Pen", 5 };
    items[0] = item1;
    items[1] = item2;
    num_items = 2;
    
    // Create prompt thread
    pthread_t prompt_t;
    pthread_create(&prompt_t, NULL, prompt_thread, NULL);
    
    // Wait for prompt thread to complete
    pthread_join(prompt_t, NULL);
    
    return 0;
}