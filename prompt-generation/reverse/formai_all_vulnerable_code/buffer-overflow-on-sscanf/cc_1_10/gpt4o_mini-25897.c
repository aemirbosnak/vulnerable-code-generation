//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
} XMLNode;

typedef struct {
    XMLNode nodes[MAX_LINES];
    int count;
} XMLDocument;

void init_document(XMLDocument *doc) {
    doc->count = 0;
}

void add_node(XMLDocument *doc, const char *key, const char *value) {
    if (doc->count < MAX_LINES) {
        strncpy(doc->nodes[doc->count].key, key, MAX_LENGTH);
        strncpy(doc->nodes[doc->count].value, value, MAX_LENGTH);
        doc->count++;
    } else {
        fprintf(stderr, "Document is full, cannot add more nodes.\n");
    }
}

void parse_line(XMLDocument *doc, const char *line) {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];

    // Simple parsing - assumes format: <key>value</key>
    if (sscanf(line, " <%[^>]>%[^<]</%[^>]>", key, value, key) == 3) {
        add_node(doc, key, value);
    } else {
        fprintf(stderr, "Invalid XML format: %s\n", line);
    }
}

void read_xml(const char *filename, XMLDocument *doc) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_line(doc, line);
    }

    fclose(file);
}

void print_document(const XMLDocument *doc) {
    for (int i = 0; i < doc->count; i++) {
        printf("Key: %s, Value: %s\n", doc->nodes[i].key, doc->nodes[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLDocument doc;
    init_document(&doc);
    
    read_xml(argv[1], &doc);
    print_document(&doc);

    return EXIT_SUCCESS;
}