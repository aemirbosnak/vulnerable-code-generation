//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

typedef struct {
    int key;
    int value;
} element;

typedef struct {
    element *elements;
    int size;
} database;

void create_database(database *db) {
    db->elements = (element *)malloc(MAX_ELEMENTS * sizeof(element));
    db->size = 0;
}

void destroy_database(database *db) {
    free(db->elements);
}

void insert_element(database *db, int key, int value) {
    if (db->size >= MAX_ELEMENTS) {
        printf("Error: database is full.\n");
        return;
    }
    db->elements[db->size].key = key;
    db->elements[db->size].value = value;
    db->size++;
}

int search_element(database *db, int key) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->elements[i].key == key) {
            return db->elements[i].value;
        }
    }
    return -1;
}

void sort_database(database *db) {
    int i, j;
    element temp;
    for (i = 0; i < db->size - 1; i++) {
        for (j = i + 1; j < db->size; j++) {
            if (db->elements[i].key > db->elements[j].key) {
                temp = db->elements[i];
                db->elements[i] = db->elements[j];
                db->elements[j] = temp;
            }
        }
    }
}

int main() {
    database db;
    create_database(&db);
    insert_element(&db, 10, 100);
    insert_element(&db, 20, 200);
    insert_element(&db, 30, 300);
    sort_database(&db);
    printf("Search for key = 10: %d\n", search_element(&db, 10));
    printf("Search for key = 20: %d\n", search_element(&db, 20));
    printf("Search for key = 30: %d\n", search_element(&db, 30));
    destroy_database(&db);
    return 0;
}