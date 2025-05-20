//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
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

void init_xml(xml_t* xml) {
    xml->num_elements = 0;
}

int add_element(xml_t* xml, char* name, char* value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        return 0;
    }

    strcpy(xml->elements[xml->num_elements].name, name);
    strcpy(xml->elements[xml->num_elements].value, value);

    xml->num_elements++;

    return 1;
}

int parse_xml(xml_t* xml, char* xml_string) {
    char* start_tag = strstr(xml_string, "<");
    char* end_tag;

    while (start_tag!= NULL) {
        start_tag += 1;

        end_tag = strstr(start_tag, ">");
        if (end_tag == NULL) {
            return 0;
        }

        *end_tag = '\0';

        char* name_start = strstr(start_tag, " ");
        if (name_start == NULL) {
            return 0;
        }

        name_start += 1;

        char* value_start = strstr(name_start, " ");
        if (value_start == NULL) {
            return 0;
        }

        *value_start = '\0';

        char* name = strdup(name_start);
        char* value = strdup(value_start + 1);

        add_element(xml, name, value);

        start_tag = end_tag + 1;
    }

    return 1;
}

void print_xml(xml_t* xml) {
    printf("<?xml version=\"1.0\"?>\n");
    printf("<root>\n");

    for (int i = 0; i < xml->num_elements; i++) {
        printf("\t<%s>%s</%s>\n", xml->elements[i].name, xml->elements[i].value, xml->elements[i].name);
    }

    printf("</root>\n");
}

int main() {
    xml_t xml;
    init_xml(&xml);

    char* xml_string = "<name>John</name><age>30</age><city>New York</city>";

    if (parse_xml(&xml, xml_string)) {
        print_xml(&xml);
    } else {
        printf("Error parsing XML\n");
    }

    return 0;
}