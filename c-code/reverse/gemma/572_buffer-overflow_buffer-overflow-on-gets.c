#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int spam_count = 0;

  gets(message);

  char* keywords[] = {"advertising", "winning", "watches", "free"};

  for (int i = 0; i < 4; i++) {
    if (strstr(message, keywords[i]) != NULL) {
      spam_count++;
    }
  }

  if (spam_count > 0) {
    printf("Warning: Your message contains spam content.\n");
  }

  return 0;
}
