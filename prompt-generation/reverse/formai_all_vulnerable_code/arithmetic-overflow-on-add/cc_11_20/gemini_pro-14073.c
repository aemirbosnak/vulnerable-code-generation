//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

int main() {
  char *s = NULL;
  char *t = NULL;
  int i;
  int j;
  int k;
  int l;

  printf(BLUE "Welcome to the Paranoid Error Handling Program!" RESET "\n");
  printf(YELLOW "Please enter a string: " RESET);
  s = malloc(100);
  if (s == NULL) {
    perror(RED "Error: malloc failed!" RESET);
    exit(EXIT_FAILURE);
  }
  fgets(s, 100, stdin);

  printf(GREEN "String entered: " RESET "%s\n", s);
  printf(YELLOW "Please enter another string: " RESET);
  t = malloc(100);
  if (t == NULL) {
    perror(RED "Error: malloc failed!" RESET);
    exit(EXIT_FAILURE);
  }
  fgets(t, 100, stdin);

  printf(GREEN "Second string entered: " RESET "%s\n", t);
  printf(YELLOW "Please enter the number of characters to compare: " RESET);
  scanf("%d", &i);

  printf(GREEN "Number of characters to compare: " RESET "%d\n", i);
  for (j = 0; j < i; j++) {
    if (s[j] != t[j]) {
      printf(RED "Error: Characters at index %d are different!" RESET "\n", j);
      exit(EXIT_FAILURE);
    }
  }

  printf(GREEN "The first %d characters of the two strings are the same.\n", i);
  printf(YELLOW "Please enter the starting index of the substring to compare: " RESET);
  scanf("%d", &k);

  printf(GREEN "Starting index of the substring to compare: " RESET "%d\n", k);
  for (l = k; l < k + i; l++) {
    if (s[l] != t[l]) {
      printf(RED "Error: Characters at index %d are different!" RESET "\n", l);
      exit(EXIT_FAILURE);
    }
  }

  printf(GREEN "The substring of length %d starting at index %d of the two strings are the same.\n", i, k);
  printf(YELLOW "Please enter the length of the substring to compare: " RESET);
  scanf("%d", &i);

  printf(GREEN "Length of the substring to compare: " RESET "%d\n", i);
  for (j = 0; j < i; j++) {
    if (s[j] != t[j]) {
      printf(RED "Error: Characters at index %d are different!" RESET "\n", j);
      exit(EXIT_FAILURE);
    }
  }

  printf(GREEN "The first %d characters of the two strings are the same.\n", i);
  printf(YELLOW "Please enter the starting index of the substring to compare: " RESET);
  scanf("%d", &k);

  printf(GREEN "Starting index of the substring to compare: " RESET "%d\n", k);
  for (l = k; l < k + i; l++) {
    if (s[l] != t[l]) {
      printf(RED "Error: Characters at index %d are different!" RESET "\n", l);
      exit(EXIT_FAILURE);
    }
  }

  printf(GREEN "The substring of length %d starting at index %d of the two strings are the same.\n", i, k);
  return 0;
}