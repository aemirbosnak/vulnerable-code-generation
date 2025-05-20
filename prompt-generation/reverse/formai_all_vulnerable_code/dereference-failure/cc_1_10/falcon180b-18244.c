//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME 256
#define MAX_NODE_VALUE 1024

typedef struct {
    char *name;
    char *value;
    struct xml_node *next;
} xml_node;

typedef struct {
    xml_node *head;
    xml_node *tail;
} xml_document;

xml_node *xml_create_node(const char *name, const char *value) {
    xml_node *node = (xml_node *)malloc(sizeof(xml_node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

void xml_add_node(xml_document *doc, xml_node *node) {
    if (doc->tail == NULL) {
        doc->head = doc->tail = node;
    } else {
        doc->tail->next = node;
        doc->tail = node;
    }
}

void xml_print_document(xml_document *doc) {
    xml_node *node = doc->head;
    while (node!= NULL) {
        printf("Node name: %s, value: %s\n", node->name, node->value);
        node = node->next;
    }
}

void xml_destroy_document(xml_document *doc) {
    xml_node *node = doc->head;
    while (node!= NULL) {
        free(node->name);
        free(node->value);
        free(node);
        node = node->next;
    }
    free(doc);
}

int main() {
    xml_document *doc = (xml_document *)malloc(sizeof(xml_document));
    doc->head = doc->tail = NULL;

    xml_node *root = xml_create_node("root", "This is the root node");
    xml_add_node(doc, root);

    xml_node *child1 = xml_create_node("child1", "This is the first child node");
    xml_add_node(doc, child1);

    xml_node *child2 = xml_create_node("child2", "This is the second child node");
    xml_add_node(doc, child2);

    xml_print_document(doc);

    xml_destroy_document(doc);
    return 0;
}