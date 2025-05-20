//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
    char name[50];
    int score;
    struct Player *left, *right;
} Player;

Player* createPlayer(char *name, int score) {
    Player *newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->left = newPlayer->right = NULL;
    return newPlayer;
}

Player* insert(Player *root, char *name, int score) {
    if (root == NULL) return createPlayer(name, score);
    if (score < root->score) {
        root->left = insert(root->left, name, score);
    } else {
        root->right = insert(root->right, name, score);
    }
    return root;
}

void inorder(Player *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Player: %s | Score: %d\n", root->name, root->score);
        inorder(root->right);
    }
}

Player* search(Player *root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0) return root;
    if (strcmp(name, root->name) < 0) return search(root->left, name);
    return search(root->right, name);
}

Player* findMin(Player *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Player* deletePlayer(Player *root, char *name) {
    if (root == NULL) return root;
    if (strcmp(name, root->name) < 0) {
        root->left = deletePlayer(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deletePlayer(root->right, name);
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
        Player *temp = findMin(root->right);
        strcpy(root->name, temp->name);
        root->score = temp->score;
        root->right = deletePlayer(root->right, temp->name);
    }
    return root;
}

void playGame(Player **root) {
    char name[50];
    int score;
    int choice;

    while (1) {
        printf("\n--- Multiplayer Score Management ---\n");
        printf("1. Add Score\n");
        printf("2. Remove Player\n");
        printf("3. Display Rankings\n");
        printf("4. Search Player\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", name);
                printf("Enter score: ");
                scanf("%d", &score);
                *root = insert(*root, name, score);
                printf("Score added successfully!\n");
                break;
            case 2:
                printf("Enter player name to remove: ");
                scanf("%s", name);
                *root = deletePlayer(*root, name);
                printf("Player removed successfully!\n");
                break;
            case 3:
                printf("Current Rankings:\n");
                inorder(*root);
                break;
            case 4:
                printf("Enter player name to search: ");
                scanf("%s", name);
                Player *foundPlayer = search(*root, name);
                if (foundPlayer) {
                    printf("Player: %s | Score: %d\n", foundPlayer->name, foundPlayer->score);
                } else {
                    printf("Player not found!\n");
                }
                break;
            case 5:
                printf("Exiting the game. Goodbye!\n");
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    Player *root = NULL;
    playGame(&root);
    return 0;
}