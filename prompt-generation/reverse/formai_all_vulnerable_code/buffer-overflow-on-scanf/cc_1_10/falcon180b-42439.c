//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10
#define MAX_SEM 10
#define MAX_INPUT 100

pthread_t threads[MAX_THREADS];
sem_t sem[MAX_SEM];

char input[MAX_INPUT];
int input_size;
int output_size;
char output[MAX_INPUT];

void *thread_func(void *arg) {
  int id = *(int *) arg;
  int start = id * (input_size / MAX_THREADS);
  int end = (id + 1) * (input_size / MAX_THREADS) - 1;

  if (id == MAX_THREADS - 1) {
    end = input_size - 1;
  }

  for (int i = start; i <= end; i++) {
    if (isalpha(input[i])) {
      output[output_size++] = toupper(input[i]);
    }
  }

  sem_post(&sem[id]);

  return NULL;
}

int main() {
  printf("Enter a string: ");
  scanf("%s", input);

  input_size = strlen(input);
  output_size = 0;

  for (int i = 0; i < MAX_THREADS; i++) {
    sem_init(&sem[i], 0, 0);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *) &i);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    sem_wait(&sem[i]);
  }

  output[output_size] = '\0';

  printf("Output: %s\n", output);

  return 0;
}