//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a node name or attribute name/value
#define MAX_NAME_LENGTH 50
// Define the maximum number of attributes a node can have
#define MAX_ATTRIBUTES 10
// Define the maximum depth of nested nodes
#define MAX_DEPTH 10

// Struct to hold an attribute name and value
typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_NAME_LENGTH];
} Attribute;

// Struct to hold an XML node
typedef struct {
    char name[MAX_NAME_LENGTH];
    Attribute attributes[MAX_ATTRIBUTES];
    int num_attributes;
    char value[MAX_NAME_LENGTH];
    int depth;
} Node;

// Helper function to parse an individual attribute from a string
Attribute parse_attribute(char* attribute_string) {
    Attribute attribute;
    char* token = strtok(attribute_string, "=");
    strcpy(attribute.name, token);
    token = strtok(NULL, "=");
    // Remove any quotes from the value
    token[strcspn(token, "\"")] = '\0';
    strcpy(attribute.value, token+1);
    return attribute;
}

// Helper function to parse a line (not including the closing tag) into a node
Node parse_node(char* line, int depth) {
    Node node;
    node.num_attributes = 0;
    node.depth = depth;
    char* token = strtok(line, " ");
    strcpy(node.name, token);
    token = strtok(NULL, " ");
    while (token != NULL) {
        node.attributes[node.num_attributes] = parse_attribute(token);
        node.num_attributes++;
        token = strtok(NULL, " ");
    }
    return node;
}

// Main function to parse the entire XML file
void parse_xml(FILE* file) {
    Node node_stack[MAX_DEPTH];
    int depth = 0;
    char line[MAX_NAME_LENGTH*MAX_ATTRIBUTES];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "</") != NULL) {
            depth--;
            Node current_node = node_stack[depth];
            if (strlen(current_node.value) > 0) {
                printf("%*s%s: %s\n", current_node.depth*4, "", current_node.name, current_node.value);
                current_node.value[0] = '\0';
            }
            printf("%*s</%s>\n", depth*4, "", current_node.name);
        }
        else if (strstr(line, "/>") != NULL) {
            Node current_node = parse_node(line, depth);
            printf("%*s<%s", depth*4, "", current_node.name);
            for (int i = 0; i < current_node.num_attributes; i++) {
                printf(" %s=\"%s\"", current_node.attributes[i].name, current_node.attributes[i].value);
            }
            printf("/>\n");
        }
        else if (strstr(line, "<") != NULL) {
            Node current_node = parse_node(line, depth);
            node_stack[depth] = current_node;
            printf("%*s<%s", depth*4, "", current_node.name);
            for (int i = 0; i < current_node.num_attributes; i++) {
                printf(" %s=\"%s\"", current_node.attributes[i].name, current_node.attributes[i].value);
            }
            printf(">\n");
            depth++;
        }
        else {
            Node current_node = node_stack[depth-1];
            strcat(current_node.value, line);
        }
    }
}

int main() {
    FILE* file = fopen("example.xml", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }
    parse_xml(file);
    fclose(file);
    return 0;
}