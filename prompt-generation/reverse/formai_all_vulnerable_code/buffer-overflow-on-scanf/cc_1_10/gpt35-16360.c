//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_ITEMS 100

typedef struct {
    char item_name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    Item items[MAX_ITEMS];
    int num_items;
} Person;

int num_people = 0;
Person people[MAX_ITEMS];

void add_person() {
    if (num_people == MAX_ITEMS) {
        printf("Maximum number of people reached. Cannot add any more.\n");
        return;
    }

    Person p;
    printf("Enter person's ID: ");
    scanf("%s", p.id);
    printf("Enter person's name: ");
    scanf("%s", p.name);
    p.num_items = 0;
    people[num_people++] = p;

    printf("Person added successfully!\n");
}

Person* find_person(char* id) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].id, id) == 0) {
            return &people[i];
        }
    }

    return NULL;
}

void add_item() {
    char id[MAX_ID_LENGTH];
    printf("Enter person's ID: ");
    scanf("%s", id);

    Person* p = find_person(id);
    if (p == NULL) {
        printf("Person not found.\n");
        return;
    }

    if (p->num_items == MAX_ITEMS) {
        printf("Maximum number of items reached for this person. Cannot add any more.\n");
        return;
    }

    Item item;
    printf("Enter item name: ");
    scanf("%s", item.item_name);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    p->items[p->num_items++] = item;

    printf("Item added successfully!\n");
}

void print_items(Item* items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf(" - %s (Quantity: %d)\n", items[i].item_name, items[i].quantity);
    }
}

void search_item() {
    char item_name[MAX_NAME_LENGTH];
    printf("Enter item name: ");
    scanf("%s", item_name);

    bool found = false;
    for (int i = 0; i < num_people; i++) {
        for (int j = 0; j < people[i].num_items; j++) {
            if (strcmp(people[i].items[j].item_name, item_name) == 0) {
                printf("Item found for person ID %s:\n", people[i].id);
                print_items(&people[i].items[j], 1);
                found = true;
            }
        }
    }

    if (!found) {
        printf("Item not found for any person.\n");
    }
}

void print_people() {
    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        printf(" - %s (ID: %s)\n", people[i].name, people[i].id);
        print_items(people[i].items, people[i].num_items);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nMedieval Inventory System - Menu\n");
        printf("1. Add person\n");
        printf("2. Add item\n");
        printf("3. Search item\n");
        printf("4. Print people and their items\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_person();
                break;
            case 2:
                add_item();
                break;
            case 3:
                search_item();
                break;
            case 4:
                print_people();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}