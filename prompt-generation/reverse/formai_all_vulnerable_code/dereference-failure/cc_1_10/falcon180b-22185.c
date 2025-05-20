//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000 // Maximum number of elements in the XML document
#define MAX_NAME_LEN 100 // Maximum length of element name
#define MAX_VALUE_LEN 200 // Maximum length of element value

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element;

typedef struct {
    int size;
    element *elements;
} document;

document *create_document() {
    document *doc = (document *)malloc(sizeof(document));
    doc->size = 0;
    doc->elements = (element *)malloc(MAX_ELEMENTS * sizeof(element));
    return doc;
}

void destroy_document(document *doc) {
    free(doc->elements);
    free(doc);
}

void add_element(document *doc, char *name, char *value) {
    if (doc->size >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    element *elem = &doc->elements[doc->size];
    strcpy(elem->name, name);
    strcpy(elem->value, value);

    doc->size++;
}

int main() {
    document *doc = create_document();

    add_element(doc, "name", "John Doe");
    add_element(doc, "age", "30");
    add_element(doc, "city", "New York");

    printf("Document:\n");
    for (int i = 0; i < doc->size; i++) {
        printf("%s: %s\n", doc->elements[i].name, doc->elements[i].value);
    }

    destroy_document(doc);

    return 0;
}