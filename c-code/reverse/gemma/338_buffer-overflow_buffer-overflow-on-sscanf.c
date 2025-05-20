#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char email[256];
  scanf("%s", email);
  char buffer[1024];
  sprintf(buffer, "To: %s", email);
  sendmail(buffer);
  return 0;
}

void sendmail(char *message) {
  // Insecure function that sends email
  // (This function is not included in the above code)
}
