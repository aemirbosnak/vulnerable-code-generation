//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

// Node structure for binary tree
typedef struct node {
    char *entry;
    struct node *left, *right;
} node;

node *addEntry(node *root, char *entry) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->entry = (char *)malloc(sizeof(char) * (strlen(entry) + 1));
    strcpy(newNode->entry, entry);
    if (root == NULL) {
        root = newNode;
    } else {
        node *current = root;
        while (1) {
            if (strcmp(current->entry, entry) < 0) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else if (strcmp(current->entry, entry) > 0) {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            } else {
                printf("Entry already exists.\n");
                return NULL;
            }
        }
    }
    return root;
}

void removeEntry(node *root, char *entry) {
    if (root == NULL) {
        printf("Diary is empty.\n");
        return;
    } else if (strcmp(root->entry, entry) == 0) {
        if (root->left == NULL && root->right == NULL) {
            free(root->entry);
            free(root);
            root = NULL;
        } else if (root->left == NULL && root->right!= NULL) {
            root = root->right;
            free(root->entry);
            free(root);
        } else if (root->left!= NULL && root->right == NULL) {
            root = root->left;
            free(root->entry);
            free(root);
        } else {
            node *current = root->left;
            while (current!= NULL && strcmp(current->entry, entry)!= 0) {
                current = current->right;
            }
            if (current!= NULL) {
                if (current->left == NULL && current->right == NULL) {
                    free(current->entry);
                    free(current);
                } else if (current->left == NULL && current->right!= NULL) {
                    current = current->right;
                    free(current->entry);
                    free(current);
                } else if (current->left!= NULL && current->right == NULL) {
                    current = current->left;
                    free(current->entry);
                    free(current);
                } else {
                    current = root->left;
                    while (current!= NULL && strcmp(current->entry, entry)!= 0) {
                        current = current->right;
                    }
                    if (current == NULL) {
                        printf("Entry not found.\n");
                    } else {
                        node *tmp = current;
                        free(current->entry);
                        current->entry = tmp->entry;
                        free(tmp);
                    }
                }
            } else {
                printf("Entry not found.\n");
            }
        }
    } else {
        printf("Entry not found.\n");
    }
}

void printDiary(node *root) {
    if (root == NULL) {
        printf("Diary is empty.\n");
        return;
    } else {
        printf("Diary:\n");
        node *current = root;
        while (current!= NULL) {
            printf("%s\n", current->entry);
            current = current->left? current->left : current->right;
        }
    }
}

int main() {
    node *root = NULL;
    char *entry;

    while (1) {
        printf("Enter an entry: ");
        scanf("%s", entry);
        if (strcmp(entry, "exit") == 0) {
            break;
        }
        root = addEntry(root, entry);
    }

    printDiary(root);
    printf("To remove an entry, enter the entry and press Enter.\n");
    scanf("%s", entry);
    removeEntry(root, entry);
    printDiary(root);

    return 0;
}