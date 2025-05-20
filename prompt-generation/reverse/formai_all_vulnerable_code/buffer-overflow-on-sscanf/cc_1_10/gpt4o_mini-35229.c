//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_BUFFER 1024

typedef struct Node {
    char name[MAX_TAG_NAME];
    char value[MAX_BUFFER];
    struct Node* next;
    struct Node* child;
} Node;

Node* createNode(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(node->name, name, MAX_TAG_NAME);
    node->value[0] = '\0';
    node->next = NULL;
    node->child = NULL;
    return node;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

Node* parseXML(FILE* xmlFile) {
    Node* root = NULL;
    Node* current = NULL;
    char buffer[MAX_BUFFER];
    char tagName[MAX_TAG_NAME];

    while (fgets(buffer, sizeof(buffer), xmlFile)) {
        char* pos = buffer;

        while (*pos) {
            // Skip whitespace
            if (*pos == ' ' || *pos == '\n' || *pos == '\t') {
                pos++;
                continue;
            }

            // Check for start tag
            if (*pos == '<' && *(pos + 1) != '/') {
                pos++;
                sscanf(pos, "%[^>]", tagName);
                Node* newNode = createNode(tagName);
                if (!root) {
                    root = newNode; // Set root
                } else {
                    if (current) {
                        newNode->next = current->child;
                        current->child = newNode; // Add to the current node's children
                    }
                }
                current = newNode; // Current node is now the new node
                pos += strlen(tagName) + 1; // Move past the tag
            }

            // Check for end tag
            else if (*pos == '<' && *(pos + 1) == '/') {
                sscanf(pos + 2, "%[^>]", tagName);
                if (current && strcmp(current->name, tagName) == 0) {
                    current = current->child ? current->child : root; // Go to parent
                }
                pos += strlen(tagName) + 3; // Move past closing tag
            }

            // Read value
            else {
                char* valueStart = pos;
                while (*pos && *pos != '<') {
                    pos++;
                }
                strncpy(current->value, valueStart, pos - valueStart);
                current->value[pos - valueStart] = '\0'; // Null-terminate value
            }
        }
    }
    return root;
}

void printXML(Node* node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) printf("\t");
    printf("<%s>", node->name);
    if (node->value[0] != '\0') {
        printf("%s", node->value);
    }
    printf("\n");

    printXML(node->child, depth + 1);
    for (int i = 0; i < depth; i++) printf("\t");
    printf("</%s>\n", node->name);

    printXML(node->next, depth);
}

void freeXML(Node* root) {
    freeNode(root);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* xmlFile = fopen(argv[1], "r");
    if (!xmlFile) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Node* xmlTree = parseXML(xmlFile);
    fclose(xmlFile);

    printf("Parsed XML structure:\n");
    printXML(xmlTree, 0);

    freeXML(xmlTree); // Clean up memory

    return EXIT_SUCCESS;
}