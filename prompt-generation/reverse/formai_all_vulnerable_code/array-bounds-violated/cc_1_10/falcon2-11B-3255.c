//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *tag;
    int line;
    struct node *next;
} node;

node *new_node(char *tag, int line) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->tag = strdup(tag);
    new_node->line = line;
    new_node->next = NULL;
    return new_node;
}

void free_node(node *node) {
    if (node) {
        free(node->tag);
        free(node);
    }
}

int parse_xml(FILE *xml_file, node **root) {
    int line = 1;
    char buffer[256];
    int buffer_size = 0;
    node *current_node = NULL;
    node *parent_node = NULL;
    node *child_node = NULL;
    int current_depth = 0;

    while (fgets(buffer, sizeof(buffer), xml_file)!= NULL) {
        buffer_size = strlen(buffer);
        if (buffer[buffer_size - 1] == '\n') {
            buffer[buffer_size - 1] = '\0';
        }
        buffer_size = strlen(buffer);
        if (buffer_size > 0) {
            if (buffer[0] == '<' && buffer[buffer_size - 1] == '>') {
                char *tag = &buffer[1];
                char *end_tag = strstr(tag, "</");
                if (end_tag) {
                    end_tag[0] = '\0';
                    char *name = strstr(tag, " ");
                    if (name) {
                        *name = '\0';
                        current_depth++;
                        parent_node = new_node(tag, line);
                        parent_node->line = line;
                        parent_node->next = NULL;
                        current_node = parent_node;
                    }
                    else {
                        free_node(current_node);
                        current_node = NULL;
                        parent_node = NULL;
                        current_depth--;
                    }
                    line++;
                }
            }
            else if (current_node) {
                char *name = strstr(buffer, " ");
                if (name) {
                    *name = '\0';
                    child_node = new_node(buffer, line);
                    child_node->line = line;
                    child_node->next = NULL;
                    current_node->next = child_node;
                    current_node = child_node;
                }
            }
        }
    }
    return 0;
}

int main() {
    FILE *xml_file = fopen("example.xml", "r");
    if (xml_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    node *root = NULL;
    if (parse_xml(xml_file, &root)!= 0) {
        fprintf(stderr, "Error parsing XML\n");
        return 1;
    }
    printf("Root tag: %s\n", root->tag);
    node *current_node = root->next;
    while (current_node) {
        printf("Tag: %s, Line: %d\n", current_node->tag, current_node->line);
        current_node = current_node->next;
    }
    free_node(root);
    fclose(xml_file);
    return 0;
}