//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Cheerful Struct Definitions 🌷
typedef struct Node {
    char name[30];
    int age;
    float gpa;
    struct Node* left;
    struct Node* right;
} Node;

// Cheerful Helper Functions 🤗
Node* create_node(char name[], int age, float gpa) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->gpa = gpa;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int height(Node* node) {
    if (node == NULL) return 0;
    else return 1 + MAX(height(node->left), height(node->right));
}

int MAX(int a, int b) {
    return (a > b) ? a : b;
}

bool is_empty(Node** root) {
    return (*root == NULL);
}

Node* search(Node* root, char name[]) {
    if (root == NULL) return NULL;
    int cmp = strcmp(name, root->name);
    if (cmp < 0) return search(root->left, name);
    if (cmp > 0) return search(root->right, name);
    return root;
}

// Cheerful Binary Search Tree Functions 🌲
Node* insert(Node** root, char name[], int age, float gpa) {
    if (is_empty(root)) *root = create_node(name, age, gpa);
    else {
        Node* temp = *root;
        while (1) {
            int cmp = strcmp(name, temp->name);
            if (cmp < 0) {
                if (temp->left == NULL) {
                    temp->left = create_node(name, age, gpa);
                    break;
                } else temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = create_node(name, age, gpa);
                    break;
                } else temp = temp->right;
            }
        }
    }
    return *root;
}

void display(Node* node, int level) {
    int i;
    for (i = 0; i < level; i++) printf("    ");
    printf("%s\n", node->name);
    if (node->left != NULL) display(node->left, level + 1);
    if (node->right != NULL) display(node->right, level + 1);
}

// Cheerful Main Function 🎉
int main() {
    Node* root = NULL;
    char name[30];
    int age;
    float gpa;
    while (1) {
        printf("\nHello! Welcome to the Cheerful Binary Search Tree!\n");
        printf("Please enter a name to add (type 'exit' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) break;
        printf("Enter the age: ");
        scanf("%d", &age);
        printf("Enter the GPA: ");
        scanf("%f", &gpa);
        root = insert(&root, name, age, gpa);
    }
    printf("\nBinary Search Tree:\n");
    display(root, 0);
    printf("\nHeight: %d\n", height(root));
    return 0;
}