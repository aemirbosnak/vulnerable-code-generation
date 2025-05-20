#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  int count = 0;

  printf("Enter text: ");
  gets(text);

  if (strstr(text, "advertising") || strstr(text, "winning") || strstr(text, "watches") || strstr(text, "free")) {
    count++;
  }

  if (count > 0) {
    printf("Message contains spam keywords.\n");
  } else {
    printf("No spam keywords found.\n");
  }

  return 0;
}
