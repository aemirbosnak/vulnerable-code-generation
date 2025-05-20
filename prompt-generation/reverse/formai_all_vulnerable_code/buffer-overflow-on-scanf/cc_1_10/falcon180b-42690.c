//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_KEY_LENGTH 50

typedef struct {
    char key[MAX_KEY_LENGTH];
    int value;
} item;

item database[MAX_ITEMS];
int num_items = 0;

void insert_item(char* key, int value) {
    if (num_items >= MAX_ITEMS) {
        printf("Database is full!\n");
        return;
    }

    strcpy(database[num_items].key, key);
    database[num_items].value = value;
    num_items++;
}

void delete_item(char* key) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(database[i].key, key) == 0) {
            memmove(&database[i], &database[i+1], sizeof(item) * (num_items - i - 1));
            num_items--;
            return;
        }
    }

    printf("Item not found!\n");
}

void search_item(char* key) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Value: %d\n", database[i].value);
            return;
        }
    }

    printf("Item not found!\n");
}

int main() {
    int choice;

    do {
        printf("1. Insert item\n");
        printf("2. Delete item\n");
        printf("3. Search item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char key[MAX_KEY_LENGTH];
                int value;
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert_item(key, value);
                break;
            }

            case 2: {
                char key[MAX_KEY_LENGTH];
                printf("Enter key: ");
                scanf("%s", key);
                delete_item(key);
                break;
            }

            case 3: {
                char key[MAX_KEY_LENGTH];
                printf("Enter key: ");
                scanf("%s", key);
                search_item(key);
                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}