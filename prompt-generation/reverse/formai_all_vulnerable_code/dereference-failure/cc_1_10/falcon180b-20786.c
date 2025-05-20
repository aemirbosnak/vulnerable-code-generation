//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_SIZE 1000

typedef struct element {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* parse_xml(char* xml_str) {
    xml_t* xml = malloc(sizeof(xml_t));
    if (xml == NULL) {
        printf("Error: could not allocate memory for XML object.\n");
        return NULL;
    }

    xml->num_elements = 0;
    char* current_element = strtok(xml_str, "<");
    while (current_element!= NULL) {
        if (xml->num_elements >= MAX_ELEMENTS) {
            printf("Error: maximum number of elements exceeded.\n");
            free(xml);
            return NULL;
        }

        element_t* element = &xml->elements[xml->num_elements];
        strcpy(element->name, current_element);
        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: malformed XML.\n");
            free(xml);
            return NULL;
        }

        current_element = strtok(current_element, "<");
        if (current_element == NULL) {
            printf("Error: malformed XML.\n");
            free(xml);
            return NULL;
        }

        strcpy(element->value, current_element);
        xml->num_elements++;

        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: malformed XML.\n");
            free(xml);
            return NULL;
        }
    }

    return xml;
}

void print_xml(xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t* element = &xml->elements[i];
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
    }
}

int main() {
    char* xml_str = "<root><element1>value1</element1><element2>value2</element2></root>";
    xml_t* xml = parse_xml(xml_str);
    if (xml!= NULL) {
        print_xml(xml);
        free(xml);
    }

    return 0;
}