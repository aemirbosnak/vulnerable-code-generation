//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Define a struct for an XML Node
typedef struct XMLNode {
    char *name;
    char *value;
    struct XMLNode **children;
    int childCount;
} XMLNode;

// Function to create a new XML node
XMLNode* createNode(const char *name, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->name = strdup(name);
    node->value = strdup(value);
    node->children = NULL;
    node->childCount = 0;
    return node;
}

// Function to add a child to a given XML node
void addChild(XMLNode *parent, XMLNode *child) {
    parent->childCount++;
    parent->children = (XMLNode **)realloc(parent->children, 
                      parent->childCount * sizeof(XMLNode *));
    parent->children[parent->childCount - 1] = child;
}

// Function to free the XML node and all its children
void freeNode(XMLNode *node) {
    if (node) {
        free(node->name);
        free(node->value);
        for (int i = 0; i < node->childCount; i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

// Function to print the XML tree
void printXML(XMLNode *node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++)
        printf("  ");
    printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    
    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], level + 1);
    }
}

// Function to parse a simple XML format
XMLNode* parseXML(const char *xml) {
    char buffer[BUFFER_SIZE];
    int index = 0; // To track the index in the XML string

    // Assume we find a root node
    if (sscanf(xml, "<%[^>]>%[^<]", buffer, buffer + 50) != 2) {
        return NULL;
    }

    char nodeName[50], nodeValue[50];
    sscanf(buffer, "%s", nodeName);
    sscanf(buffer + 50, "%s", nodeValue);

    XMLNode *rootNode = createNode(nodeName, nodeValue);

    // For simplicity, we only handle one level of children
    while (1) {
        index = strstr(xml + index, "<") - xml;
        if (index < 0) break; // End of the XML string
        int endIndex = strstr(xml + index, ">") - xml; // Find >
        if (endIndex < 0) break;
        
        strncpy(buffer, xml + index + 1, endIndex - index - 1);
        buffer[endIndex - index - 1] = '\0'; // Extract the tag
        index = endIndex + 1;

        // Now get the value
        endIndex = strstr(xml + index, "<") - xml;
        if (endIndex < 0) break;

        strncpy(nodeValue, xml + index, endIndex - index);
        nodeValue[endIndex - index] = '\0'; // Extract the value
        index = endIndex;

        // Create the child node and add it to the root
        addChild(rootNode, createNode(buffer, nodeValue));
    }
    return rootNode;
}

// Main function to demonstrate the XML parser
int main() {
    const char *xmlData = "<root>Hello<child>World</child></root>";

    printf("Parsing XML:\n%s\n\n", xmlData);
    XMLNode *xmlTree = parseXML(xmlData);

    printf("Parsed XML Tree:\n");
    printXML(xmlTree, 0);
    
    // Clean up memory
    freeNode(xmlTree);
    return 0;
}