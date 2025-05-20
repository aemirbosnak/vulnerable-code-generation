//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

typedef struct HashNode {
    Subscriber subscriber;
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE];

int hash(char *str, int size) {
    int hash = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        hash += tolower(str[i]);
    }

    return hash % size;
}

void add_subscriber(char *name, char *email) {
    int index = hash(name, TABLE_SIZE);
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));

    strcpy(new_node->subscriber.name, name);
    strcpy(new_node->subscriber.email, email);
    new_node->next = table[index];
    table[index] = new_node;
}

void remove_subscriber(char *name) {
    int index = hash(name, TABLE_SIZE);
    HashNode *current = table[index];
    HashNode *previous = NULL;

    while (current != NULL && strcmp(current->subscriber.name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Subscriber not found.\n");
        return;
    }

    if (previous == NULL) {
        table[index] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void print_subscribers() {
    int i;

    printf("Subscribers:\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            HashNode *current = table[i];

            while (current != NULL) {
                printf("%s (%s)\n", current->subscriber.name, current->subscriber.email);
                current = current->next;
            }
        }
    }
}

int main() {
    char command[10];
    char name[50];
    char email[100];

    while (1) {
        printf("\nMailing List Manager:\n1. Add Subscriber\n2. Remove Subscriber\n3. Print Subscribers\n4. Exit\n");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case '2':
                printf("Enter Name: ");
                scanf("%s", name);
                remove_subscriber(name);
                break;
            case '3':
                print_subscribers();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}