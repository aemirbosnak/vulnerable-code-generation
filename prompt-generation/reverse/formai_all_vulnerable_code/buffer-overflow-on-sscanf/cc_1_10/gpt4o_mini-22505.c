//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_ATTR_NAME 100
#define MAX_ATTR_VALUE 100
#define MAX_BUFFER 1024

typedef struct {
    char tagName[MAX_TAG_NAME];
    char attrName[MAX_ATTR_NAME];
    char attrValue[MAX_ATTR_VALUE];
} XmlNode;

void parseXml(const char *filename);
void parseTag(const char *line, XmlNode *node);
void trimWhitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXml(argv[1]);

    return EXIT_SUCCESS;
}

void parseXml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER];
    XmlNode node;

    while (fgets(line, sizeof(line), file)) {
        trimWhitespace(line);
        if (line[0] != '\0' && line[0] != '<') continue;

        if (strstr(line, "<") && strstr(line, ">")) {
            parseTag(line, &node);
            printf("Tag Name: %s\n", node.tagName);
            if (strlen(node.attrName) > 0) {
                printf("Attribute: %s=\"%s\"\n", node.attrName, node.attrValue);
            }
        }
    }

    fclose(file);
}

void parseTag(const char *line, XmlNode *node) {
    sscanf(line, "<%[^ /]s", node->tagName);
    node->attrName[0] = '\0'; // Clear attribute name
    node->attrValue[0] = '\0'; // Clear attribute value

    char *attr_start = strchr(line, ' ');
    if (attr_start) {
        char *attr_end = strchr(attr_start, '>');
        if (attr_end) {
            *attr_end = '\0'; // Temporarily terminate the string
            sscanf(attr_start + 1, "%[^=]=%[^\n\"]", node->attrName, node->attrValue); // Extract attribute name and value
            if (node->attrValue[0] == '\"') {
                memmove(node->attrValue, node->attrValue + 1, strlen(node->attrValue)); // Remove starting quote
            }
            if (node->attrValue[strlen(node->attrValue) - 1] == '\"') {
                node->attrValue[strlen(node->attrValue) - 1] = '\0'; // Remove ending quote
            }
            *attr_end = '>'; // Restore the closing tag character
        }
    }
}

void trimWhitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)  // All spaces?
        return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}