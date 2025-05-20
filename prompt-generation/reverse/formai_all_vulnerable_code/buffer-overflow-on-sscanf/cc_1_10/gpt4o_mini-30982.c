//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 128
#define MAX_TAG_VALUE 512

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

XMLNode* createNode(const char *tag, const char *value) {
    XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void addChild(XMLNode *parent, XMLNode *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XMLNode *temp = parent->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeXMLNode(XMLNode *node) {
    if (node) {
        freeXMLNode(node->child);
        freeXMLNode(node->next);
        free(node);
    }
}

void printXMLNode(XMLNode *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    
    printXMLNode(node->child, depth + 1);
    printXMLNode(node->next, depth);
}

void parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    XMLNode *root = NULL;
    XMLNode *current = NULL;
    char buffer[MAX_BUFFER];

    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        char tag[MAX_TAG_NAME] = {0};
        char value[MAX_TAG_VALUE] = {0};
        
        // Simple parsing logic: Capture tags and values
        if (sscanf(buffer, " <%[^>]> %s </%[^>]>", tag, value, tag) == 3) {
            XMLNode *newNode = createNode(tag, value);
            if (root == NULL) {
                root = newNode; // Set root node
            }
            if (current) {
                addChild(current, newNode);
            }
            current = newNode; // Move to the new node
        } else if (sscanf(buffer, " </%[^>]> ", tag) == 1) {
            if (current) {
                current = current->next; // Move back to parent (just a simplistic approach)
            }
        }
    }

    fclose(file);
    printXMLNode(root, 0);
    freeXMLNode(root);
}

int main() {
    const char *filename = "example.xml";
    parseXML(filename);
    return 0;
}