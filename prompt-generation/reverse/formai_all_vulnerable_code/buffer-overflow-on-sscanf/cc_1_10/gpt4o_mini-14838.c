//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_VALUE_LENGTH 255

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* next;
    struct XmlNode* children;
} XmlNode;

XmlNode* createNode(const char* tag, const char* value) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (newNode != NULL) {
        strncpy(newNode->tag, tag, MAX_TAG_NAME);
        strncpy(newNode->value, value, MAX_VALUE_LENGTH);
        newNode->next = NULL;
        newNode->children = NULL;
    }
    return newNode;
}

void addChild(XmlNode* parent, XmlNode* child) {
    if (parent == NULL || child == NULL) return;

    child->next = parent->children;
    parent->children = child;
}

void freeXmlNode(XmlNode* node) {
    if (node == NULL) return;

    freeXmlNode(node->children);
    freeXmlNode(node->next);
    free(node);
}

void printXmlNode(const XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    
    if (node->children) {
        printXmlNode(node->children, depth + 1);
    }
    printXmlNode(node->next, depth);
}

XmlNode* parseXml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    char line[256];
    XmlNode* head = NULL;
    XmlNode* tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_NAME] = {0};
        char value[MAX_VALUE_LENGTH] = {0};

        if (sscanf(line, "<%[^>]>%[^<]", tag, value) == 2) {
            XmlNode* newNode = createNode(tag, value);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    fclose(file);
    return head;
}

int main() {
    const char* filename = "example.xml";
    XmlNode* xmlTree = parseXml(filename);

    if (xmlTree != NULL) {
        printf("Parsed XML contents:\n");
        printXmlNode(xmlTree, 0);
        freeXmlNode(xmlTree);
    } else {
        printf("Could not parse the XML file.\n");
    }

    return 0;
}