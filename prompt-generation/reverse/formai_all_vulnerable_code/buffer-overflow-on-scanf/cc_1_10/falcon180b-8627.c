//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element;

typedef struct {
    int num_elements;
    element elements[MAX_ELEMENTS];
} xml_document;

xml_document* parse_xml(char* xml_string) {
    xml_document* doc = (xml_document*)malloc(sizeof(xml_document));
    doc->num_elements = 0;

    char* current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element* new_element = (element*)malloc(sizeof(element));
        strcpy(new_element->name, current_element);
        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: Missing closing tag for element %s\n", new_element->name);
            exit(1);
        }
        current_element += 1; // Skip the '>' character
        while (*current_element!= '<') {
            if (*current_element == '&') {
                current_element += 1; // Skip the '&' character
                char* entity_start = current_element;
                while (*current_element!= ';') {
                    current_element += 1;
                }
                char* entity_value = current_element + 1;
                while (*entity_value!= ';') {
                    entity_value += 1;
                }
                *entity_value = '\0';
                strcat(new_element->value, entity_value + 1);
                current_element = entity_start + 1;
            } else {
                strcat(new_element->value, current_element);
                current_element += 1;
            }
        }
        doc->elements[doc->num_elements++] = *new_element;
    }

    return doc;
}

void print_xml_document(xml_document* doc) {
    printf("<xml>\n");
    for (int i = 0; i < doc->num_elements; i++) {
        printf("<%s>%s</%s>\n", doc->elements[i].name, doc->elements[i].value, doc->elements[i].name);
    }
    printf("</xml>\n");
}

int main() {
    char xml_string[1000];
    printf("Enter XML string: ");
    scanf("%[^\n]", xml_string);

    xml_document* doc = parse_xml(xml_string);
    print_xml_document(doc);

    free(doc);
    return 0;
}