//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node {
    char *key;
    char *data;
    struct node *next;
} node;

typedef struct {
    node *head;
    int size;
} db;

void insert(db *db, char *key, char *data) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->key, key);
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (db->head == NULL) {
        db->head = newNode;
        db->size++;
    } else {
        node *curr = db->head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        db->size++;
    }
}

void printDB(db *db) {
    node *curr = db->head;
    while (curr!= NULL) {
        printf("%s => %s\n", curr->key, curr->data);
        curr = curr->next;
    }
}

void deleteDB(db *db, char *key) {
    node *prev = NULL;
    node *curr = db->head;
    while (curr!= NULL && strcmp(curr->key, key)!= 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    if (prev == NULL) {
        db->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    db->size--;
}

int main() {
    db db;
    insert(&db, "Name", "John");
    insert(&db, "Occupation", "Hacker");
    insert(&db, "Location", "Seattle");
    insert(&db, "Age", "35");

    printDB(&db);
    printf("\n");

    deleteDB(&db, "Name");
    printDB(&db);
    printf("\n");

    deleteDB(&db, "Location");
    printDB(&db);
    printf("\n");

    deleteDB(&db, "Occupation");
    printDB(&db);
    printf("\n");

    return 0;
}