//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

pthread_mutex_t lock;
int found = 0;
char *words[MAX_WORDS];
int num_words = 0;

void *thread_func(void *arg) {
  char *word = (char *)arg;
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_words; i++) {
    if (strcmp(word, words[i]) == 0) {
      found = 1;
      break;
    }
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main() {
  pthread_t threads[10];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s", words[num_words]) != EOF) {
    num_words++;
  }
  fclose(fp);

  char *input;
  while ((input = malloc(MAX_WORD_LENGTH)) != NULL) {
    printf("Enter a word (q to quit): ");
    scanf("%s", input);
    if (strcmp(input, "q") == 0) {
      break;
    }

    for (int i = 0; i < 10; i++) {
      pthread_create(&threads[i], &attr, thread_func, input);
    }

    for (int i = 0; i < 10; i++) {
      pthread_join(threads[i], NULL);
    }

    if (found) {
      printf("The word is spelled correctly.\n");
    } else {
      printf("The word is not spelled correctly.\n");
    }
    found = 0;
    free(input);
  }

  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&lock);
  return EXIT_SUCCESS;
}