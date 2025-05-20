#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void add_candidate(char **candidates, int *num_candidates) {
  char name[100];
  printf("Enter candidate name: ");
  scanf("%s", name);
  *candidates = realloc(*candidates, (*num_candidates + 1) * sizeof(char *));
  candidates[*num_candidates] = strdup(name);
  (*num_candidates)++;
}

int main() {
  char **candidates = NULL;
  int num_candidates = 0;

  add_candidate(&candidates, &num_candidates);
  add_candidate(&candidates, &num_candidates);

  for (int i = 0; i < num_candidates; i++) {
    printf("Candidate name: %s\n", candidates[i]);
  }

  return 0;
}
