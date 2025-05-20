#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void vote(char candidate[]) {
  char buffer[20];
  scanf("%s", buffer);
  strcpy(candidate, buffer);
}

int main() {
  char candidate[20];
  vote(candidate);
  printf("You voted for: %s", candidate);
  return 0;
}
