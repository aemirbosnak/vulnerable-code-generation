//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char *key;
    int value;
    struct node *next;
};

struct node *create_node(char *key, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

struct node *insert_node(struct node *head, char *key, int value) {
    struct node *new_node = create_node(key, value);
    struct node *temp = head;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    while (temp!= NULL && strcmp(temp->key, key)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        temp = new_node;
        temp->next = head;
        head = temp;
    } else {
        temp->value = value;
    }
    return head;
}

void delete_node(struct node *head, char *key) {
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp!= NULL && strcmp(temp->key, key)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
    } else {
        if (prev!= NULL) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }
        free(temp->key);
        free(temp);
    }
}

void search_node(struct node *head, char *key) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            printf("Key: %s, Value: %d\n", temp->key, temp->value);
        }
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    int choice, value;
    char key[MAX_SIZE];

    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                head = insert_node(head, key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                delete_node(head, key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%s", key);
                search_node(head, key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}