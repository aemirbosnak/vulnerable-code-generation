//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_BUFFER 1024

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    struct XmlNode* next;
} XmlNode;

// Function prototypes
XmlNode* createNode(const char* tagName, const char* content);
void parseXml(const char* filename);
void freeNodes(XmlNode* node);
void printNodes(XmlNode* node);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXml(argv[1]);
    return EXIT_SUCCESS;
}

// Create a new XmlNode
XmlNode* createNode(const char* tagName, const char* content) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->content, content, MAX_BUFFER);
    newNode->next = NULL;
    return newNode;
}

// Print the linked list of XML nodes
void printNodes(XmlNode* node) {
    while (node) {
        printf("<%s>%s</%s>\n", node->tagName, node->content, node->tagName);
        node = node->next;
    }
}

// Free the linked list of nodes
void freeNodes(XmlNode* node) {
    XmlNode* temp;
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Parsing XML file and extracting nodes
void parseXml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    XmlNode* head = NULL;
    XmlNode* tail = NULL;

    char buffer[MAX_BUFFER];
    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];

    while (fgets(buffer, sizeof(buffer), file)) {
        char* openingTag = strchr(buffer, '<');
        if (openingTag) {
            // Extract tag name
            sscanf(openingTag, "<%[^>]", tagName);
            // Find corresponding closing tag
            char* closingTag = strstr(buffer, tagName);
            if (closingTag) {
                closingTag = strstr(closingTag, ">");
                if (closingTag) {
                    closingTag = strstr(closingTag, "<");
                    if (closingTag) {
                        // Extract content
                        int contentLength = closingTag - (openingTag + strlen(tagName) + 2);
                        strncpy(content, openingTag + strlen(tagName) + 2, contentLength);
                        content[contentLength] = '\0';

                        // Create a new node and add it to the list
                        XmlNode* newNode = createNode(tagName, content);
                        if (!head) {
                            head = newNode;
                            tail = newNode;
                        } else {
                            tail->next = newNode;
                            tail = newNode;
                        }
                    }
                }
            }
        }
    }

    fclose(file);

    // Display results
    printf("Parsed XML content:\n");
    printNodes(head);

    // Free allocated memory
    freeNodes(head);
}