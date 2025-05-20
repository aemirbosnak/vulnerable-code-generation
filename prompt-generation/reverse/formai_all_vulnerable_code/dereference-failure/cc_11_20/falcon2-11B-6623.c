//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define XML tags
#define XML_START_TAG "<"
#define XML_END_TAG ">"
#define XML_ATTR_START " "
#define XML_ATTR_END "="
#define XML_ATTR_VALUE " "

// Define XML nodes
typedef struct node {
    char tag[50];
    char content[200];
    struct node *next;
} node;

// Define XML parser function
node* parse_xml(char* xml) {
    node *current = NULL;
    char buffer[500];
    int length = 0;
    int index = 0;

    // Read characters from XML string
    while (xml[index]!= '\0') {
        switch (xml[index]) {
            case '<':
                if (buffer[length] == '\0') {
                    buffer[length] = xml[index];
                    length++;
                }
                else if (buffer[length - 1] == '>' && buffer[length - 2] == '<') {
                    buffer[length] = '\0';
                    current->tag[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                break;
            case '>':
                if (buffer[length] == '\0') {
                    buffer[length] = xml[index];
                    length++;
                }
                else if (buffer[length - 1] == '<' && buffer[length - 2] == '<') {
                    buffer[length] = '\0';
                    current->tag[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                else if (buffer[length]!= '\0') {
                    buffer[length] = '\0';
                    current->content[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                break;
            case '=':
                if (buffer[length] == '\0') {
                    buffer[length] = xml[index];
                    length++;
                }
                else if (buffer[length - 1] == '<' && buffer[length - 2] == '<') {
                    buffer[length] = '\0';
                    current->tag[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                else if (buffer[length]!= '\0') {
                    buffer[length] = '\0';
                    current->content[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                break;
            case '"':
                if (buffer[length] == '\0') {
                    buffer[length] = xml[index];
                    length++;
                }
                else if (buffer[length - 1] == '<' && buffer[length - 2] == '<') {
                    buffer[length] = '\0';
                    current->tag[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                else if (buffer[length]!= '\0') {
                    buffer[length] = '\0';
                    current->content[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
                break;
            default:
                if (buffer[length] == '\0') {
                    buffer[length] = xml[index];
                    length++;
                }
                else if (buffer[length]!= '\0') {
                    buffer[length] = '\0';
                    current->content[0] = buffer;
                    current->next = NULL;
                    current = current->next;
                    length = 0;
                }
        }
        index++;
    }

    return current;
}

int main() {
    char xml[] = "<book> <title>The Catcher in the Rye</title> <author>J.D. Salinger</author> </book>";
    node *root = parse_xml(xml);

    while (root!= NULL) {
        printf("%s\n", root->tag);
        if (root->next!= NULL) {
            printf("Content: %s\n", root->content);
        }
        root = root->next;
    }

    return 0;
}