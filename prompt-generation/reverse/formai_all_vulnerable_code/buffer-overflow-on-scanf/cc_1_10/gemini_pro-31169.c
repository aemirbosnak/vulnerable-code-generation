//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
  char *input;
  int length;
  int start;
  int end;
  int palindrome;
} palindrome_check_args;

void *palindrome_checker(void *args) {
  palindrome_check_args *args_ptr = (palindrome_check_args *)args;

  int start = args_ptr->start;
  int end = args_ptr->end;

  int mid = (start + end) / 2;

  int i, j;

  for (i = start, j = end; i <= mid; i++, j--) {
    if (args_ptr->input[i] != args_ptr->input[j]) {
      args_ptr->palindrome = 0;
      return NULL;
    }
  }

  args_ptr->palindrome = 1;

  return NULL;
}

int main() {
  char input[BUFFER_SIZE];
  int length;

  printf("Enter a string: ");
  scanf("%s", input);

  length = strlen(input);

  int num_threads = (length + MAX_THREADS - 1) / MAX_THREADS;

  pthread_t threads[num_threads];

  palindrome_check_args args[num_threads];

  int i;

  for (i = 0; i < num_threads; i++) {
    args[i].input = input;
    args[i].length = length;
    args[i].start = i * length / num_threads;
    args[i].end = (i + 1) * length / num_threads - 1;
    args[i].palindrome = 1;

    pthread_create(&threads[i], NULL, palindrome_checker, (void *)&args[i]);
  }

  for (i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  int palindrome = 1;

  for (i = 0; i < num_threads; i++) {
    palindrome &= args[i].palindrome;
  }

  if (palindrome) {
    printf("The string \"%s\" is a palindrome.\n", input);
  } else {
    printf("The string \"%s\" is not a palindrome.\n", input);
  }

  return 0;
}