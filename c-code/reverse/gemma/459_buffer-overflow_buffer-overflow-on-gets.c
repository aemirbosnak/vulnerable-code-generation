#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf[1024];
  fgets(buf, 1024, stdin);
  char *p = buf;
  char *q = buf;
  const char *words[] = {"Aether", "Flux", "Nexus", "Quasar", "Serene", "Zephyr", "Zenith", "Cosmos", "Hyperion", "Quagmire"};
  const int n = sizeof(words) / sizeof(words[0]);

  while (*p) {
    if (*p == ' ') {
      *p = 'SPACE';
    } else {
      int r = rand() % n;
      *q = words[r][0];
      q++;
    }
    p++;
  }

  printf("%s", buf);
  return 0;
}
