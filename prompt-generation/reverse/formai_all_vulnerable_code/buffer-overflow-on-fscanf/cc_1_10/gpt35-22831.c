//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold XML node information
typedef struct xml_node {
    char* name;
    char* value;
    struct xml_node* children;
    struct xml_node* next;
} xml_node;

// Function prototypes
void parse_xml(char* filename);
xml_node* parse_node(FILE* file);
xml_node* parse_children(FILE* file);
void free_node(xml_node* node);
void print_xml(xml_node* node);
void indent(int depth);

// Main function
int main(int argc, char** argv) {

    // Check if filename argument is provided
    if (argc < 2) {
        printf("Please provide filename.\n");
        return 0;
    }

    // Parse XML file
    parse_xml(argv[1]);

    return 0;
}

// Function to parse XML file
void parse_xml(char* filename) {
    // Open file for reading
    FILE* file = fopen(filename, "r");

    // Check if file exists
    if (!file) {
        printf("File not found.\n");
        return;
    }

    // Parse root node
    xml_node* root = parse_node(file);

    // Close file
    fclose(file);

    // Print XML tree
    print_xml(root);

    // Free memory
    free_node(root);
}

// Function to parse XML node
xml_node* parse_node(FILE* file) {
    // Allocate memory for node
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->name = NULL;
    node->value = NULL;
    node->children = NULL;
    node->next = NULL;

    // Read opening tag
    char tag[256];
    fscanf(file, " <%[^>]>", tag);

    // Extract node name
    strtok(tag, " ");
    node->name = strdup(tag);

    // Extract attributes (optional)
    char* attr = strtok(NULL, "");
    if (attr) {
        // TODO: parse attributes
    }

    // Parse children (optional)
    node->children = parse_children(file);

    // Read closing tag
    char end_tag[256];
    fscanf(file, " </%[^>]>", end_tag);

    // Verify closing tag matches opening tag
    if (strcmp(node->name, end_tag) != 0) {
        printf("Error: opening tag does not match closing tag.\n");
        free_node(node);
        return NULL;
    }

    // Read node value (optional)
    char value[256];
    fscanf(file, " %[^\n]", value);
    if (strlen(value) > 0) {
        // Remove leading/trailing whitespace
        char* p = value;
        while (*p && (*p == ' ' || *p == '\t')) p++;
        char* end = p + strlen(p) - 1;
        while (end > p && (*end == ' ' || *end == '\t')) end--;
        *(end + 1) = 0;

        // Save node value
        node->value = strdup(p);
    }

    // Read next node (optional)
    int c = fgetc(file);
    if (c == '<') {
        ungetc(c, file);
        node->next = parse_node(file);
    } else {
        ungetc(c, file);
    }

    return node;
}

// Function to parse XML children
xml_node* parse_children(FILE* file) {
    // Parse first child (optional)
    int c = fgetc(file);
    if (c != '<') {
        ungetc(c, file);
        return NULL;
    }
    ungetc(c, file);

    // Allocate memory for first child
    xml_node* child = parse_node(file);
    xml_node* cur = child;

    // Parse subsequent children (optional)
    while ((c = fgetc(file)) == '<') {
        ungetc(c, file);
        cur->next = parse_node(file);
        cur = cur->next;
    }
    ungetc(c, file);

    return child;
}

// Function to free XML node
void free_node(xml_node* node) {
    if (node) {
        if (node->name) free(node->name);
        if (node->value) free(node->value);
        free_node(node->children);
        free_node(node->next);
        free(node);
    }
}

// Function to print XML tree
void print_xml(xml_node* node) {
    if (node) {
        // Print opening tag
        indent(0);
        printf("<%s", node->name);

        // Print attributes (optional)
        // TODO: print attributes

        // Print value (optional)
        if (node->value) {
            printf(">%s", node->value);
        } else if (node->children) {
            printf(">\n");
        } else {
            printf("/>\n");
            return;
        }

        // Print children (optional)
        if (node->children) {
            printf("\n");
            print_xml(node->children);
            indent(0);
        }

        // Print closing tag
        printf("</%s>\n", node->name);

        // Print next node (optional)
        print_xml(node->next);
    }
}

// Function to print indentation
void indent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}