//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char *words[MAX_WORDS];
int frequencies[MAX_WORDS] = {0};
int num_words = 0;

pthread_mutex_t lock;

void *count_word(void *arg) {
  int word_index = *(int*)arg;
  int count = 0;
  char *word = words[word_index];
  
  for (int i = 0; i < num_words; i++) {
    if (strcmp(word, words[i]) == 0) {
      count++;
    }
  }
  
  pthread_mutex_lock(&lock);
  frequencies[word_index] = count;
  pthread_mutex_unlock(&lock);
  
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s FILE\n", argv[0]);
    return 1;
  }
  
  pthread_mutex_init(&lock, NULL);
  
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Unable to open file %s\n", argv[1]);
    return 1;
  }
  
  char word[MAX_WORD_LEN];
  
  while (fscanf(input_file, "%s", word) == 1 && num_words < MAX_WORDS) {
    words[num_words] = strdup(word);
    num_words++;
  }
  
  fclose(input_file);
  
  pthread_t threads[num_words];
  
  for (int i = 0; i < num_words; i++) {
    int *arg = malloc(sizeof(*arg));
    *arg = i;
    
    pthread_create(&threads[i], NULL, count_word, arg);
  }
  
  for (int i = 0; i < num_words; i++) {
    pthread_join(threads[i], NULL);
  }
  
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], frequencies[i]);
  }
  
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  
  return 0;
}