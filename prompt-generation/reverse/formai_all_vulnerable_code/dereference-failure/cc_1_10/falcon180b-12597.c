//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 100
#define MAX_ATTRIBUTE_SIZE 50
#define MAX_ELEMENTS 1000

typedef struct {
    char *name;
    char *value;
} attribute_t;

typedef struct {
    char *name;
    int num_attributes;
    attribute_t *attributes;
} element_t;

typedef struct {
    int num_elements;
    element_t *elements;
} document_t;

document_t *parse_xml(char *xml_string) {
    document_t *doc = (document_t *)malloc(sizeof(document_t));
    doc->num_elements = 0;
    doc->elements = (element_t *)malloc(MAX_ELEMENTS * sizeof(element_t));

    char *current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element_t *current_doc_element = &doc->elements[doc->num_elements];
        strcpy(current_doc_element->name, current_element);
        current_doc_element->num_attributes = 0;
        current_doc_element->attributes = (attribute_t *)malloc(MAX_ATTRIBUTE_SIZE * sizeof(attribute_t));

        char *current_attribute = strtok(NULL, " ");
        while (current_attribute!= NULL) {
            attribute_t *current_attribute_value = &current_doc_element->attributes[current_doc_element->num_attributes];
            strcpy(current_attribute_value->name, current_attribute);
            current_attribute_value->value = strtok(NULL, " ");
            current_doc_element->num_attributes++;
            current_attribute = strtok(NULL, " ");
        }

        current_element = strtok(NULL, ">");
        doc->num_elements++;
    }

    return doc;
}

void print_document(document_t *doc) {
    for (int i = 0; i < doc->num_elements; i++) {
        element_t *current_element = &doc->elements[i];
        printf("<%s", current_element->name);

        for (int j = 0; j < current_element->num_attributes; j++) {
            attribute_t *current_attribute = &current_element->attributes[j];
            printf(" %s=\"%s\"", current_attribute->name, current_attribute->value);
        }

        printf(">");

        for (int k = 0; k < current_element->num_attributes; k++) {
            attribute_t *current_attribute = &current_element->attributes[k];
            printf("%s=\"%s\" ", current_attribute->name, current_attribute->value);
        }

        printf("</%s>", current_element->name);
    }
}

int main() {
    char *xml_string = "<person name=\"John\" age=\"30\">"
                        "<city>New York</city>"
                        "<country>USA</country>"
                        "</person>";

    document_t *doc = parse_xml(xml_string);
    print_document(doc);

    return 0;
}