//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *tag;
    char *value;
    struct tag_value_pair *next;
} tag_value_pair;

typedef struct {
    tag_value_pair *head;
} xml_parser;

xml_parser *create_parser() {
    xml_parser *parser = (xml_parser *)malloc(sizeof(xml_parser));
    parser->head = NULL;
    return parser;
}

void destroy_parser(xml_parser *parser) {
    tag_value_pair *current = parser->head;
    while (current!= NULL) {
        tag_value_pair *temp = current->next;
        free(current->tag);
        free(current->value);
        free(current);
        current = temp;
    }
    free(parser);
}

tag_value_pair *add_tag_value_pair(xml_parser *parser, char *tag, char *value) {
    tag_value_pair *new_pair = (tag_value_pair *)malloc(sizeof(tag_value_pair));
    new_pair->tag = strdup(tag);
    new_pair->value = strdup(value);
    new_pair->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_pair;
        return parser->head;
    }

    tag_value_pair *current = parser->head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_pair;

    return new_pair;
}

void print_parser(xml_parser *parser) {
    tag_value_pair *current = parser->head;
    while (current!= NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}

int main() {
    xml_parser *parser = create_parser();

    char xml_data[] = "<book><title>Harry Potter</title><author>J.K. Rowling</author></book>";
    char *token = strtok(xml_data, "<");

    while (token!= NULL) {
        if (strcmp(token, "</book>") == 0) {
            break;
        }

        char *tag = strtok(token, ">");
        char *value = strtok(NULL, "<");

        if (tag!= NULL && value!= NULL) {
            add_tag_value_pair(parser, tag, value);
        }

        token = strtok(NULL, "<");
    }

    print_parser(parser);

    destroy_parser(parser);

    return 0;
}