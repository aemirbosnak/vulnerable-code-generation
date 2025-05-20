#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char text[100];
  gets(text);

  if (strstr(text, "advertising") || strstr(text, "winning") || strstr(text, "watches") || strstr(text, "free")) {
    printf("Spam detected!");
  } else {
    printf("No spam detected.");
  }

  return 0;
}
