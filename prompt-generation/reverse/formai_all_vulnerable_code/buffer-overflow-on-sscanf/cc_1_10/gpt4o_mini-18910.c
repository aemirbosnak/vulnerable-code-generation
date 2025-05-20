//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char *content;
    struct XMLNode *next;
    struct XMLNode *children;
} XMLNode;

XMLNode* createNode(const char* tag) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (!newNode) {
        perror("Failed to allocate memory for XML node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    newNode->content = NULL;
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

// Function to parse the XML string into nodes
XMLNode* parseXML(const char* xml) {
    XMLNode *root = NULL;
    XMLNode *currentNode = NULL;
    char tag[MAX_TAG_LENGTH];
    const char *ptr = xml;
    
    while (*ptr) {
        // Skip whitespace
        while (*ptr && (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')) ptr++;

        // Check for starting tag
        if (*ptr == '<' && *(ptr + 1) != '/') {
            ptr++; // Skip '<'
            sscanf(ptr, "%[^>]", tag);
            XMLNode* newNode = createNode(tag);

            // If we are at the root node, set it
            if (root == NULL) {
                root = newNode;
            } else {
                // Attach the new node to the current node's children
                newNode->next = currentNode->children;
                currentNode->children = newNode;
            }

            // Move the pointer past the tag
            while (*ptr != '>') ptr++;
            ptr++; // Skip '>'

            // Set the current node to the new node
            currentNode = newNode;
        }
        // Check for closing tag
        else if (*ptr == '<' && *(ptr + 1) == '/') {
            while (*ptr && *ptr != '>') ptr++; // Skip until '>'
            ptr++; // Skip '>'
            currentNode = currentNode->next; // Move back up
        }
        // Capture content
        else {
            const char *contentStart = ptr;
            while (*ptr && *ptr != '<') ptr++; // Move to the start of the next tag
            if (ptr > contentStart) {
                currentNode->content = (char*)malloc(ptr - contentStart + 1); // Allocate memory for content
                if (!currentNode->content) {
                    perror("Failed to allocate memory for XML content");
                    exit(EXIT_FAILURE);
                }
                strncpy(currentNode->content, contentStart, ptr - contentStart);
                currentNode->content[ptr - contentStart] = '\0';
            }
        }
    }
    return root;
}

// Function to print the XML nodes for debugging
void printXML(XMLNode* node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) printf("\t");
    printf("<%s>", node->tag);
    if (node->content) {
        printf("%s", node->content);
    }
    printf("\n");

    // Recursively print children
    printXML(node->children, level + 1);
    
    for (int i = 0; i < level; i++) printf("\t");
    printf("</%s>\n", node->tag);

    printXML(node->next, level); // Move to next sibling
}

// Function to free the allocated memory
void freeXML(XMLNode* node) {
    if (!node) return;
    
    freeXML(node->children);  // Free children
    if (node->content) free(node->content); // Free content
    freeXML(node->next); // Free next siblings
    free(node); // Free the node itself
}

int main() {
    const char* xmlData =
        "<note>\n"
        "  <to>Tove</to>\n"
        "  <from>Jani</from>\n"
        "  <heading>Reminder</heading>\n"
        "  <body>Don't forget me this weekend!</body>\n"
        "</note>";

    XMLNode* root = parseXML(xmlData);
    printf("Parsed XML Structure:\n");
    printXML(root, 0);
    freeXML(root); // Clean up memory
    return 0;
}