//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 1000
#define MAX_TAGS 100
#define MAX_ATTR_LEN 50
#define MAX_TAG_LEN 50
#define MAX_VALUE_LEN 1000

typedef struct {
    char *tag;
    char *value;
} tag_t;

typedef struct {
    tag_t *data;
    int data_len;
    int data_size;
} parser_t;

parser_t *parser_create() {
    parser_t *parser = (parser_t *)malloc(sizeof(parser_t));
    parser->data = (tag_t *)malloc(MAX_DATA * sizeof(tag_t));
    parser->data_len = 0;
    parser->data_size = MAX_DATA;
    return parser;
}

void parser_destroy(parser_t *parser) {
    free(parser->data);
    free(parser);
}

void parser_add_tag(parser_t *parser, char *tag, char *value) {
    if (parser->data_len >= parser->data_size) {
        parser->data_size += MAX_DATA;
        parser->data = (tag_t *)realloc(parser->data, parser->data_size * sizeof(tag_t));
    }

    strcpy(parser->data[parser->data_len].tag, tag);
    strcpy(parser->data[parser->data_len].value, value);

    parser->data_len++;
}

void parser_print_data(parser_t *parser) {
    int i;
    for (i = 0; i < parser->data_len; i++) {
        printf("Tag: %s\nValue: %s\n\n", parser->data[i].tag, parser->data[i].value);
    }
}

int main() {
    parser_t *parser = parser_create();

    char xml_data[] = "<root>\n\t<tag1>value1</tag1>\n\t<tag2 attr=\"value\">value2</tag2>\n</root>";

    char *token = strtok(xml_data, "<");
    while (token!= NULL) {
        if (strcmp(token, "</") == 0) {
            char *tag_name = strtok(NULL, ">");
            int tag_index = -1;

            for (int i = 0; i < parser->data_len; i++) {
                if (strcmp(parser->data[i].tag, tag_name) == 0) {
                    tag_index = i;
                    break;
                }
            }

            if (tag_index!= -1) {
                parser->data_len--;
                for (int j = tag_index; j < parser->data_len; j++) {
                    parser->data[j] = parser->data[j + 1];
                }
            }
        } else {
            char *tag_name = token;
            char *value = strtok(NULL, ">");

            parser_add_tag(parser, tag_name, value);
        }

        token = strtok(NULL, ">");
    }

    parser_print_data(parser);

    parser_destroy(parser);

    return 0;
}