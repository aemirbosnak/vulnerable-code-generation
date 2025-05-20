//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct element {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element;

typedef struct {
    int num_elements;
    element elements[MAX_ELEMENTS];
} xml_parser;

void init_parser(xml_parser *parser) {
    parser->num_elements = 0;
}

int add_element(xml_parser *parser, char *name, char *value) {
    if (parser->num_elements >= MAX_ELEMENTS) {
        return -1;
    }

    strcpy(parser->elements[parser->num_elements].name, name);
    strcpy(parser->elements[parser->num_elements].value, value);

    parser->num_elements++;

    return 0;
}

void print_elements(xml_parser *parser) {
    int i;

    for (i = 0; i < parser->num_elements; i++) {
        printf("name: %s\n", parser->elements[i].name);
        printf("value: %s\n\n", parser->elements[i].value);
    }
}

int main() {
    char xml_string[1000];
    char *name = NULL;
    char *value = NULL;
    char *token = NULL;
    xml_parser parser;

    init_parser(&parser);

    printf("Enter XML string:\n");
    scanf("%s", xml_string);

    token = strtok(xml_string, "<");

    while (token!= NULL) {
        if (strncmp(token, "element", 7) == 0) {
            name = strtok(NULL, " ");
            value = strtok(NULL, ">");

            if (name!= NULL && value!= NULL) {
                add_element(&parser, name, value);
            }
        }

        token = strtok(NULL, ">");
    }

    print_elements(&parser);

    return 0;
}