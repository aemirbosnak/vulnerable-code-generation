//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Structure to hold the word and its frequency
typedef struct {
    char *word;
    int count;
} WordFreq;

// Node for linked list implementation of word frequency counter
typedef struct Node {
    WordFreq data;
    struct Node *next;
} Node;

// Function to add word to linked list or increment its frequency if already present
void addToLinkedList(Node **head, char *word) {
    // Convert word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    // Traverse linked list to check for existing word and increment its frequency
    Node *current = *head;
    while (current != NULL) {
        if (strcmp(current->data.word, word) == 0) {
            current->data.count++;
            return;
        }
        current = current->next;
    }
    
    // Create new node for new word
    Node *newNode = (Node*) malloc(sizeof(Node));
    WordFreq newWord = {word, 1};
    newNode->data = newWord;
    newNode->next = *head;
    *head = newNode;
}

// Function to retrieve total number of words in text file
int getTotalWords(FILE *fp) {
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            count++;
        }
    }
    rewind(fp);
    return count;
}

int main(int argc, char *argv[]) {
    // Check that command line arguments are provided
    if (argc < 2) {
        printf("Error: No input file specified\n");
        return 1;
    }
    
    // Open text file for reading
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open input file\n");
        return 1;
    }
    
    // Read from file and populate linked list with word frequencies
    Node *head = NULL;
    char word[50];
    while (fscanf(fp, "%s", word) != EOF) {
        addToLinkedList(&head, word);
    }
    
    // Print word frequencies to console in descending order
    int totalWords = getTotalWords(fp);
    while (head != NULL) {
        printf("%-15s%.2f%%\n", head->data.word, ((float) head->data.count / totalWords) * 100);
        Node *temp = head;
        head = head->next;
        free(temp->data.word);
        free(temp);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
}