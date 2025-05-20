#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache_entry {
    int key;
    int value;
    struct cache_entry* next;
} cache_entry;

cache_entry* head = NULL;
const int cache_size = 10;

void evict() {
    cache_entry* current = head;
    while (head->next != NULL) {
        current = head;
        head = head->next;
    }
    free(current);
    head->next = NULL;
}

void insert(int key, int value) {
    cache_entry* new_entry = (cache_entry*) malloc(sizeof(cache_entry));
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = head;
    head = new_entry;
    evict();
}

void search(int key) {
    cache_entry* current = head;
    while (current != NULL) {
        if (current->key == key) {
            printf("Found key %d at index %d\n", key, current - head);
            return;
        }
        current = current->next;
    }
    printf("Key %d not found\n", key);
}

int main() {
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    insert(6, 6);

    search(1);
    search(2);
    search(7); // Null pointer dereference intentionally
    search(3);
    search(4);
    search(5);
    search(6);

    return 0;
}
