//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256
#define MAX_VALUE_LENGTH 512

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function to create a new XML node
XMLNode* createNode(const char* tag, const char* value) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new XML node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to parse XML content
XMLNode* parseXML(FILE* file) {
    char line[MAX_LINE_LENGTH];
    XMLNode* root = NULL;
    XMLNode* current = NULL;
    XMLNode* lastPtr = NULL;
    
    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char value[MAX_VALUE_LENGTH];
        // Check for opening tag
        if (sscanf(line, "<%[^>]>", tag) == 1) {
            // Create new node for opening tag
            if (current == NULL) {
                root = createNode(tag, "");
                current = root;
            } else {
                XMLNode* child = createNode(tag, "");
                child->next = current->child;
                current->child = child;
                current = child;
            }
        }
        // Check for closing tag
        else if (sscanf(line, "</%[^>]>", tag) == 1) {
            // Move up the tree
            if (current != NULL) {
                current = lastPtr;
            }
        }
        // Check for value inside tags
        else {
            char* start = strchr(line, '>');
            char* end = strrchr(line, '<');
            if (start && end && start < end) {
                size_t length = end - start - 1;
                strncpy(value, start + 1, length);
                value[length] = '\0';
                // Assign value to the current node
                if (current != NULL) {
                    strncpy(current->value, value, MAX_VALUE_LENGTH);
                }
            }
        }
        // Save last non-null current node
        lastPtr = current;
    }
    return root;
}

// Function to print the parsed XML tree
void printXML(XMLNode* node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    printXML(node->child, level + 1);
    printXML(node->next, level);
}

// Free the XML tree
void freeXML(XMLNode* node) {
    if (node == NULL) return;
    freeXML(node->child);
    freeXML(node->next);
    free(node);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <XML file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Failed to open XML file");
        return EXIT_FAILURE;
    }
    
    XMLNode* root = parseXML(file);
    fclose(file);

    printf("Parsed XML structure:\n");
    printXML(root, 0);

    freeXML(root);
    return EXIT_SUCCESS;
}