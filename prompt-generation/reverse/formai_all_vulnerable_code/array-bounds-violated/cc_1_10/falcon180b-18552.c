//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

int num_elements = 0;
element_t elements[MAX_ELEMENTS];

void startElement(char* name) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(name, elements[i].name) == 0) {
            // Element already exists, do nothing
            return;
        }
    }
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        exit(1);
    }
    strcpy(elements[num_elements].name, name);
    num_elements++;
}

void endElement(char* name) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(name, elements[i].name) == 0) {
            // Element found, set its value
            strcpy(elements[i].value, "");
            return;
        }
    }
    // Element not found, do nothing
    return;
}

void characters(char* data) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].name, "")!= 0) {
            // Element has a name, set its value
            strcat(elements[i].value, data);
        }
    }
}

int main(int argc, char** argv) {
    FILE* file;
    char buffer[MAX_VALUE_LENGTH];
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_VALUE_LENGTH, file)!= NULL) {
        int len = strlen(buffer);
        if (buffer[len-1] == '\n') {
            buffer[--len] = '\0';
        }
        characters(buffer);
    }

    fclose(file);

    printf("XML Elements:\n");
    for (i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].name, "")!= 0 && strcmp(elements[i].value, "")!= 0) {
            printf("%s: %s\n", elements[i].name, elements[i].value);
        }
    }

    return 0;
}