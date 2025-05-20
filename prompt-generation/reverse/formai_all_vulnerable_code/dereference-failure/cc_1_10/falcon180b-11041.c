//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct element_t {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct element_t *next;
} element_t;

typedef struct {
    element_t *head;
} element_list_t;

element_t *create_element(char *name, char *value) {
    element_t *element = malloc(sizeof(element_t));
    strncpy(element->name, name, MAX_NAME_LENGTH);
    strncpy(element->value, value, MAX_VALUE_LENGTH);
    element->next = NULL;
    return element;
}

void add_element(element_list_t *list, char *name, char *value) {
    element_t *element = create_element(name, value);
    if (list->head == NULL) {
        list->head = element;
    } else {
        element_t *current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = element;
    }
}

void print_element(element_t *element) {
    printf("Name: %s\nValue: %s\n", element->name, element->value);
}

void print_element_list(element_list_t *list) {
    element_t *current = list->head;
    while (current!= NULL) {
        print_element(current);
        current = current->next;
    }
}

int main() {
    element_list_t element_list;
    element_list.head = NULL;

    add_element(&element_list, "name", "John");
    add_element(&element_list, "age", "30");
    add_element(&element_list, "gender", "Male");

    print_element_list(&element_list);

    return 0;
}