#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1024];
  int count = 0;
  printf("Enter text: ");
  fgets(text, 1024, stdin);

  char *keywords[] = {"advertising", "winning", "watches", "free"};
  for (int i = 0; i < 4; i++) {
    if (strstr(text, keywords[i]) != NULL) {
      count++;
    }
  }

  if (count > 0) {
    printf("Warning: Text contains spam keywords.\n");
  }

  return 0;
}
