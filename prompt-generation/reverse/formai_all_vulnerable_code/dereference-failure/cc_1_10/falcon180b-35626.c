//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* create_xml() {
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    if (xml == NULL) {
        printf("Error: Could not allocate memory for XML object.\n");
        return NULL;
    }
    xml->num_elements = 0;
    return xml;
}

void add_element(xml_t* xml, const char* name, const char* value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    strncpy(xml->elements[xml->num_elements].name, name, MAX_NAME_LENGTH);
    strncpy(xml->elements[xml->num_elements].value, value, MAX_VALUE_LENGTH);
    xml->num_elements++;
}

void print_xml(xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        printf("Element %d:\n", i);
        printf("  Name: %s\n", xml->elements[i].name);
        printf("  Value: %s\n", xml->elements[i].value);
        printf("\n");
    }
}

int main() {
    xml_t* xml = create_xml();
    add_element(xml, "name", "John Doe");
    add_element(xml, "age", "30");
    add_element(xml, "city", "New York");
    print_xml(xml);
    free(xml);
    return 0;
}