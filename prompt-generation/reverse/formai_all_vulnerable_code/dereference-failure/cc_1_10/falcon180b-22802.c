//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element;

typedef struct {
    int size;
    element elements[MAX_ELEMENTS];
} xml_document;

xml_document *create_document() {
    xml_document *doc = (xml_document *) malloc(sizeof(xml_document));
    doc->size = 0;
    return doc;
}

void add_element(xml_document *doc, char *name, char *value) {
    element *new_element = (element *) malloc(sizeof(element));
    strcpy(new_element->name, name);
    strcpy(new_element->value, value);
    doc->elements[doc->size++] = *new_element;
}

void print_document(xml_document *doc) {
    printf("<document>\n");
    for (int i = 0; i < doc->size; i++) {
        printf("  <%s>%s</%s>\n", doc->elements[i].name, doc->elements[i].value, doc->elements[i].name);
    }
    printf("</document>\n");
}

int main() {
    char input[MAX_VALUE_LENGTH];
    xml_document *doc = create_document();

    printf("Enter XML data:\n");
    while (fgets(input, MAX_VALUE_LENGTH, stdin)!= NULL) {
        char *name = strtok(input, " ");
        char *value = strtok(NULL, " ");

        while (name!= NULL && value!= NULL) {
            add_element(doc, name, value);
            name = strtok(NULL, " ");
            value = strtok(NULL, " ");
        }
    }

    print_document(doc);

    free(doc);
    return 0;
}