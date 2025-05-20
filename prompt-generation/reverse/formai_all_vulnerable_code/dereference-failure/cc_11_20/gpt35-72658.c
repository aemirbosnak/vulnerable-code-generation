//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Define structure to hold XML element information
struct xml_element {
    char *name;
    char *value;
    struct xml_element *children;
    struct xml_element *sibling;
};

// Function to parse a single XML element
struct xml_element *parse_element(FILE *fp) {
    char buffer[BUFFER_SIZE];
    int i = 0, c;

    // Read element name
    while ((c = fgetc(fp)) != EOF && !isspace(c) && c != '>' && i < BUFFER_SIZE - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';

    // Create new XML element
    struct xml_element *elem = malloc(sizeof(struct xml_element));
    elem->name = strdup(buffer);
    elem->value = NULL;
    elem->children = NULL;
    elem->sibling = NULL;

    // Read element attributes
    while ((c = fgetc(fp)) != EOF && c != '>') {
        if (!isspace(c)) {
            ungetc(c, fp);
            i = 0;
            while ((c = fgetc(fp)) != EOF && c != '=' && c != '>') {
                buffer[i++] = c;
            }
            buffer[i] = '\0';
            if (c == '=') {
                char quote = fgetc(fp);
                i = 0;
                while ((c = fgetc(fp)) != EOF && c != quote && i < BUFFER_SIZE - 1) {
                    buffer[i++] = c;
                }
                buffer[i] = '\0';
            }
        }
    }

    // Read element value or children
    i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            if ((c = fgetc(fp)) == '/') {
                break;
            } else {
                ungetc(c, fp);
                struct xml_element *child = parse_element(fp);
                if (child != NULL) {
                    child->sibling = elem->children;
                    elem->children = child;
                }
            }
        } else {
            buffer[i++] = c;
            if (i > BUFFER_SIZE - 1) {
                break;
            }
        }
    }
    buffer[i] = '\0';

    // Set element value if not empty
    if (strlen(buffer) > 0) {
        elem->value = strdup(buffer);
    }

    return elem;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }

    struct xml_element *root = parse_element(fp);

    // Free memory
    fclose(fp);

    return 0;
}