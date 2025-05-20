//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 256
#define MAX_XML_SIZE 4096

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char content[MAX_XML_SIZE];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function to create a new XML Node
XMLNode *createNode(const char *tag, const char *content) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_NAME);
    strncpy(node->content, content, MAX_XML_SIZE);
    node->next = NULL;
    node->child = NULL;
    return node;
}

// Function to add a child node
void addChild(XMLNode *parent, XMLNode *child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        XMLNode *temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

// Function to parse XML string and build tree
XMLNode *parseXML(const char *xml) {
    XMLNode *root = NULL;
    XMLNode *current = NULL;
    char tag[MAX_TAG_NAME] = "";
    char content[MAX_XML_SIZE] = "";
    
    const char *ptr = xml;
    while (*ptr) {
        // Skip whitespace
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') {
            ptr++;
            continue;
        }

        // If opening tag found
        if (*ptr == '<' && *(ptr + 1) != '/') {
            ptr++;
            sscanf(ptr, "%[^>]", tag);
            ptr += strlen(tag) + 1;  // Move past the tag
            // Create new node
            XMLNode *newNode = createNode(tag, "");
            if (!root) root = newNode;  // Set root if it doesn't exist
            if (current) addChild(current, newNode);  // Add to current
            current = newNode;  // Make it current node
        }
        // If closing tag found
        else if (*ptr == '<' && *(ptr + 1) == '/') {
            ptr += 2; // Skip "</"
            sscanf(ptr, "%[^>]", tag);
            ptr += strlen(tag) + 1; // Move past the tag
            // Set content of the current node
            current = NULL; // Go back to parent (for simplicity, we won't keep track of parent)
        }
        // If text content found
        else {
            // Accumulate text content till we find a tag
            while (*ptr && *ptr != '<') {
                strncat(content, ptr, 1);
                ptr++;
            }
            if (current) {
                strncpy(current->content, content, MAX_XML_SIZE);
                content[0] = '\0'; // Reset content buffer
            }
        }
    }
    return root;
}

// Function to print the XML tree
void printXML(XMLNode *node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->content, node->tag);

    if (node->child) {
        printXML(node->child, level + 1);
    }

    if (node->next) {
        printXML(node->next, level);
    }
}

// Clean up memory
void freeXML(XMLNode *node) {
    if (!node) return;

    freeXML(node->child);
    freeXML(node->next);
    free(node);
}

int main() {
    const char *xml = "<root>\n"
                      "  <child1>Hello World</child1>\n"
                      "  <child2>\n"
                      "    <subchild>Data</subchild>\n"
                      "  </child2>\n"
                      "</root>";

    XMLNode *xmlTree = parseXML(xml);
    printf("Parsed XML Tree:\n");
    printXML(xmlTree, 0);
    
    freeXML(xmlTree);
    return 0;
}