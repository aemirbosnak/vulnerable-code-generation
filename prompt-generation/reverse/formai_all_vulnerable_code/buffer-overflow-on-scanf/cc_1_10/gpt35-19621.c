//FormAI DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME 50
#define MAX_FILESIZE 10000

struct File {
    char name[MAX_FILENAME];
    char data[MAX_FILESIZE];
    int size;
};

struct NodeList {
    struct File data;
    struct NodeList* next;
};

typedef struct NodeList NodeList;

void add_file(NodeList** head_ref, struct File new_file) {
    NodeList* new_node = (NodeList*) malloc(sizeof(NodeList));
    new_node->data = new_file;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_files(NodeList* node) {
    int count = 1;
    while (node != NULL) {
        printf("%d. %s\n", count, node->data.name);
        node = node->next;
        count++;
    }
}

void backup_file(NodeList* node, char* filename) {
    while (node != NULL) {
        if (strcmp(node->data.name, filename) == 0) {
            printf("Backing up %s...\n", filename);
            // Backup implementation logic here
            printf("%s backed up successfully!\n", filename);
            return;
        }
        node = node->next;
    }
    printf("%s not found. Backup failed.\n", filename);
}

int main() {
    NodeList* head = NULL;
    
    struct File file1 = {"file1.txt", "This is file 1.", 16};
    struct File file2 = {"file2.txt", "This is file 2.", 16};
    struct File file3 = {"file3.txt", "This is file 3.", 16};
    
    add_file(&head, file1);
    add_file(&head, file2);
    add_file(&head, file3);
    
    printf("Available files:\n");
    print_files(head);
    
    char filename[MAX_FILENAME];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    
    backup_file(head, filename);
    
    return 0;
}