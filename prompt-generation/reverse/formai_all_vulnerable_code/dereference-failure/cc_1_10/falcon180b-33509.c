//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: surprised
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
    element *elements;
} xml;

xml *parse_xml(char *xml_string) {
    xml *result = malloc(sizeof(xml));
    result->size = 0;
    result->elements = malloc(MAX_ELEMENTS * sizeof(element));

    char *current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element *e = &result->elements[result->size];
        strncpy(e->name, current_element, MAX_NAME_LENGTH);

        char *value_start = strchr(current_element, '>') + 1;
        strncpy(e->value, value_start, MAX_VALUE_LENGTH);

        current_element = strtok(NULL, ">");
        result->size++;
    }

    return result;
}

void print_xml(xml *xml) {
    for (int i = 0; i < xml->size; i++) {
        element *e = &xml->elements[i];
        printf("<%s>%s</%s>\n", e->name, e->value, e->name);
    }
}

int main() {
    char xml_string[] = "<name>John</name><age>30</age><city>New York</city>";
    xml *xml = parse_xml(xml_string);
    print_xml(xml);
    free(xml->elements);
    free(xml);
    return 0;
}