//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
    char name[30];
    int score;
    struct Player *left, *right;
} Player;

Player* createPlayer(const char *name, int score) {
    Player *newPlayer = (Player *)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->left = newPlayer->right = NULL;
    return newPlayer;
}

Player* insertPlayer(Player *root, const char *name, int score) {
    if (root == NULL) return createPlayer(name, score);
    
    if (score < root->score) {
        root->left = insertPlayer(root->left, name, score);
    } else {
        root->right = insertPlayer(root->right, name, score);
    }
    
    return root;
}

void inorderTraversal(Player *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Player: %s, Score: %d\n", root->name, root->score);
        inorderTraversal(root->right);
    }
}

Player* getMinValueNode(Player *node) {
    Player *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Player* deletePlayer(Player *root, int score) {
    if (root == NULL) return root;
    
    if (score < root->score) {
        root->left = deletePlayer(root->left, score);
    } else if (score > root->score) {
        root->right = deletePlayer(root->right, score);
    } else {
        if (root->left == NULL) {
            Player *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Player *temp = root->left;
            free(root);
            return temp;
        }
        
        Player *temp = getMinValueNode(root->right);
        root->score = temp->score;
        strcpy(root->name, temp->name);
        root->right = deletePlayer(root->right, temp->score);
    }
    return root;
}

void freeTree(Player *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void showMenu() {
    printf("\nMultiplayer Game Scoreboard\n");
    printf("1. Add Player\n");
    printf("2. Delete Player\n");
    printf("3. Show Scores\n");
    printf("4. Exit\n");
}

int main() {
    Player *root = NULL;
    int choice, score;
    char name[30];

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", name);
                printf("Enter player score: ");
                scanf("%d", &score);
                root = insertPlayer(root, name, score);
                printf("Player added: %s with score %d\n", name, score);
                break;
            case 2:
                printf("Enter player score to delete: ");
                scanf("%d", &score);
                root = deletePlayer(root, score);
                printf("Player with score %d deleted.\n", score);
                break;
            case 3:
                printf("Current Scores:\n");
                inorderTraversal(root);
                break;
            case 4:
                freeTree(root);
                printf("Exiting the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}