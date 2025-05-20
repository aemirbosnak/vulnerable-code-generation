//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the data structure for nodes that store the sentiment scores */
typedef struct SentimentNode {
    char *word;
    int score;
    struct SentimentNode *left;
    struct SentimentNode *right;
} SentimentNode;

/* Function to create a new node with a given word and score */
SentimentNode* createNode(char *word, int score) {
    SentimentNode *newNode = (SentimentNode*) malloc(sizeof(SentimentNode));
    newNode->word = word;
    newNode->score = score;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a new node into the binary search tree */
SentimentNode* insertNode(SentimentNode *root, char *word, int score) {
    if (root == NULL) return createNode(word, score);
    if (strcmp(word, root->word) < 0)
        root->left = insertNode(root->left, word, score);
    else if (strcmp(word, root->word) > 0)
        root->right = insertNode(root->right, word, score);
    return root;
}

/* Function to search for a node by its word in the binary search tree */
SentimentNode* searchNode(SentimentNode *root, char *word) {
    if (root == NULL) return NULL;
    if (strcmp(word, root->word) == 0) return root;
    if (strcmp(word, root->word) < 0)
        return searchNode(root->left, word);
    else
        return searchNode(root->right, word);
}

/* Function to recursively traverse and print the binary search tree in order */
void printInOrder(SentimentNode *root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%s: %d\n", root->word, root->score);
    printInOrder(root->right);
}

/* Function to free the memory used by the binary search tree when finished */
void freeTree(SentimentNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* Main function for the sentiment analysis tool */
int main() {
    char word[100];
    int score;
    SentimentNode *root = NULL;

    /* Read the sentiment word list and add the nodes to the binary search tree */
    FILE *sentimentFile = fopen("sentiment_words.txt", "r");
    if (sentimentFile == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }
    while (fscanf(sentimentFile, "%s %d", word, &score) == 2) {
        root = insertNode(root, word, score);
    }
    fclose(sentimentFile);

    /* Read the input text to be analyzed and calculate its overall sentiment score */
    int totalScore = 0;
    int wordCount = 0;
    while (scanf("%s", word) == 1) {
        SentimentNode *node = searchNode(root, word);
        if (node != NULL) {
            totalScore += node->score;
            wordCount++;
        }
    }
    double averageScore = (double) totalScore / wordCount;

    /* Print the overall sentiment score and the sentiment scores of individual words */
    printf("Overall sentiment score: %.2f\n", averageScore);
    printf("Sentiment scores of individual words:\n");
    rewind(stdin);  // Clear the input buffer
    while (scanf("%s", word) == 1) {
        SentimentNode *node = searchNode(root, word);
        if (node != NULL) {
            printf("%s: %d\n", word, node->score);
        }
    }

    /* Free the memory used by the binary search tree */
    freeTree(root);
    return 0;
}