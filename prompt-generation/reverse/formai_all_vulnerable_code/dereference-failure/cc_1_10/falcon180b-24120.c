//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Element;

typedef struct {
    Element elements[MAX_ELEMENTS];
    int num_elements;
} XMLData;

XMLData* create_xml_data() {
    XMLData* data = (XMLData*)malloc(sizeof(XMLData));
    data->num_elements = 0;
    return data;
}

void destroy_xml_data(XMLData* data) {
    free(data);
}

void add_element(XMLData* data, char* name, char* value) {
    if (data->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    Element* element = &data->elements[data->num_elements];
    strncpy(element->name, name, MAX_NAME_LENGTH-1);
    strncpy(element->value, value, MAX_VALUE_LENGTH-1);
    data->num_elements++;
}

int main() {
    XMLData* data = create_xml_data();

    add_element(data, "name", "John Doe");
    add_element(data, "age", "30");
    add_element(data, "city", "New York");

    printf("Name: %s\n", data->elements[0].value);
    printf("Age: %s\n", data->elements[1].value);
    printf("City: %s\n", data->elements[2].value);

    destroy_xml_data(data);

    return 0;
}