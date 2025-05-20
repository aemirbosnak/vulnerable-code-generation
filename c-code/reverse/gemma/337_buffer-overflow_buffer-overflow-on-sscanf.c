#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char recipient[256];
  printf("Enter recipient email address: ");
  scanf("%s", recipient);

  char cmd[1024];
  sprintf(cmd, "rcpt to <%s>", recipient);

  // Send email
  system(cmd);

  return 0;
}
