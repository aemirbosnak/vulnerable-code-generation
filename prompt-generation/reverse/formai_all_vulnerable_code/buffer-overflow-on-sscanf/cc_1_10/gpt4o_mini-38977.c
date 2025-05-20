//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_CONTENT 1024
#define MAX_NESTING 10

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    struct XMLNode *child[MAX_NESTING];
    int childCount;
} XMLNode;

XMLNode* createNode(const char* tag, const char* content) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_NAME);
    strncpy(node->content, content, MAX_CONTENT);
    node->childCount = 0;
    return node;
}

void addChild(XMLNode* parent, XMLNode* child) {
    if (parent->childCount < MAX_NESTING) {
        parent->child[parent->childCount++] = child;
    } else {
        fprintf(stderr, "Max child nodes exceeded for tag: %s\n", parent->tag);
    }
}

void freeXMLNode(XMLNode* node) {
    if (node) {
        for (int i = 0; i < node->childCount; i++) {
            freeXMLNode(node->child[i]);
        }
        free(node);
    }
}

void printXML(XMLNode* node, int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
    printf("<%s>", node->tag);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    for (int i = 0; i < node->childCount; i++) {
        printXML(node->child[i], indent + 1);
    }
    for (int i = 0; i < indent; i++) printf("  ");
    printf("</%s>\n", node->tag);
}

XMLNode* parseXML(const char* input) {
    XMLNode* root = NULL;
    XMLNode* current = NULL;
    char tag[MAX_TAG_NAME], content[MAX_CONTENT];
    const char* p = input;

    while (*p) {
        if (*p == '<') {
            if (*(p + 1) == '/') { // Closing tag
                p = strchr(p, '>');
                if (current) {
                    current = NULL; // End of current node
                }
            } else { // Opening tag
                p++;
                sscanf(p, "%[^>]", tag);
                current = createNode(tag, "");
                if (!root) {
                    root = current;
                }
                p = strchr(p, '>') + 1;
            }
        } else {
            char* nextTag = strchr(p, '<');
            if (nextTag) {
                size_t len = nextTag - p;
                strncpy(content, p, len);
                content[len] = '\0';
                if (current) {
                    strncpy(current->content, content, MAX_CONTENT);
                }
                p = nextTag;
            } else {
                strcpy(content, p);
                if (current) {
                    strncpy(current->content, content, MAX_CONTENT);
                }
                break; // End of string
            }
        }
    }

    return root;
}

int main() {
    const char* xmlData = "<root><child1>Hello</child1><child2><subchild>World!</subchild></child2></root>";

    XMLNode* xmlTree = parseXML(xmlData);
    if (xmlTree) {
        printXML(xmlTree, 0);
        freeXMLNode(xmlTree);
    }

    return 0;
}