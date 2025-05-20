//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT_NAME_LENGTH 100
#define MAX_ELEMENT_VALUE_LENGTH 1000
#define MAX_ELEMENT_COUNT 1000

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
    int depth;
} Element;

int main() {
    char *xml = "<root>\n<child1>This is child 1</child1>\n<child2>This is child 2</child2>\n<child3>This is child 3</child3>\n</root>";
    int xml_length = strlen(xml);
    Element elements[MAX_ELEMENT_COUNT];
    int element_count = 0;

    int current_depth = 0;
    int current_element_index = -1;
    char current_element_name[MAX_ELEMENT_NAME_LENGTH] = {0};
    char current_element_value[MAX_ELEMENT_VALUE_LENGTH] = {0};

    for (int i = 0; i < xml_length; i++) {
        char c = xml[i];

        if (c == '<') {
            current_element_index++;
            elements[current_element_index].depth = current_depth;

            if (xml[i + 1] == '/') {
                i += 2;

                while (xml[i] != '>') {
                    current_element_name[strlen(current_element_name)] = xml[i];
                    i++;
                }

                elements[current_element_index].name[strlen(elements[current_element_index].name)] = '\0';
                current_depth--;
            } else {
                i++;

                while (xml[i] != '>') {
                    current_element_name[strlen(current_element_name)] = xml[i];
                    i++;
                }

                elements[current_element_index].name[strlen(elements[current_element_index].name)] = '\0';
                current_depth++;
            }
        } else if (c == '>') {
            if (current_element_value[0] != '\0') {
                elements[current_element_index].value[strlen(elements[current_element_index].value)] = '\0';
            }

            current_element_value[0] = '\0';
        } else {
            if (current_element_index >= 0) {
                current_element_value[strlen(current_element_value)] = c;
            }
        }
    }

    for (int i = 0; i < current_element_index + 1; i++) {
        printf("%s: %s\n", elements[i].name, elements[i].value);
    }

    return 0;
}