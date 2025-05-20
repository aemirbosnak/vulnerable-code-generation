#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char candidate_name[100];
  int voter_id;

  printf("Enter candidate name: ");
  scanf("%s", candidate_name);

  printf("Enter voter ID: ");
  scanf("%d", &voter_id);

  // Logic to validate voter and cast vote

  printf("Vote cast for %s with voter ID %d", candidate_name, voter_id);

  return 0;
}
