//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *tag;
    char *text;
    struct Node *next;
    struct Node *child;
} Node;

// A tender function to create a new node
Node* createNode(const char *tag, const char *text) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->tag = strdup(tag);
    newNode->text = strdup(text);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// A poetic function to add a child node
void addChildNode(Node *parent, Node *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node *temp = parent->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

// A loving function to free the nodes, relinquishing their memory
void freeNode(Node *node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node->tag);
        free(node->text);
        free(node);
    }
}

// A tender function to parse XML from a string
Node* parseXML(const char *xml) {
    Node *root = NULL;
    Node *current = NULL;
    char tag[256];
    char text[256];
    const char *p = xml;
    
    while (*p) {
        if (*p == '<') {
            if (*(p + 1) == '/') {  // Closing tag
                p = strchr(p, '>');
                if (p) p++;
                continue;
            } else {
                p++;
                sscanf(p, "%[^>]", tag); // Get the tag
                p += strlen(tag);
                current = createNode(tag, "");
                if (!root) {
                    root = current;
                }
            }
            if (*p == '>') {
                p++;
                char *textPointer = text;
                while (*p && *p != '<') {
                    *textPointer++ = *p++;
                }
                *textPointer = '\0'; // Null-terminate the text
                if (*text) {
                    current->text = strdup(text);
                }
            }
            if (*p == '<') {
                addChildNode(current, current);
            }
        }
        p++;
    }
    return root;
}

// A function that serenades the nodes to the console
void printXML(Node *node, int depth) {
    while (node) {
        for (int i = 0; i < depth; i++)
            printf("  "); // Indent for visual delight
        if (node->text && strlen(node->text) > 0) {
            printf("<%s>%s</%s>\n", node->tag, node->text, node->tag);
        } else {
            printf("<%s>\n", node->tag);
        }
        printXML(node->child, depth + 1);
        node = node->next;
        if (node == NULL && depth > 0) {
            for (int i = 0; i < depth - 1; i++)
                printf("  ");
        }
    }
}

// A function that whispers farewell to bittersweet memories
void parseAndPrintXML(const char *xml) {
    Node *parsedXML = parseXML(xml);
    printXML(parsedXML, 0);
    freeNode(parsedXML);
}

int main() {
    const char *xmlData = "<love><heart>Forever</heart><kiss>Soft</kiss></love>";
    printf("Parsing the XML filled with romantic dreams...\n");
    parseAndPrintXML(xmlData);
    return 0;
}