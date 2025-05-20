//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 200

typedef struct element {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Element;

Element elements[MAX_ELEMENTS];
int num_elements = 0;

char *read_value(char *str) {
    char *value = str;
    while (*str!= '"' && *str!= '\0') {
        str++;
    }
    if (*str == '"') {
        *str = '\0';
        str++;
    }
    return value;
}

void add_element(char *name, char *value) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements\n");
        return;
    }
    strcpy(elements[num_elements].name, name);
    strcpy(elements[num_elements].value, value);
    num_elements++;
}

void print_elements() {
    printf("<root>\n");
    for (int i = 0; i < num_elements; i++) {
        printf("  <%s>%s</%s>\n", elements[i].name, elements[i].value, elements[i].name);
    }
    printf("</root>\n");
}

int main() {
    FILE *fp;
    char ch;
    char *token = NULL;
    size_t len = 0;
    ssize_t read;
    int in_tag = 0;
    int in_value = 0;
    char tag_buffer[MAX_NAME_LEN];

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while ((read = getline(&token, &len, fp))!= -1) {
        if (token[0] == '<') {
            in_tag = 1;
        } else if (token[0] == '>') {
            in_tag = 0;
        } else if (in_tag) {
            strncat(tag_buffer, token, len);
            tag_buffer[len] = '\0';
        } else if (in_value) {
            strncat(elements[num_elements - 1].value, token, len);
            elements[num_elements - 1].value[len] = '\0';
        } else if (token[0] == '=') {
            in_value = 1;
        }
    }

    free(token);
    fclose(fp);

    print_elements();

    return 0;
}