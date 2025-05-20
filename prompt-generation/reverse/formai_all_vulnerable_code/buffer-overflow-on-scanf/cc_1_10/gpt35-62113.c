//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_STR_LEN 50

typedef struct {
    int id;
    char name[MAX_STR_LEN];
    float price;
} Item;

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair items[MAX_ITEMS];
    int count;
} Index;

void add_item(Item items[], int *count)
{
    Item item;
    printf("Enter item ID: ");
    scanf("%d", &item.id);
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    items[*count] = item;
    (*count)++;
}

void print_items(Item items[], int count)
{
    printf("ID\tName\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

void add_to_index(Index *index, int key, int value)
{
    Pair pair = {key, value};
    index->items[index->count] = pair;
    index->count++;
}

void print_index(Index index)
{
    printf("Key\tValue\n");
    for (int i = 0; i < index.count; i++) {
        printf("%d\t%d\n", index.items[i].key, index.items[i].value);
    }
}

int search_index(Index index, int key)
{
    for (int i = 0; i < index.count; i++) {
        if (index.items[i].key == key) {
            return index.items[i].value;
        }
    }
    return -1;  // key not found
}

int main()
{
    Item items[MAX_ITEMS];
    int count = 0;

    Index index;
    index.count = 0;

    while (1) {
        printf("\n1. Add item\n");
        printf("2. Print items\n");
        printf("3. Add to index\n");
        printf("4. Print index\n");
        printf("5. Search index\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                print_items(items, count);
                break;
            case 3:
                printf("Enter key: ");
                int key;
                scanf("%d", &key);
                printf("Enter value: ");
                int value;
                scanf("%d", &value);
                add_to_index(&index, key, value);
                break;
            case 4:
                print_index(index);
                break;
            case 5:
                printf("Enter key to search: ");
                int search_key;
                scanf("%d", &search_key);
                int search_result = search_index(index, search_key);
                if (search_result == -1) {
                    printf("Key not found in index\n");
                } else {
                    printf("Value: %d\n", search_result);
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}