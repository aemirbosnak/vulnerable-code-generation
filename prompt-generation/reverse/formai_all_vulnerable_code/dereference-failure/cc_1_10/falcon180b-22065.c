//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_parser_t;

xml_parser_t *create_parser() {
    xml_parser_t *parser = (xml_parser_t *)malloc(sizeof(xml_parser_t));
    parser->num_elements = 0;
    return parser;
}

void destroy_parser(xml_parser_t *parser) {
    for (int i = 0; i < parser->num_elements; i++) {
        free(parser->elements[i].name);
        free(parser->elements[i].value);
    }
    free(parser);
}

void add_element(xml_parser_t *parser, char *name, char *value) {
    if (parser->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached\n");
        return;
    }

    element_t *new_element = (element_t *)malloc(sizeof(element_t));
    new_element->name = strdup(name);
    new_element->value = strdup(value);

    parser->elements[parser->num_elements++] = *new_element;
}

void print_parser(xml_parser_t *parser) {
    for (int i = 0; i < parser->num_elements; i++) {
        printf("Name: %s, Value: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser_t *parser = create_parser();

    add_element(parser, "name", "John");
    add_element(parser, "age", "30");
    add_element(parser, "city", "New York");

    print_parser(parser);

    destroy_parser(parser);

    return 0;
}