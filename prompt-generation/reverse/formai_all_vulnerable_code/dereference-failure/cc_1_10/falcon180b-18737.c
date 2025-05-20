//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char value[MAX_VALUE_LENGTH + 1];
} Element;

typedef struct {
    Element *elements;
    int num_elements;
} XMLParser;

void element_init(Element *element) {
    element->name[0] = '\0';
    element->value[0] = '\0';
}

void xml_parser_init(XMLParser *parser) {
    parser->elements = malloc(MAX_ELEMENTS * sizeof(Element));
    parser->num_elements = 0;
}

void xml_parser_free(XMLParser *parser) {
    free(parser->elements);
}

void xml_parser_add_element(XMLParser *parser, const char *name, const char *value) {
    if (parser->num_elements == MAX_ELEMENTS) {
        printf("Error: maximum number of elements reached.\n");
        return;
    }

    Element *element = parser->elements + parser->num_elements;
    strncpy(element->name, name, MAX_NAME_LENGTH);
    strncpy(element->value, value, MAX_VALUE_LENGTH);

    parser->num_elements++;
}

void xml_parser_print_elements(XMLParser *parser) {
    for (int i = 0; i < parser->num_elements; i++) {
        printf("Name: %s, Value: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    XMLParser parser;
    xml_parser_init(&parser);

    char input[MAX_VALUE_LENGTH + 1];
    while (fgets(input, MAX_VALUE_LENGTH, stdin)!= NULL) {
        char *name = strtok(input, " ");
        char *value = strtok(NULL, " ");

        if (name == NULL || value == NULL) {
            printf("Error: invalid input.\n");
            continue;
        }

        xml_parser_add_element(&parser, name, value);
    }

    xml_parser_print_elements(&parser);

    xml_parser_free(&parser);

    return 0;
}