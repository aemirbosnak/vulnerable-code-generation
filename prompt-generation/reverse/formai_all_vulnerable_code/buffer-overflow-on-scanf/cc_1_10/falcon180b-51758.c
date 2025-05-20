//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_WORD_SIZE 100

// Node structure
struct node {
    char word[MAX_WORD_SIZE];
    int count;
    struct node* next;
};

// Function to create a new node
struct node* createNode(char word[], int count) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    newNode->count = count;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a word in the linked list
int search(struct node* head, char word[]) {
    struct node* current = head;
    while (current!= NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

// Function to add a new word to the linked list
void addWord(struct node* head, char word[], int count) {
    struct node* newNode = createNode(word, count);
    struct node* current = head;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Function to read words from a file
void readWords(FILE* fp, struct node** head) {
    char word[MAX_WORD_SIZE];
    while (fscanf(fp, "%s", word)!= EOF) {
        addWord(*head, word, 1);
    }
}

int main() {
    FILE* fp;
    char filename[MAX_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(0);
    }
    struct node* head = NULL;
    readWords(fp, &head);
    fclose(fp);
    printf("Enter the word to search: ");
    char searchWord[MAX_WORD_SIZE];
    scanf("%s", searchWord);
    int count = search(head, searchWord);
    if (count == 0) {
        printf("Word not found!\n");
    } else {
        printf("Word found %d times!\n", count);
    }
    return 0;
}