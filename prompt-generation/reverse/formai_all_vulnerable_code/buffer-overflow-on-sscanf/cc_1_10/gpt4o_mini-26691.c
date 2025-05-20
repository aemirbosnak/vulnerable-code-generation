//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_VALUE 256

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XmlNode *next;
} XmlNode;

XmlNode* createNode(const char *tag, const char *value) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    strcpy(node->tag, tag);
    strcpy(node->value, value);
    node->next = NULL;
    return node;
}

void appendNode(XmlNode **head, XmlNode *newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        XmlNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeXmlNodes(XmlNode *head) {
    XmlNode *current = head;
    while (current != NULL) {
        XmlNode *temp = current;
        current = current->next;
        free(temp);
    }
}

void parseXml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_TAG_VALUE];
    XmlNode *xmlList = NULL, *current = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_NAME];
        char value[MAX_TAG_VALUE];
        
        if (sscanf(line, "<%s>%[^\n]</%s>", tag, value, tag) == 3) {
            XmlNode *newNode = createNode(tag, value);
            appendNode(&xmlList, newNode);
        }
    }

    fclose(file);

    // Print the parsed XML nodes
    current = xmlList;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }

    // Free allocated nodes
    freeXmlNodes(xmlList);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    parseXml(argv[1]);
    return 0;
}