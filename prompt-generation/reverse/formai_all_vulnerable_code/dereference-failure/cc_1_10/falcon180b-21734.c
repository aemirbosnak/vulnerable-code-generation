//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* parse_xml(char* xml_data) {
    xml_t* xml = malloc(sizeof(xml_t));
    xml->num_elements = 0;
    char* current_element = strtok(xml_data, "<");
    while(current_element!= NULL) {
        element_t* element = malloc(sizeof(element_t));
        strcpy(element->name, current_element);
        current_element = strtok(NULL, ">");
        if(current_element == NULL) {
            free(element);
            break;
        }
        current_element = strtok(NULL, "<");
        if(current_element == NULL) {
            free(element);
            break;
        }
        strcpy(element->value, current_element);
        xml->elements[xml->num_elements++] = *element;
        free(element);
    }
    return xml;
}

void print_xml(xml_t* xml) {
    printf("Number of elements: %d\n", xml->num_elements);
    for(int i = 0; i < xml->num_elements; i++) {
        printf("Element %d:\n", i+1);
        printf("  Name: %s\n", xml->elements[i].name);
        printf("  Value: %s\n", xml->elements[i].value);
    }
}

int main() {
    char xml_data[] = "<element1>value1</element1><element2>value2</element2><element3>value3</element3>";
    xml_t* xml = parse_xml(xml_data);
    print_xml(xml);
    free(xml);
    return 0;
}