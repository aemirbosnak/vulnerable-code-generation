//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char *name;
    char *value;
} element_t;

int num_elements = 0;
element_t elements[MAX_ELEMENTS];

void start_element(char *name) {
    element_t *element = &elements[num_elements];
    element->name = strdup(name);
    element->value = NULL;
    num_elements++;
}

void add_element_value(char *value) {
    element_t *element = &elements[num_elements - 1];
    element->value = strdup(value);
}

void end_element() {
    num_elements--;
}

int main() {
    FILE *xml_file = fopen("example.xml", "r");
    if (xml_file == NULL) {
        printf("Error opening XML file.\n");
        return 1;
    }

    char buffer[MAX_VALUE_LENGTH];
    int in_element = 0;
    char *element_name = NULL;
    while (fgets(buffer, MAX_VALUE_LENGTH, xml_file)!= NULL) {
        if (in_element) {
            if (buffer[0] == '<') {
                char *name_start = strchr(buffer, '>') + 1;
                int name_length = strlen(name_start);
                if (name_length > MAX_NAME_LENGTH) {
                    printf("Element name too long.\n");
                    return 1;
                }
                element_name = strndup(name_start, name_length);
            } else if (buffer[strlen(buffer) - 1] == '>') {
                in_element = 0;
            } else {
                add_element_value(buffer);
            }
        } else {
            if (strncmp(buffer, "<", 1) == 0) {
                in_element = 1;
            }
        }
    }

    if (in_element) {
        printf("Unclosed element.\n");
        return 1;
    }

    fclose(xml_file);

    printf("Number of elements: %d\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element %s: %s\n", elements[i].name, elements[i].value);
    }

    return 0;
}