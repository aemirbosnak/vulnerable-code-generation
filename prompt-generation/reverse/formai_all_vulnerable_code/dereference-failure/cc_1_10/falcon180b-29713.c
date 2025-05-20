//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_LENGTH 100

typedef struct element {
    char name[MAX_ELEMENT_LENGTH];
    char value[MAX_ELEMENT_LENGTH];
    struct element *next;
} element_t;

element_t *head = NULL;
element_t *tail = NULL;

void add_element(char *name, char *value) {
    element_t *new_element = (element_t *)malloc(sizeof(element_t));
    strcpy(new_element->name, name);
    strcpy(new_element->value, value);
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
        tail = new_element;
    } else {
        tail->next = new_element;
        tail = new_element;
    }
}

void print_elements() {
    element_t *current_element = head;

    while (current_element!= NULL) {
        printf("%s: %s\n", current_element->name, current_element->value);
        current_element = current_element->next;
    }
}

int main() {
    char input[MAX_ELEMENT_LENGTH];
    char *name_start, *value_start, *name_end, *value_end;
    int in_name = 0, in_value = 0;

    printf("Enter XML data:\n");
    fgets(input, MAX_ELEMENT_LENGTH, stdin);

    name_start = input;
    value_start = input;
    name_end = strchr(input, '>');
    if (name_end!= NULL) {
        *name_end = '\0';
        value_end = strchr(name_end + 1, '<');
        if (value_end!= NULL) {
            *value_end = '\0';
            add_element(name_start + 1, value_start + 1);
        }
    }

    while (fgets(input, MAX_ELEMENT_LENGTH, stdin)!= NULL) {
        name_start = strchr(input, '<');
        if (name_start!= NULL) {
            value_start = strchr(name_start + 1, '>');
            if (value_start!= NULL) {
                name_end = strchr(value_start + 1, '<');
                if (name_end!= NULL) {
                    value_end = strchr(name_end + 1, '>');
                    if (value_end!= NULL) {
                        *value_end = '\0';
                        add_element(name_start + 1, value_start + 1);
                    }
                }
            }
        }
    }

    print_elements();

    return 0;
}