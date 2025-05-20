//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_SIZE 100

typedef struct {
    char *name;
    char *value;
} element_t;

element_t elements[MAX_ELEMENTS];
int num_elements = 0;

void start_element(const char *name, const char *value) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements.\n");
        exit(1);
    }

    element_t *elem = &elements[num_elements++];
    elem->name = strdup(name);
    elem->value = strdup(value);
}

void end_element() {
}

void characters(const char *chars, int len) {
    if (num_elements > 0 && num_elements < MAX_ELEMENTS) {
        element_t *elem = &elements[num_elements - 1];
        elem->value = realloc(elem->value, strlen(elem->value) + len + 1);
        strcat(elem->value, chars);
    }
}

void print_elements() {
    for (int i = 0; i < num_elements; i++) {
        printf("Name: %s\nValue: %s\n", elements[i].name, elements[i].value);
    }
}

int main() {
    start_element("root", "");
    start_element("child1", "value1");
    start_element("child2", "value2");
    characters("Some text", 9);
    end_element();
    end_element();
    print_elements();

    return 0;
}