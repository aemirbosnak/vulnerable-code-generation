//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 20

typedef struct {
  char *word;
  int count;
} Word;

typedef struct {
  Word words[MAX_WORDS];
  int size;
} Dictionary;

Dictionary *create_dictionary() {
  Dictionary *dict = malloc(sizeof(Dictionary));
  dict->size = 0;
  return dict;
}

void add_word(Dictionary *dict, char *word) {
  int i;
  for (i = 0; i < dict->size; i++) {
    if (strcmp(dict->words[i].word, word) == 0) {
      dict->words[i].count++;
      return;
    }
  }
  if (dict->size == MAX_WORDS) {
    printf("Dictionary is full!\n");
    return;
  }
  dict->words[dict->size].word = malloc(strlen(word) + 1);
  strcpy(dict->words[dict->size].word, word);
  dict->words[dict->size].count = 1;
  dict->size++;
}

void free_dictionary(Dictionary *dict) {
  int i;
  for (i = 0; i < dict->size; i++) {
    free(dict->words[i].word);
  }
  free(dict);
}

int is_spam(char *message) {
  Dictionary *dict = create_dictionary();
  char *words[MAX_LEN];
  int i, num_words = 0;
  char *token = strtok(message, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }
  for (i = 0; i < num_words; i++) {
    add_word(dict, words[i]);
  }
  int num_spam_words = 0;
  for (i = 0; i < dict->size; i++) {
    if (dict->words[i].count > 1) {
      num_spam_words++;
    }
  }
  free_dictionary(dict);
  return num_spam_words > 0;
}

int main() {
  char message[100];
  printf("Enter a message: ");
  gets(message);
  if (is_spam(message)) {
    printf("This message is spam!\n");
  } else {
    printf("This message is not spam.\n");
  }
  return 0;
}