//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_METADATA_LENGTH 256

typedef struct Metadata {
    char key[MAX_METADATA_LENGTH];
    char value[MAX_METADATA_LENGTH];
    struct Metadata *next;
} Metadata;

void add_metadata(Metadata **head, const char *key, const char *value) {
    Metadata *new_meta = (Metadata *)malloc(sizeof(Metadata));
    strcpy(new_meta->key, key);
    strcpy(new_meta->value, value);
    new_meta->next = *head;
    *head = new_meta;
}

void print_metadata(Metadata *head) {
    if (head == NULL) return;
    
    printf("Key: %s, Value: %s\n", head->key, head->value);
    print_metadata(head->next);
}

void free_metadata(Metadata *head) {
    if (head == NULL) return;

    free_metadata(head->next);
    free(head);
}

void extract_metadata(const char *line, Metadata **metadata) {
    char key[MAX_METADATA_LENGTH];
    char value[MAX_METADATA_LENGTH];
    if (sscanf(line, "%s : %s", key, value) == 2) {
        add_metadata(metadata, key, value);
    }
}

void read_file(const char *file_path, Metadata **metadata) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        extract_metadata(line, metadata);
    }
    
    fclose(file);
}

void display_usage() {
    printf("Usage: metadata_extractor <file_path>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    Metadata *metadata = NULL;
    
    read_file(argv[1], &metadata);
    
    printf("\nExtracted Metadata:\n");
    print_metadata(metadata);
    
    free_metadata(metadata);
    
    return EXIT_SUCCESS;
}