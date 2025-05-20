//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct xml_node {
    char *name;
    char *value;
    struct xml_node *parent;
    struct xml_node *next;
    struct xml_node *children;
} xml_node;

xml_node *xml_parser(char *data) {
    xml_node *root = NULL;
    xml_node *current = NULL;

    int state = 0;
    int in_tag = 0;
    int in_value = 0;
    char *tag_name = NULL;
    char *tag_value = NULL;

    for (char *c = data; *c; c++) {
        switch (state) {
            case 0:
                if (*c == '<') {
                    state = 1;
                }
                break;
            case 1:
                if (*c == '/') {
                    state = 2;
                } else if (*c == '?') {
                    state = 3;
                } else {
                    state = 4;
                    tag_name = c;
                }
                break;
            case 2:
                if (*c == '>') {
                    state = 0;
                    current = current->parent;
                }
                break;
            case 3:
                if (*c == '>') {
                    state = 0;
                }
                break;
            case 4:
                if (*c == '>') {
                    state = 0;
                    in_tag = 0;
                    if (tag_value) {
                        current->value = tag_value;
                        tag_value = NULL;
                    }
                    current = current->next;
                } else if (*c == ' ') {
                    state = 5;
                } else if (*c == '/') {
                    state = 6;
                } else {
                    if (!in_tag) {
                        tag_name = c;
                        in_tag = 1;
                    }
                }
                break;
            case 5:
                if (*c == '>') {
                    state = 0;
                    in_tag = 0;
                    if (tag_value) {
                        current->value = tag_value;
                        tag_value = NULL;
                    }
                    current = current->next;
                } else if (*c == '/') {
                    state = 6;
                }
                break;
            case 6:
                if (*c == '>') {
                    state = 0;
                    in_tag = 0;
                    if (tag_value) {
                        current->value = tag_value;
                        tag_value = NULL;
                    }
                    current = current->parent;
                }
                break;
            default:
                if (in_value) {
                    if (*c == '\"') {
                        state = 4;
                        in_value = 0;
                        tag_value = realloc(tag_value, sizeof(char) * (strlen(tag_value) + 1));
                        tag_value[strlen(tag_value)] = '\0';
                    } else {
                        tag_value = realloc(tag_value, sizeof(char) * (strlen(tag_value) + 2));
                        tag_value[strlen(tag_value)] = *c;
                        tag_value[strlen(tag_value) + 1] = '\0';
                    }
                } else if (*c == '\"') {
                    state = 7;
                    in_value = 1;
                    tag_value = calloc(1, sizeof(char));
                }
                break;
        }
    }

    return root;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(size + 1);
    fread(data, 1, size, file);
    fclose(file);

    xml_node *root = xml_parser(data);

    xml_node *node = root;
    while (node) {
        printf("%s", node->name);
        if (node->value) {
            printf(" = \"%s\"", node->value);
        }
        printf("\n");

        node = node->next;
    }

    free(data);
    return 0;
}