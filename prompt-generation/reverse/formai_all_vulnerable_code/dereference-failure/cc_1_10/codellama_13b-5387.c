//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: artistic
/*
 * 🌱 🌲 🌳 🌴 🌵 🌷 🌻 🌼 🌽 🌾 🌿
 * 🔍 🔎 🔏 🔐 🔑 🔒 🔓 🔔 🔕 🔖
 * 🎨 🎩 🎪 🎫 🎬 🎭 🎮 🎰 🎱 🎲
 * 🏠 🏡 🏢 🏣 🏤 🏥 🏦 🏧 🏨 🏩
 * 💻 💼 📱 📞 📟 📠 📡 📢 📣 📤
 * 🔄 🔅 🔆 🔇 🔈 🔉 🔊 🔋 🔌 🔍
 * 🔎 🔏 🔐 🔑 🔒 🔓 🔔 🔕 🔖
 * 🌱 🌲 🌳 🌴 🌵 🌷 🌻 🌼 🌽 🌾
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void createBinarySearchTree(struct Node **root) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = 5;
    new_node->left = NULL;
    new_node->right = NULL;
    *root = new_node;
}

void insertNode(struct Node **root, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
    } else {
        struct Node *curr = *root;
        while (curr != NULL) {
            if (curr->data < data) {
                if (curr->right == NULL) {
                    curr->right = new_node;
                    break;
                }
                curr = curr->right;
            } else {
                if (curr->left == NULL) {
                    curr->left = new_node;
                    break;
                }
                curr = curr->left;
            }
        }
    }
}

void inorderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node *root = NULL;
    createBinarySearchTree(&root);
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 13);
    insertNode(&root, 17);
    insertNode(&root, 19);
    insertNode(&root, 11);

    printf("Inorder traversal of the binary search tree is: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}