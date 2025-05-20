//FormAI DATASET v1.0 Category: Binary search trees ; Style: modular
#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

/** Function to create a new node **/
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

/** Function to insert a new node **/
struct node* insert(struct node* node, int val) {
    /** If tree is empty, return a new node**/
    if (node == NULL) return newNode(val);

    /** Otherwise, recur down the tree**/
    if (val < node->val)
        node->left  = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);   

    /** return the (unchanged) node pointer **/
    return node;
}

/** Function to search a key **/
struct node* search(struct node* root, int key) {
    /** Base Cases: root is null or key is present at root**/
    if (root == NULL || root->val == key)
       return root;
    
    /** Key is greater than root's val**/
    if (root->val < key)
       return search(root->right, key);
 
    /** Key is smaller than root's val**/
    return search(root->left, key);
}

/** Function to find minimum value node in given BST **/
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    /** loop down to find the leftmost leaf **/
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**Function to delete a key from BST **/
struct node* deleteNode(struct node* root, int key) {
    /** Base Case **/
    if (root == NULL) return root;

    /** If the key to be deleted is smaller than the root's val,
        then it lies in left subtree**/
    if (key < root->val)
        root->left = deleteNode(root->left, key);

    /** If the key to be deleted is greater than the root's val,
        then it lies in right subtree**/
    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    /** if key is same as root's val, then This is the node
        to be deleted**/
    else {
        /** node with only one child or no child **/
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        /** node with two children: Get the inorder successor (smallest
            in the right subtree)**/
        struct node* temp = minValueNode(root->right);

        /** Copy the inorder successor's content to this node **/
        root->val = temp->val;

        /** Delete the inorder successor**/
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

/**Function to print the tree**/
void printTree(struct node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d \n", root->val);
        printTree(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, val, flag = 0;
    printf("Binary Search Tree Operations:\n");
    while(1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d", &val);
                    root = insert(root, val);
                    break;

            case 2: printf("Enter the value to be searched: ");
                    scanf("%d", &val);
                    if(search(root, val) == NULL)
                        printf("Value not found.\n");
                    else
                        printf("Value found.\n");
                    break;

            case 3: printf("Enter the value to be deleted: ");
                    scanf("%d", &val);
                    root = deleteNode(root, val);
                    break;

            case 4: printf("Tree is:\n");
                    printTree(root);
                    break;

            case 5: flag = 1;
                    break;

            default: printf("Invalid choice.\n");
                     break;
        }
        if(flag == 1)
            break;
    }
    return 0;
}