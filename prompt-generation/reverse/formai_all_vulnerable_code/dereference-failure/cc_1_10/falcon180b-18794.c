//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_ATTRIBUTES 10

typedef struct element {
    char name[50];
    int num_attributes;
    char attributes[MAX_ATTRIBUTES][50];
} Element;

typedef struct {
    Element elements[MAX_ELEMENTS];
    int num_elements;
} XMLDoc;

XMLDoc* create_document() {
    XMLDoc* doc = (XMLDoc*) malloc(sizeof(XMLDoc));
    doc->num_elements = 0;
    return doc;
}

void add_element(XMLDoc* doc, char* name, int num_attributes, char** attributes) {
    Element* element = &doc->elements[doc->num_elements];
    strcpy(element->name, name);
    element->num_attributes = num_attributes;
    for (int i = 0; i < num_attributes; i++) {
        strcpy(element->attributes[i], attributes[i]);
    }
    doc->num_elements++;
}

void print_document(XMLDoc* doc) {
    for (int i = 0; i < doc->num_elements; i++) {
        Element* element = &doc->elements[i];
        printf("<%s", element->name);
        for (int j = 0; j < element->num_attributes; j++) {
            printf(" %s=\"%s\"", element->attributes[j], element->attributes[j]);
        }
        printf(">\n");
        for (int j = 0; j < element->num_attributes; j++) {
            printf("\t%s=\"%s\"\n", element->attributes[j], element->attributes[j]);
        }
        printf("</%s>\n\n", element->name);
    }
}

int main() {
    XMLDoc* doc = create_document();
    add_element(doc, "person", 2, (char**) {"name", "John"});
    add_element(doc, "person", 3, (char**) {"name", "Jane", "age", "25"});
    print_document(doc);
    return 0;
}