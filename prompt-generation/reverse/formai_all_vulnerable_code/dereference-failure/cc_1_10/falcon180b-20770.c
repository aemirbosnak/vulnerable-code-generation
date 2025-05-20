//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 200

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} xml_t;

xml_t *xml_parse(char *xml_string) {
    xml_t *xml = (xml_t*)malloc(sizeof(xml_t));
    xml->elements = (element_t*)malloc(MAX_ELEMENTS * sizeof(element_t));
    xml->num_elements = 0;

    char *current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element_t *element = &(xml->elements[xml->num_elements]);
        strcpy(element->name, current_element);
        current_element = strtok(NULL, ">");

        char *value_start = strtok(current_element, "<");
        if (value_start == NULL) {
            strcpy(element->value, "");
        } else {
            strcpy(element->value, value_start);
        }

        xml->num_elements++;
        current_element = strtok(NULL, ">");
    }

    return xml;
}

void xml_print(xml_t *xml) {
    printf("<xml>\n");
    for (int i = 0; i < xml->num_elements; i++) {
        printf("<%s>%s</%s>\n", xml->elements[i].name, xml->elements[i].value, xml->elements[i].name);
    }
    printf("</xml>\n");
}

int main() {
    char *xml_string = "<name>John</name><age>30</age><city>New York</city>";
    xml_t *xml = xml_parse(xml_string);
    xml_print(xml);

    free(xml->elements);
    free(xml);
    return 0;
}