//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000

typedef struct {
    char *key;
    int value;
} Element;

Element *elements = NULL;
int num_elements = 0;

int hash(char *key) {
    int hash_value = 0;
    int i = 0;
    while (key[i]) {
        hash_value += key[i];
        i++;
    }
    return hash_value % MAX_ELEMENTS;
}

void insert(char *key, int value) {
    int index = hash(key);
    Element *element = elements + index;
    while (element->key!= NULL) {
        if (strcmp(element->key, key) == 0) {
            element->value = value;
            return;
        }
        element++;
    }
    if (num_elements == MAX_ELEMENTS) {
        printf("Error: Hash table is full\n");
        return;
    }
    element->key = strdup(key);
    element->value = value;
    num_elements++;
}

int search(char *key) {
    int index = hash(key);
    Element *element = elements + index;
    while (element->key!= NULL) {
        if (strcmp(element->key, key) == 0) {
            return element->value;
        }
        element++;
    }
    return -1;
}

int main() {
    elements = (Element *) malloc(MAX_ELEMENTS * sizeof(Element));
    memset(elements, 0, MAX_ELEMENTS * sizeof(Element));
    char *key = "test";
    int value = 123;
    insert(key, value);
    int result = search(key);
    printf("Result: %d\n", result);
    free(elements);
    return 0;
}