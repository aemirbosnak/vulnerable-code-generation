//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element;

typedef struct {
    element *elements;
    int num_elements;
} document;

document *create_document() {
    document *doc = (document *)malloc(sizeof(document));
    doc->elements = (element *)malloc(MAX_ELEMENTS * sizeof(element));
    doc->num_elements = 0;
    return doc;
}

void add_element(document *doc, char *name, char *value) {
    if (doc->num_elements >= MAX_ELEMENTS) {
        printf("Error: maximum number of elements reached.\n");
        return;
    }
    element *elem = &doc->elements[doc->num_elements];
    strcpy(elem->name, name);
    strcpy(elem->value, value);
    doc->num_elements++;
}

void print_document(document *doc) {
    for (int i = 0; i < doc->num_elements; i++) {
        printf("%s: %s\n", doc->elements[i].name, doc->elements[i].value);
    }
}

void destroy_document(document *doc) {
    free(doc->elements);
    free(doc);
}

int main() {
    document *doc = create_document();
    add_element(doc, "name", "John");
    add_element(doc, "age", "30");
    print_document(doc);
    destroy_document(doc);
    return 0;
}