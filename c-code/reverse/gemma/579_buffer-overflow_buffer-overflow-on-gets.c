#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  printf("Enter a message: ");
  fgets(message, 1000, stdin);

  char *spam_keywords[] = {"advertising", "winning", "watches", "free"};
  int num_keywords = 4;

  for (int i = 0; i < num_keywords; i++) {
    if (strstr(message, spam_keywords[i]) != NULL) {
      printf("Message flagged as spam.\n");
      return 0;
    }
  }

  printf("Message is not flagged as spam.\n");
  return 0;
}
