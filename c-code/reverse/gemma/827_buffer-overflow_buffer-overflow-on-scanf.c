#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char name[20];
  int vote;

  printf("Enter candidate name: ");
  scanf("%s", name);

  printf("Enter vote: ");
  scanf("%d", &vote);

  switch (vote) {
    case 1:
      printf("Candidate %s received a vote.", name);
      break;
    case 2:
      printf("Candidate %s received a vote.", name);
      break;
    case 3:
      printf("Candidate %s received a vote.", name);
      break;
    default:
      printf("Invalid vote.");
  }

  return 0;
}
