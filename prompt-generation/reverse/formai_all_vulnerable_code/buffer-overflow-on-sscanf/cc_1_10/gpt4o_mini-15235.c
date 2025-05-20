//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 256
#define MAX_VALUE 512

typedef struct XmlNode {
    char name[MAX_ELEMENT];
    char value[MAX_VALUE];
    struct XmlNode *next;
} XmlNode;

XmlNode* createNode(const char *name, const char *value) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    strncpy(node->name, name, MAX_ELEMENT);
    strncpy(node->value, value, MAX_VALUE);
    node->next = NULL;
    return node;
}

void addNode(XmlNode **head, const char *name, const char *value) {
    XmlNode *newNode = createNode(name, value);
    newNode->next = *head;
    *head = newNode;
}

void freeList(XmlNode *head) {
    XmlNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void parseXML(const char *xml, XmlNode **head) {
    char name[MAX_ELEMENT] = {0};
    char value[MAX_VALUE] = {0};

    const char *ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // Move past closing tag
                ptr = strchr(ptr, '>');
                if (ptr) ptr++;
            } else {
                // Opening tag
                ptr++;
                sscanf(ptr, "%[^>]", name);
                ptr += strlen(name);
                while (*ptr && *ptr != '<') {
                    strncat(value, ptr, 1);
                    ptr++;
                }
                addNode(head, name, value);
                memset(value, 0, sizeof(value)); // Clear value for the next use
            }
        } else {
            ptr++;
        }
    }
}

void printXmlNodes(XmlNode *head) {
    XmlNode *current = head;
    while (current) {
        printf("Element: %s, Value: %s\n", current->name, current->value);
        current = current->next;
    }
}

int main() {
    // The neon-drenched world awaits through this XML data
    const char *xmlData = "<cyberpunk><neon>Glowing Lights</neon><city>Nightmares</city><hacker>Shadow Runner</hacker></cyberpunk>";

    XmlNode *head = NULL;
    parseXML(xmlData, &head);
    printXmlNodes(head);

    // Cleanup memory
    freeList(head);

    return 0;
}