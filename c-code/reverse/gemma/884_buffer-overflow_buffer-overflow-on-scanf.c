#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char password[1024];
  scanf("%s", password);
  if (strlen(password) >= 8) {
    printf("Strong password\n");
  } else {
    printf("Weak password\n");
  }
  return 0;
}
