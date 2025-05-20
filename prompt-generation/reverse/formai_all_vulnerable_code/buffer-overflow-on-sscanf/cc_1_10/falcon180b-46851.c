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

int num_elements = 0;
element_t *elements = NULL;

void add_element(char *name, char *value) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements\n");
        return;
    }

    num_elements++;
    elements = realloc(elements, sizeof(element_t) * num_elements);

    strcpy(elements[num_elements - 1].name, name);
    strcpy(elements[num_elements - 1].value, value);
}

void print_elements() {
    int i;

    for (i = 0; i < num_elements; i++) {
        printf("Name: %s\nValue: %s\n", elements[i].name, elements[i].value);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char buf[MAX_VALUE_LENGTH];
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        if (sscanf(buf, "<%[^>]>%[^\n]", name, value) == 2) {
            add_element(name, value);
        }
    }

    fclose(fp);
    print_elements();

    return 0;
}