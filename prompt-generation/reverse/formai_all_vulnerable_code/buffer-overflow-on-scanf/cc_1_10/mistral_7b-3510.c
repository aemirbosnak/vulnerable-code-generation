//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

Subscriber *hash_table[TABLE_SIZE] = {0};

unsigned int hash_func(char *str) {
    unsigned int hash = 0;
    for (int i = 0; str[i]; i++)
        hash = (hash * 31 + str[i]) % TABLE_SIZE;
    return hash;
}

Subscriber *find_subscriber(char *name) {
    unsigned int hash = hash_func(name);
    Subscriber *current = hash_table[hash];

    while (current) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }

    return NULL;
}

void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);

    unsigned int hash = hash_func(name);
    new_subscriber->next = hash_table[hash];
    hash_table[hash] = new_subscriber;
}

void delete_subscriber(char *name) {
    Subscriber *prev = NULL, *current = hash_table[hash_func(name)];

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev)
                prev->next = current->next;
            else
                hash_table[hash_func(name)] = current->next;

            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void print_mailing_list() {
    printf("Mailing List:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Subscriber *current = hash_table[i];
        if (current) {
            printf("%s: %s\n", current->name, current->email);
            while (current->next) {
                current = current->next;
                printf("%s: %s\n", current->name, current->email);
            }
        }
    }
}

int main() {
    char command[50], name[50], email[100];

    while (true) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s", name, email);
            add_subscriber(name, email);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_subscriber(name);
        } else if (strcmp(command, "list") == 0) {
            print_mailing_list();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}