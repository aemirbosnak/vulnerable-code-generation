//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
  char *word;
  struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
  WordNode *newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

void countWords(WordNode *head) {
  int wordCount = 0;
  WordNode *currNode = head;

  while (currNode) {
    wordCount++;
    currNode = currNode->next;
  }

  printf("Total number of words: %d\n", wordCount);
}

int main() {
  WordNode *head = NULL;
  char word[20];

  printf("Enter a list of words, separated by commas: ");
  scanf("%s", word);

  char *words[] = {word, NULL};
  insertWord(head, words[0]);

  countWords(head);

  return 0;
}