//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element_t;

int num_elements = 0;
element_t elements[MAX_ELEMENTS];

void startElement(char* name) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: too many elements\n");
        return;
    }
    strcpy(elements[num_elements].name, name);
    num_elements++;
}

void endElement(char* name) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].name, name) == 0) {
            printf("Element '%s' has value '%s'\n", elements[i].name, elements[i].value);
            num_elements--;
            break;
        }
    }
}

void characters(char* ch, int len) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].name, "")!= 0) {
            strncat(elements[i].value, ch, len);
        }
    }
}

int main() {
    FILE* fp;
    char ch;
    int len;

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        len = 0;
        while (ch!= '<') {
            if (len >= MAX_VALUE_LEN - 1) {
                printf("Error: value too long\n");
                exit(1);
            }
            elements[num_elements - 1].value[len++] = ch;
            ch = fgetc(fp);
        }
        ch = fgetc(fp);
        if (ch == '/') {
            endElement(elements[num_elements - 1].name);
        } else {
            startElement(elements[num_elements - 1].name);
        }
    }

    fclose(fp);

    return 0;
}