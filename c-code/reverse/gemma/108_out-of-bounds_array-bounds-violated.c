#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str1[1024], str2[1024], str3[1024];

  fgets(str1, 1024, stdin);
  str1[strcspn(str1, "';<|&")] = ' ';

  fgets(str2, 1024, stdin);
  str2[strcspn(str2, "';<|&")] = ' ';

  fgets(str3, 1024, stdin);
  str3[strcspn(str3, "';<|&")] = '_';

  printf("%s %s %s\n", str1, str2, str3);

  return 0;
}
