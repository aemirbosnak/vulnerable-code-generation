//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_NAME_LENGTH 100
#define MAX_ELEMENT_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} xml_t;

xml_t *xml_parse(char *xml_data) {
    xml_t *result = malloc(sizeof(xml_t));
    result->elements = malloc(MAX_ELEMENTS * sizeof(element_t));
    result->num_elements = 0;

    char *current_element = strtok(xml_data, "<");
    while (current_element!= NULL) {
        if (result->num_elements >= MAX_ELEMENTS) {
            printf("Error: Too many elements in XML.\n");
            exit(1);
        }

        element_t *new_element = malloc(sizeof(element_t));
        strncpy(new_element->name, current_element, MAX_ELEMENT_NAME_LENGTH);
        new_element->name[MAX_ELEMENT_NAME_LENGTH - 1] = '\0';
        strncpy(new_element->value, "", MAX_ELEMENT_VALUE_LENGTH);

        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: Missing closing tag for element.\n");
            exit(1);
        }

        char *value_start = strchr(current_element, '>') + 1;
        strncat(new_element->value, value_start, MAX_ELEMENT_VALUE_LENGTH - strlen(new_element->value) - 1);
        new_element->value[MAX_ELEMENT_VALUE_LENGTH - 1] = '\0';

        result->elements[result->num_elements++] = *new_element;
    }

    return result;
}

void xml_print(xml_t *xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        printf("<%s>%s</%s>\n", xml->elements[i].name, xml->elements[i].value, xml->elements[i].name);
    }
}

int main() {
    char xml_data[1000] = "<root><element1>Value1</element1><element2>Value2</element2></root>";
    xml_t *xml = xml_parse(xml_data);
    xml_print(xml);
    free(xml->elements);
    free(xml);
    return 0;
}