//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIC_FILE "dictionary.txt"
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
    struct node* next;
} node;

node* newNode(char* word) {
    node* new = (node*)malloc(sizeof(node));
    strcpy(new->word, word);
    new->count = 0;
    new->next = NULL;
    return new;
}

void addWord(node* head, char* word) {
    node* curr = head;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    curr->next = newNode(word);
}

int countWords(FILE* fp, node* head) {
    char word[MAX_WORD_LEN];
    int count = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        node* curr = head;
        while (curr!= NULL) {
            if (strcmp(curr->word, word) == 0) {
                curr->count++;
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL) {
            addWord(head, word);
        }
        count++;
    }
    return count;
}

void printWords(node* head) {
    node* curr = head;
    while (curr!= NULL) {
        printf("%s %d\n", curr->word, curr->count);
        curr = curr->next;
    }
}

int main() {
    FILE* fp;
    fp = fopen(DIC_FILE, "r");
    if (fp == NULL) {
        printf("Dictionary file not found.\n");
        return 1;
    }
    node* head = NULL;
    countWords(fp, head);
    fclose(fp);
    printWords(head);
    return 0;
}