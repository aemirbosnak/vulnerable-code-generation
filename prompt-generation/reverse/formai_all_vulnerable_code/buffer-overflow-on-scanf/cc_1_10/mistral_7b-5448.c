//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** data;
} HashTable;

HashTable create_hash_table() {
    HashTable ht;
    ht.data = calloc(TABLE_SIZE, sizeof(Node*));
    return ht;
}

int hash_func(char* key, int table_size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += tolower(key[i]);
    }
    hash %= table_size;
    return hash;
}

void insert_subscription(HashTable* ht, char* name) {
    int index = hash_func(name, TABLE_SIZE);
    if (ht->data[index] == NULL) {
        ht->data[index] = malloc(sizeof(Node));
        strcpy(ht->data[index]->name, name);
        ht->data[index]->next = NULL;
    } else {
        Node* current = ht->data[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = malloc(sizeof(Node));
        strcpy(current->next->name, name);
        current->next->next = NULL;
    }
}

void remove_subscription(HashTable* ht, char* name) {
    int index = hash_func(name, TABLE_SIZE);
    if (ht->data[index] != NULL) {
        Node* current = ht->data[index];
        if (strcmp(current->name, name) == 0) {
            ht->data[index] = current->next;
            free(current);
            return;
        }
        while (current->next != NULL && strcmp(current->next->name, name) != 0) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Name not found in the list.\n");
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    } else {
        printf("Name not found in the list.\n");
    }
}

void display_mailing_list(HashTable ht) {
    printf("Mailing List:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht.data[i] != NULL) {
            Node* current = ht.data[i];
            printf("%s\n", current->name);
            while (current->next != NULL) {
                current = current->next;
                printf("%s\n", current->name);
            }
        }
    }
}

int main() {
    HashTable ht = create_hash_table();

    char command[10];
    char name[50];

    while (true) {
        printf("Enter command (subscribe/unsubscribe/view/quit): ");
        scanf("%s", command);

        if (strcmp(command, "subscribe") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            insert_subscription(&ht, name);
        } else if (strcmp(command, "unsubscribe") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            remove_subscription(&ht, name);
        } else if (strcmp(command, "view") == 0) {
            display_mailing_list(ht);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    free(ht.data);

    return 0;
}