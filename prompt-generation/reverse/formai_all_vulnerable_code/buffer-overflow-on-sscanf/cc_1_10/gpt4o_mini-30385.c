//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold XML data
typedef struct XMLNode {
    char *tag;
    char *value;
    struct XMLNode **children;
    int child_count;
} XMLNode;

// Function to create a new XMLNode
XMLNode *createNode(const char *tag, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->tag = strdup(tag);
    node->value = strdup(value);
    node->child_count = 0;
    node->children = NULL;
    return node;
}

// Function to add a child node to a parent node
void addChild(XMLNode *parent, XMLNode *child) {
    parent->children = (XMLNode **)realloc(parent->children, sizeof(XMLNode *) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

// Function to free an XMLNode and its children
void freeXMLNode(XMLNode *node) {
    if (node) {
        free(node->tag);
        free(node->value);
        for (int i = 0; i < node->child_count; i++) {
            freeXMLNode(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

// Function to print XML in a structured format
void printXML(const XMLNode *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (node->value && strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        printXML(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

// Function to parse a simple XML string
XMLNode *parseXML(const char *xml) {
    XMLNode *root = NULL;
    char tag[256];
    char value[256];
    char *ptr = (char *)xml;

    while (sscanf(ptr, "<%[^>]>%[^<]</%[^>]", tag, value, tag) == 3) {
        XMLNode *node = createNode(tag, value);
        if (!root) {
            root = node; // Set root node
        } else {
            addChild(root, node); // Add child to root
        }
        ptr += strlen(tag) + strlen(value) + 5; // Move pointer forward
    }
    return root;
}

// Entry point of the program
int main() {
    const char *xmlData =
    "<book><title>Learning C</title><author>John Doe</author></book>";
  
    printf("Parsing the following XML:\n%s\n", xmlData);
  
    XMLNode *parsedXML = parseXML(xmlData);
    if (parsedXML) {
        printf("\nXML Parsed Structure:\n");
        printXML(parsedXML, 0);
        freeXMLNode(parsedXML); // Free memory after use
    } else {
        printf("Failed to parse XML.\n");
    }

    return 0;
}