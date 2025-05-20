//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_LENGTH 100

typedef struct element {
    char *name;
    char *value;
    struct element *next;
} Element;

Element *root = NULL;

void startElement(char *name) {
    Element *element = (Element*)malloc(sizeof(Element));
    element->name = strdup(name);
    element->value = NULL;
    element->next = NULL;

    if (root == NULL) {
        root = element;
    } else {
        Element *current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = element;
    }
}

void endElement(char *name) {
    Element *current = root;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            current->value = strdup("");
            return;
        }
        current = current->next;
    }
}

void characterData(char *data) {
    Element *current = root;
    while (current!= NULL) {
        if (current->value == NULL) {
            current->value = strdup(data);
            break;
        }
        current = current->next;
    }
}

void printElement(Element *element) {
    printf("<%s>", element->name);
    if (element->value!= NULL) {
        printf("%s", element->value);
    }
    printf("</%s>", element->name);
}

void printXML(Element *element) {
    if (element == NULL) {
        return;
    }

    printElement(element);

    Element *current = element->next;
    while (current!= NULL) {
        printXML(current);
        current = current->next;
    }
}

int main() {
    char xmlData[] = "<book><title>Harry Potter</title><author>J.K. Rowling</author></book>";

    startElement("book");

    characterData("Harry Potter");
    characterData("J.K. Rowling");

    endElement("book");

    printXML(root);

    return 0;
}