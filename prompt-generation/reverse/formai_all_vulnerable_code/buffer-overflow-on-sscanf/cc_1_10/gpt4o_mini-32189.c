//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 256
#define MAX_VALUE_LEN 256

typedef struct XMLNode {
    char tag[MAX_TAG_LEN];
    char value[MAX_VALUE_LEN];
    struct XMLNode *next;
} XMLNode;

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

XMLNode *create_node(const char *tag, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_LEN);
    strncpy(node->value, value, MAX_VALUE_LEN);
    node->next = NULL;
    return node;
}

void append_node(XMLNode **head, const char *tag, const char *value) {
    XMLNode *new_node = create_node(tag, value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    XMLNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void free_nodes(XMLNode *head) {
    XMLNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void parse_xml(FILE *file, XMLNode **head) {
    char line[512];
    char tag[MAX_TAG_LEN];
    char value[MAX_VALUE_LEN];

    while (fgets(line, sizeof(line), file)) {
        trim_newline(line);
        if (sscanf(line, "<%[^>]>%[^<]</%s", tag, value, tag) == 3) {
            append_node(head, tag, value);
        }
    }
}

void print_xml_nodes(const XMLNode *node) {
    while (node != NULL) {
        printf("Tag: %s, Value: %s\n", node->tag, node->value);
        node = node->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.xml>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    XMLNode *xml_nodes = NULL;
    parse_xml(file, &xml_nodes);
    fclose(file);

    print_xml_nodes(xml_nodes);
    free_nodes(xml_nodes);

    return EXIT_SUCCESS;
}