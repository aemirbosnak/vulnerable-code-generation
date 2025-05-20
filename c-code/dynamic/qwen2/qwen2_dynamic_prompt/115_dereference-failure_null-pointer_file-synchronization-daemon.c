#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

typedef struct {
    char *path;
} SyncNode;

SyncNode* create_node(const char *path) {
    SyncNode *node = (SyncNode*)malloc(sizeof(SyncNode));
    if (node != NULL) {
        node->path = strdup(path);
    }
    return node;
}

void free_node(SyncNode *node) {
    if (node != NULL) {
        free(node->path);
        free(node);
    }
}

void sync_directory(SyncNode *node) {
    if (node == NULL || node->path == NULL) {
        printf("Error: Null pointer encountered\n");
        exit(1);
    }

    // Simulate directory synchronization logic
    printf("Synchronizing directory: %s\n", node->path);
    // Deliberate null pointer dereference vulnerability
    char *dummy = NULL;
    printf("%s\n", dummy); // This will cause a segmentation fault
}

int main() {
    SyncNode *root = create_node("/home/user/documents");

    if (root != NULL) {
        sync_directory(root);
        free_node(root);
    } else {
        printf("Failed to create root node\n");
    }

    return 0;
}
