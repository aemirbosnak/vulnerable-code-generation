//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    struct node *next;
} node;

node *hash_table[100];

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while(key[i]!= '\0') {
        sum += key[i];
        i++;
    }
    return sum % 100;
}

void insert(char *key, int value) {
    int index = hash(key);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = (char *)malloc(strlen(key) + 1);
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    if(hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        node *temp = hash_table[index];
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int search(char *key) {
    int index = hash(key);
    node *temp = hash_table[index];
    while(temp!= NULL) {
        if(strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

int main() {
    int choice, value;
    char key[20];
    int i = 0;
    while(1) {
        printf("Enter your choice:\n1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter key:\n");
            scanf("%s", key);
            printf("Enter value:\n");
            scanf("%d", &value);
            insert(key, value);
        } else if(choice == 2) {
            printf("Enter key to search:\n");
            scanf("%s", key);
            value = search(key);
            if(value == -1) {
                printf("Key not found\n");
            } else {
                printf("Value: %d\n", value);
            }
        } else if(choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}