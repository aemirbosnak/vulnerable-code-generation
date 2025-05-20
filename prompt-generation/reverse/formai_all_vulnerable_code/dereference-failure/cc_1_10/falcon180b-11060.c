//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int num_elements;
    element_t *elements;
} document_t;

document_t *create_document() {
    document_t *doc = (document_t *)malloc(sizeof(document_t));
    if (doc == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    doc->num_elements = 0;
    doc->elements = (element_t *)malloc(MAX_ELEMENTS * sizeof(element_t));
    if (doc->elements == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return doc;
}

void free_document(document_t *doc) {
    free(doc->elements);
    free(doc);
}

void add_element(document_t *doc, char *name, char *value) {
    if (doc->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached\n");
        return;
    }
    element_t *elem = &doc->elements[doc->num_elements];
    elem->name = strdup(name);
    elem->value = strdup(value);
    doc->num_elements++;
}

void print_document(document_t *doc) {
    for (int i = 0; i < doc->num_elements; i++) {
        printf("<%s>%s</%s>\n", doc->elements[i].name, doc->elements[i].value, doc->elements[i].name);
    }
}

int main() {
    document_t *doc = create_document();
    add_element(doc, "name", "John");
    add_element(doc, "age", "30");
    add_element(doc, "city", "New York");
    print_document(doc);
    free_document(doc);
    return 0;
}