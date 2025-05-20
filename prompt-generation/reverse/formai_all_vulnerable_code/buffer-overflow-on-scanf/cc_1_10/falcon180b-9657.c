//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *key;
    int value;
} pair;

pair table[MAX_SIZE];
int count = 0;

void insert(char *key, int value) {
    if (count >= MAX_SIZE) {
        printf("Error: table is full\n");
        exit(1);
    }
    table[count].key = strdup(key);
    table[count].value = value;
    count++;
}

int search(char *key) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(table[i].key, key) == 0) {
            return table[i].value;
        }
    }
    return -1;
}

int main() {
    char key[100];
    int value;
    while (1) {
        printf("Enter key: ");
        scanf("%s", key);
        if (strcmp(key, "exit") == 0) {
            break;
        }
        printf("Enter value: ");
        scanf("%d", &value);
        insert(key, value);
    }
    while (1) {
        printf("Enter key to search: ");
        scanf("%s", key);
        int result = search(key);
        if (result == -1) {
            printf("Key not found\n");
        } else {
            printf("Value: %d\n", result);
        }
    }
    return 0;
}