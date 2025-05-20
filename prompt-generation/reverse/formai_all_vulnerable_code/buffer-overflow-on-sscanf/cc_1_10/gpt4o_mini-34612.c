//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 64
#define MAX_TAG_CONTENT 256
#define MAX_BUFFER 1024

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    struct XmlNode* children;
    struct XmlNode* nextSibling;
} XmlNode;

// Function to create a new XML node
XmlNode* createXmlNode(const char* tagName, const char* content) {
    XmlNode* node = (XmlNode*)malloc(sizeof(XmlNode));
    if (node == NULL) {
        perror("Failed to allocate memory for XML node");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tagName, tagName, MAX_TAG_NAME);
    strncpy(node->content, content, MAX_TAG_CONTENT);
    node->children = NULL;
    node->nextSibling = NULL;
    return node;
}

// Function to append a child node to a parent node
void appendChild(XmlNode* parent, XmlNode* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        XmlNode* sibling = parent->children;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

// Function to parse an XML string and construct the XML tree
XmlNode* parseXml(const char* xml) {
    XmlNode* root = NULL;
    XmlNode* currentNode = NULL;
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    int i = 0;
    char* p = (char*)xml;

    while (*p) {
        if (*p == '<') {
            if (*(p + 1) != '/') {  // Opening tag
                p++;
                sscanf(p, "%[^>]", tagName);
                while (*p != '>') p++; // Move to the end of the tag
                p++; // Skip '>'

                // Create and append the new node
                XmlNode* newNode = createXmlNode(tagName, "");
                if (currentNode == NULL) {
                    root = newNode;  // The first node is the root
                } else {
                    appendChild(currentNode, newNode);
                }
                currentNode = newNode;  // Move current to the new node
            } else {  // Closing tag
                p += 2;  // Skip '</'
                sscanf(p, "%[^>]", tagName);
                while (*p != '>') p++; // Move to the end of the tag
                p++; // Skip '>'

                currentNode = currentNode->nextSibling;  // Move up the hierarchy
            }
        } else if (currentNode) {  // Content inside the tags
            i = 0;
            while (*p && *p != '<' && i < MAX_TAG_CONTENT - 1) {
                content[i++] = *p++;
            }
            content[i] = '\0';
            strncpy(currentNode->content, content, MAX_TAG_CONTENT);
        }
    }

    return root;
}

// Function to print the XML tree
void printXml(XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tagName, node->content, node->tagName);
    printXml(node->children, depth + 1);
    printXml(node->nextSibling, depth);
}

// Function to free the XML tree
void freeXmlTree(XmlNode* node) {
    if (node != NULL) {
        freeXmlTree(node->children);
        freeXmlTree(node->nextSibling);
        free(node);
    }
}

int main() {
    const char* xmlInput = "<greeting>Hello, world!</greeting><farewell>Goodbye!</farewell>";
    
    XmlNode* xmlTree = parseXml(xmlInput);
    printf("Parsed XML Tree:\n");
    printXml(xmlTree, 0);
    
    freeXmlTree(xmlTree);  // Clean up memory
    return 0;
}