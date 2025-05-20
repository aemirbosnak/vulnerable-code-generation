//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *create_node(int data) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

NODE *insert_node(NODE *root, int data) {
    if(root == NULL) {
        return create_node(data);
    }
    if(data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

NODE *find_min_node(NODE *node) {
    NODE *current_node = node;
    while(current_node->left != NULL) {
        current_node = current_node->left;
    }
    return current_node;
}

NODE *delete_node(NODE *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else {
        if(root->left == NULL) {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder_traversal(NODE *root) {
    if(root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    NODE *root = NULL;
    int num_players = 0;
    printf("Enter the number of players : ");
    scanf("%d", &num_players);
    printf("\nEnter the player names and scores one by one.\n");
    char players[num_players][50];
    int scores[num_players];
    for(int i=0; i<num_players; i++) {
        printf("\nName of player-%d : ", i+1);
        scanf("%s", players[i]);
        printf("Score of player-%d : ", i+1);
        scanf("%d", &scores[i]);
        root = insert_node(root, scores[i]);
    }
    printf("\n");

    int choice, score;
    char player[50];
    do {
        printf("\nMenu\n1. Add a player\n2. Remove a player\n3. Display players\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\nEnter the name of the player : ");
                scanf("%s", player);
                printf("Enter the score of the player : ");
                scanf("%d", &score);
                root = insert_node(root, score);
                printf("\n%s with score %d added successfully!\n", player, score);
                break;
            }
            case 2: {
                printf("\nEnter the name of the player to be removed : ");
                scanf("%s", player);
                printf("Enter the score of the player to be removed : ");
                scanf("%d", &score);
                root = delete_node(root, score);
                printf("\n%s with score %d removed successfully!\n", player, score);
                break;
            }
            case 3: {
                printf("\nList of players : \n");
                for(int i=0; i<num_players; i++) {
                    printf("%s : %d\n", players[i], scores[i]);
                }
                printf("\nCurrent leaderboard (in order of scores) : ");
                inorder_traversal(root);
                printf("\n");
                break;
            }
            case 4: {
                printf("\nThank you for playing!\n");
                break;
            }
            default: {
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}