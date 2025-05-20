//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_NAME_LENGTH 50
#define MAX_ELEMENT_VALUE_LENGTH 200

typedef struct {
    char* name;
    char* value;
} element_t;

typedef struct {
    int count;
    element_t* elements;
} element_list_t;

element_list_t* create_element_list() {
    element_list_t* list = (element_list_t*)malloc(sizeof(element_list_t));
    list->count = 0;
    list->elements = (element_t*)malloc(MAX_ELEMENTS * sizeof(element_t));
    return list;
}

void add_element(element_list_t* list, char* name, char* value) {
    if (list->count >= MAX_ELEMENTS) {
        printf("Error: maximum number of elements reached.\n");
        return;
    }

    element_t* element = &list->elements[list->count];
    strncpy(element->name, name, MAX_ELEMENT_NAME_LENGTH);
    strncpy(element->value, value, MAX_ELEMENT_VALUE_LENGTH);
    list->count++;
}

void print_element_list(element_list_t* list) {
    for (int i = 0; i < list->count; i++) {
        element_t* element = &list->elements[i];
        printf("Name: %s\nValue: %s\n", element->name, element->value);
    }
}

int main() {
    char* xml_text = "<root>\n"
                      "  <element name=\"foo\">bar</element>\n"
                      "  <element name=\"baz\">qux</element>\n"
                      "</root>";

    element_list_t* list = create_element_list();

    char* current_element_name = NULL;
    char* current_element_value = NULL;
    int current_element_name_length = 0;
    int current_element_value_length = 0;

    char* xml_text_copy = strdup(xml_text);
    char* token = strtok(xml_text_copy, ">");

    while (token!= NULL) {
        if (current_element_name == NULL) {
            current_element_name = strdup(token);
            current_element_name_length = strlen(current_element_name);
        } else if (current_element_value == NULL) {
            current_element_value = strdup(token);
            current_element_value_length = strlen(current_element_value);
        } else {
            add_element(list, current_element_name, current_element_value);
            current_element_name = NULL;
            current_element_value = NULL;
        }

        free(token);
        token = strtok(NULL, ">");
    }

    if (current_element_name!= NULL) {
        add_element(list, current_element_name, current_element_value);
    }

    print_element_list(list);

    return 0;
}