//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_CONTENT 256
#define MAX_LINE_LENGTH 512

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    struct XMLNode *next;
} XMLNode;

typedef struct XMLParser {
    XMLNode *head;
    XMLNode *tail;
} XMLParser;

void initParser(XMLParser *parser) {
    parser->head = NULL;
    parser->tail = NULL;
}

void appendNode(XMLParser *parser, const char *tagname, const char *content) {
    XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(newNode->tagName, tagname, MAX_TAG_NAME);
    strncpy(newNode->content, content, MAX_CONTENT);
    newNode->next = NULL;

    if (parser->tail) {
        parser->tail->next = newNode;
    } else {
        parser->head = newNode;
    }
    parser->tail = newNode;
}

void freeParser(XMLParser *parser) {
    XMLNode *current = parser->head;
    while (current != NULL) {
        XMLNode *next = current->next;
        free(current);
        current = next;
    }
    parser->head = NULL;
    parser->tail = NULL;
}

void parseXMLLine(XMLParser *parser, const char *line) {
    char tag[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    
    if (sscanf(line, "<%[^>]>%[^<]</%[^>]", tag, content, tag) == 3) {
        appendNode(parser, tag, content);
    }
}

void printParsedData(const XMLParser *parser) {
    XMLNode *current = parser->head;
    while (current != NULL) {
        printf("Tag: %s, Content: %s\n", current->tagName, current->content);
        current = current->next;
    }
}

void readAndParseXML(FILE *file) {
    XMLParser parser;
    initParser(&parser);
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        parseXMLLine(&parser, line);
    }
    
    printParsedData(&parser);
    freeParser(&parser);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    readAndParseXML(file);
    fclose(file);
    return 0;
}