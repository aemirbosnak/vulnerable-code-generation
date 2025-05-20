//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 32
#define MAX_CONTENT_LENGTH 256

typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct XmlNode *next;
    struct XmlNode *child;
} XmlNode;

XmlNode* create_node(const char *tag, const char *content) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    strncpy(node->content, content, MAX_CONTENT_LENGTH);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void free_xml(XmlNode* node) {
    if (node) {
        free_xml(node->child);
        free_xml(node->next);
        free(node);
    }
}

void print_xml(XmlNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", node->tag);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    print_xml(node->child, depth + 1);
    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", node->tag);
    print_xml(node->next, depth);
}

XmlNode* parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    XmlNode *root = NULL, *current = NULL, *last = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH], content[MAX_CONTENT_LENGTH];
        if (sscanf(line, "<%[^>]>", tag) == 1) {
            // Start of a new tag
            if (!root) {
                root = create_node(tag, "");
                current = root;
            } else {
                XmlNode *new_node = create_node(tag, "");
                if (current->child == NULL) {
                    current->child = new_node;
                } else {
                    last->next = new_node;
                }
                last = new_node;
                current = new_node;
            }
        } else if (sscanf(line, "</%[^>]>%s", tag, content) == 1) {
            // End of a tag
            if (current) {
                current = current->next ?: current->child;
            }
        } else {
            // Content line
            if (current) {
                strncat(current->content, line, MAX_CONTENT_LENGTH - strlen(current->content) - 1);
            }
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlNode *xml_tree = parse_xml(argv[1]);
    if (xml_tree) {
        print_xml(xml_tree, 0);
        free_xml(xml_tree);
    }

    return EXIT_SUCCESS;
}