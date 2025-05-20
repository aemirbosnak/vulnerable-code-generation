//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct element {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct element *next;
} Element;

Element *head = NULL;

void add_element(char *name, char *value) {
    Element *new_element = (Element*)malloc(sizeof(Element));
    strcpy(new_element->name, name);
    strcpy(new_element->value, value);
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        Element *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_elements() {
    Element *current = head;
    while (current!= NULL) {
        printf("%s: %s\n", current->name, current->value);
        current = current->next;
    }
}

int main() {
    char input[MAX_ELEMENTS][MAX_VALUE_LENGTH];
    int num_elements = 0;

    while (num_elements < MAX_ELEMENTS) {
        printf("Enter element (name:value): ");
        scanf("%s", input[num_elements]);

        char delimiter = ':';
        char *name = strtok(input[num_elements], &delimiter);
        char *value = strtok(NULL, &delimiter);

        add_element(name, value);
        num_elements++;
    }

    print_elements();

    return 0;
}