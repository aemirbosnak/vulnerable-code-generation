#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  int i, n;

  printf("Enter text: ");
  scanf("%d", &n);

  if (n > 1024) {
    printf("Error: Text exceeds buffer size.\n");
  } else {
    for (i = 0; i < n; i++) {
      scanf("%c", &buffer[i]);
    }

    printf("Your text: %s\n", buffer);
  }

  return 0;
}
