//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} entry;

entry table[MAX_SIZE];
int size = 0;

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]!= '\0') {
        sum += key[i];
        i++;
    }
    return sum % MAX_SIZE;
}

void insert(char *key, int value) {
    int index = hash(key);
    int i = 0;
    while (table[index].key!= NULL && i < MAX_SIZE) {
        if (strcmp(table[index].key, key) == 0) {
            table[index].value = value;
            return;
        }
        index = (index + 1) % MAX_SIZE;
        i++;
    }
    table[index].key = strdup(key);
    table[index].value = value;
    size++;
}

int search(char *key) {
    int index = hash(key);
    int i = 0;
    while (table[index].key!= NULL && i < MAX_SIZE) {
        if (strcmp(table[index].key, key) == 0) {
            return table[index].value;
        }
        index = (index + 1) % MAX_SIZE;
        i++;
    }
    return -1;
}

void delete(char *key) {
    int index = hash(key);
    int i = 0;
    while (table[index].key!= NULL && i < MAX_SIZE) {
        if (strcmp(table[index].key, key) == 0) {
            free(table[index].key);
            table[index].key = NULL;
            table[index].value = -1;
            size--;
            return;
        }
        index = (index + 1) % MAX_SIZE;
        i++;
    }
}

void print_table() {
    int i = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (table[i].key!= NULL) {
            printf("%s %d\n", table[i].key, table[i].value);
        }
    }
}

int main() {
    int choice, value;
    char key[50];

    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Print table\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%s", key);
            value = search(key);
            if (value == -1) {
                printf("Key not found\n");
            } else {
                printf("Value: %d\n", value);
            }
            break;
        case 3:
            printf("Enter key: ");
            scanf("%s", key);
            delete(key);
            break;
        case 4:
            print_table();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}