//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure for the parser
typedef struct {
    char *data;
    int len;
    struct parser *next;
} parser;

// Define a function to create a new parser
parser *create_parser(char *data) {
    parser *p = (parser *)malloc(sizeof(parser));
    p->data = data;
    p->len = strlen(data);
    p->next = NULL;
    return p;
}

// Define a function to add a child parser
void add_child(parser *parent, parser *child) {
    child->next = parent->next;
    parent->next = child;
}

// Define a function to print the parser tree
void print_tree(parser *root) {
    parser *p = root;
    while (p!= NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }
}

// Define a function to parse an XML string
parser *parse(char *data) {
    parser *root = create_parser(data);
    parser *p = root;
    int level = 0;

    // Loop through the string and parse the tags
    while (*data!= '\0') {
        if (*data == '<') {
            // Opening tag
            data++;
            char *tag = data;
            while (isalnum(*data) || *data == '_' || *data == '-') {
                data++;
            }
            *data = '\0';
            parser *child = create_parser(tag);
            add_child(p, child);
            p = child;
            level++;
        } else if (*data == '>') {
            // Closing tag
            data++;
            if (level > 0) {
                level--;
            } else {
                p = p->next;
            }
        } else if (*data == '&') {
            // Entity reference
            data++;
            char *ref = data;
            while (*data!= ';' && *data!= '\0') {
                data++;
            }
            *data = '\0';
            parser *entity = create_parser(ref);
            add_child(p, entity);
        } else {
            // Text content
            data++;
        }
    }

    return root;
}

// Define the main function
int main() {
    char *xml = "<root><child>Hello, world!</child></root>";
    parser *tree = parse(xml);
    print_tree(tree);
    return 0;
}