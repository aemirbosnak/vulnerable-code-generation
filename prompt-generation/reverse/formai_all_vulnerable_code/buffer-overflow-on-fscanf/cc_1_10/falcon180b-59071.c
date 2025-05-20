//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *name;
    char *value;
    struct element *next;
} element;

typedef struct element_stack {
    element *head;
} element_stack;

element *current_element = NULL;
element_stack *stack = NULL;

void startElement(char *name, char *value) {
    element *newElement = (element*)malloc(sizeof(element));
    newElement->name = strdup(name);
    newElement->value = strdup(value);
    newElement->next = NULL;

    if (stack == NULL) {
        stack = (element_stack*)malloc(sizeof(element_stack));
        stack->head = newElement;
    } else {
        element *lastElement = stack->head;
        while (lastElement->next!= NULL) {
            lastElement = lastElement->next;
        }
        lastElement->next = newElement;
    }

    current_element = newElement;
}

void endElement() {
    if (current_element!= NULL) {
        current_element = current_element->next;
    }
}

void characterData(char *data) {
    if (current_element!= NULL) {
        current_element->value = strdup(data);
    }
}

void printElement() {
    element *current = stack->head;
    while (current!= NULL) {
        printf("<%s>%s</%s>\n", current->name, current->value, current->name);
        current = current->next;
    }
}

int main() {
    char input[MAX_TOKEN_LENGTH];
    FILE *file;
    file = fopen("example.xml", "r");

    if (file == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (strcmp(input, "<") == 0) {
            fscanf(file, "%s", input);
            startElement(input, "");
        } else if (strcmp(input, "/>") == 0) {
            endElement();
        } else if (strcmp(input, "</") == 0) {
            fscanf(file, "%s", input);
            endElement();
        } else if (strcmp(input, "\"") == 0) {
            fscanf(file, "%s", input);
            characterData(input);
        }
    }

    printElement();

    fclose(file);
    return 0;
}