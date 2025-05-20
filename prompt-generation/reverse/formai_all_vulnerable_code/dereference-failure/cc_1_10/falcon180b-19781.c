//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_STRING_LENGTH 1000

struct element {
    char* name;
    char* value;
    struct element* next;
};

struct element* root = NULL;

void startElement(char* name, char* value) {
    struct element* newElement = (struct element*) malloc(sizeof(struct element));
    newElement->name = name;
    newElement->value = value;
    newElement->next = NULL;
    if (root == NULL) {
        root = newElement;
    } else {
        struct element* current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void endElement(char* name) {
    struct element* current = root;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            current->next = NULL;
            return;
        }
        current = current->next;
    }
}

void characters(char* value) {
    struct element* current = root;
    while (current!= NULL) {
        if (current->value == NULL) {
            current->value = value;
            return;
        }
        current = current->next;
    }
}

void parse(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", fileName);
        exit(1);
    }
    char buffer[MAX_STRING_LENGTH];
    while (fgets(buffer, MAX_STRING_LENGTH, file)!= NULL) {
        char* name = strtok(buffer, " ");
        char* value = strtok(NULL, " ");
        startElement(name, value);
    }
    fclose(file);
}

void print(struct element* element) {
    while (element!= NULL) {
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
        element = element->next;
    }
}

int main() {
    root = NULL;
    parse("example.xml");
    print(root);
    return 0;
}