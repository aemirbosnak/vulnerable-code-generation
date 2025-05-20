//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 100
#define MAX_ATTRIBUTES 10

struct element {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
    struct attribute {
        char name[MAX_ELEMENT_SIZE];
        char value[MAX_ELEMENT_SIZE];
    } attributes[MAX_ATTRIBUTES];
    int attribute_count;
};

int parse_element(FILE *file, struct element *elem) {
    char buffer[MAX_ELEMENT_SIZE];
    fscanf(file, "<%[^>]>", elem->name);

    int count = 0;
    while (fscanf(file, " %[^=]=\"%[^>]\">", elem->attributes[count].name, elem->attributes[count].value) == 2) {
        count++;
        if (count >= MAX_ATTRIBUTES) {
            printf("Too many attributes!\n");
            return -1;
        }
    }
    elem->attribute_count = count;

    fscanf(file, "%[^<]", elem->value);
    fscanf(file, "</%[^>]> ", buffer);

    if (strcmp(buffer, elem->name) != 0) {
        printf("Element names do not match!\n");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: xml_parser filename.xml\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file '%s'!\n", argv[1]);
        return -1;
    }

    struct element elem;
    while (parse_element(file, &elem) == 0) {
        printf("Found element: '%s'", elem.name);
        if (elem.attribute_count > 0) {
            printf(" with attributes:\n");
            for (int i = 0; i < elem.attribute_count; i++) {
                printf("  %s=\"%s\"\n", elem.attributes[i].name, elem.attributes[i].value);
            }
        } else {
            printf("\n");
        }
        printf("Value: '%s'\n", elem.value);
    }

    fclose(file);
    return 0;
}