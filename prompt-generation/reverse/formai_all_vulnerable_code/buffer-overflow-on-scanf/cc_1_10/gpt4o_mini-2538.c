//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 3  // Maximum keys in a B-tree node
#define ORDER (MAX_KEYS + 1) // Order of B-tree

typedef struct Student {
    int id;
    char name[50];
} Student;

typedef struct BTreeNode {
    int n; // Current number of keys
    Student keys[MAX_KEYS]; // Keys
    struct BTreeNode *children[ORDER]; // Child pointers
    int leaf; // Is true if leaf node
} BTreeNode;

BTreeNode *root = NULL;

// Function prototypes
BTreeNode *createNode(int leaf);
void insert(Student student);
void splitChild(BTreeNode *parent, int index);
void insertNonFull(BTreeNode *node, Student student);
void search(BTreeNode *node, int id);
void traverse(BTreeNode *node);

int main() {
    int choice, id;
    Student student;

    while (1) {
        printf("Database Indexing System\n");
        printf("1. Insert student record\n");
        printf("2. Search student by ID\n");
        printf("3. Traverse database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &student.id);
                printf("Enter student name: ");
                scanf("%s", student.name);
                insert(student);
                break;
            case 2:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                search(root, id);
                break;
            case 3:
                printf("Database Records:\n");
                traverse(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

BTreeNode *createNode(int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->n = 0;
    node->leaf = leaf;
    for (int i = 0; i < ORDER; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(Student student) {
    if (root == NULL) {
        root = createNode(1);
    }
    if (root->n == MAX_KEYS) {
        BTreeNode *s = createNode(0);
        s->children[0] = root;
        splitChild(s, 0);
        insertNonFull(s, student);
        root = s;
    } else {
        insertNonFull(root, student);
    }
}

void splitChild(BTreeNode *parent, int index) {
    BTreeNode *fullNode = parent->children[index];
    BTreeNode *newNode = createNode(fullNode->leaf);
    newNode->n = MAX_KEYS / 2;

    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newNode->keys[i] = fullNode->keys[i + MAX_KEYS / 2 + 1];
    }

    if (!fullNode->leaf) {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
            newNode->children[i] = fullNode->children[i + MAX_KEYS / 2 + 1];
        }
    }

    fullNode->n = MAX_KEYS / 2;

    // Insert newNode to parent
    for (int i = parent->n; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newNode;

    for (int i = parent->n - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }

    parent->keys[index] = fullNode->keys[MAX_KEYS / 2];
    parent->n++;
}

void insertNonFull(BTreeNode *node, Student student) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && student.id < node->keys[i].id) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = student;
        node->n++;
    } else {
        while (i >= 0 && student.id < node->keys[i].id) {
            i--;
        }
        i++;
        if (node->children[i]->n == MAX_KEYS) {
            splitChild(node, i);
            if (student.id > node->keys[i].id) {
                i++;
            }
        }
        insertNonFull(node->children[i], student);
    }
}

void search(BTreeNode *node, int id) {
    int i = 0;

    while (i < node->n && id > node->keys[i].id) {
        i++;
    }

    if (i < node->n && id == node->keys[i].id) {
        printf("Student found: ID = %d, Name = %s\n", node->keys[i].id, node->keys[i].name);
        return;
    }

    if (node->leaf) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    search(node->children[i], id);
}

void traverse(BTreeNode *node) {
    int i;
    for (i = 0; i < node->n; i++) {
        if (!node->leaf) {
            traverse(node->children[i]);
        }
        printf("ID: %d, Name: %s\n", node->keys[i].id, node->keys[i].name);
    }
    if (!node->leaf) {
        traverse(node->children[i]);
    }
}