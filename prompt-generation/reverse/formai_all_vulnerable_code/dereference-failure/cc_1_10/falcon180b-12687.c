//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000000
#define MAX_STRING_LENGTH 1000

typedef struct {
    char *key;
    int value;
} element_t;

element_t *elements = NULL;
int num_elements = 0;

void init() {
    elements = (element_t *) malloc(MAX_ELEMENTS * sizeof(element_t));
    num_elements = 0;
}

void add_element(char *key, int value) {
    element_t *new_element = (element_t *) malloc(sizeof(element_t));
    new_element->key = strdup(key);
    new_element->value = value;
    elements[num_elements++] = *new_element;
}

int search(char *key) {
    int i;
    for(i = 0; i < num_elements; i++) {
        if(strcmp(elements[i].key, key) == 0) {
            return elements[i].value;
        }
    }
    return -1;
}

int main() {
    init();
    add_element("apple", 1);
    add_element("banana", 2);
    add_element("cherry", 3);
    add_element("date", 4);
    add_element("elderberry", 5);
    add_element("fig", 6);
    add_element("grape", 7);
    add_element("honeydew", 8);
    add_element("kiwi", 9);
    add_element("lemon", 10);
    add_element("mango", 11);
    add_element("nectarine", 12);
    add_element("orange", 13);
    add_element("pear", 14);
    add_element("quince", 15);
    add_element("raspberry", 16);
    add_element("strawberry", 17);
    add_element("tangerine", 18);
    add_element("watermelon", 19);
    add_element("xylophone", 20);
    add_element("yellow", 21);
    add_element("zebra", 22);

    int value = search("banana");
    printf("Value for banana: %d\n", value);

    value = search("elephant");
    printf("Value for elephant: %d\n", value);

    return 0;
}