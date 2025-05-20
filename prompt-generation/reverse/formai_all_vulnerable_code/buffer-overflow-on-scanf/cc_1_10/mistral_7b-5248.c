//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 13
#define MAX_NAME_LEN 20
#define MAX_ITEM_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} Item;

typedef struct HashNode {
    Item item;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode *nodes[TABLE_SIZE];
} HashTable;

HashTable hashTable;
Item menu[10];

void initHashTable() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable.nodes[i] = NULL;
    }
}

int hashFunction(const char *name) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash += tolower(name[i]);
    }
    return hash % TABLE_SIZE;
}

void addItem(const char *name, int price) {
    Item newItem = {name, price};
    int hashIndex = hashFunction(name);

    HashNode *newNode = (HashNode *) malloc(sizeof(HashNode));
    newNode->item = newItem;
    newNode->next = hashTable.nodes[hashIndex];
    hashTable.nodes[hashIndex] = newNode;
}

void displayMenu() {
    puts("\n------------------- MENU -------------------");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %.2d\n", i+1, menu[i].name, menu[i].price);
    }
    puts("--------------------------------------------");
}

int main() {
    initHashTable();
    addItem("Cappuccino", 2.5);
    addItem("Latte", 2.8);
    addItem("Espresso", 1.8);
    addItem("Americano", 1.9);
    addItem("Mocha", 3.2);
    addItem("Tea", 1.5);
    addItem("Hot Chocolate", 2.2);
    addItem("Cookies", 0.8);
    addItem("Danish", 1.6);
    addItem("Sandwich", 3.5);

    int choice;
    int total = 0;
    do {
        displayMenu();
        scanf("%d", &choice);
        if (choice > 0 && choice <= 10) {
            printf("You ordered: %s\n", menu[choice-1].name);
            total += menu[choice-1].price;
            printf("Your total is: %.2f\n", (float) total / 10.0);
        } else {
            puts("Invalid choice!");
        }
    } while (choice != 0);

    return 0;
}