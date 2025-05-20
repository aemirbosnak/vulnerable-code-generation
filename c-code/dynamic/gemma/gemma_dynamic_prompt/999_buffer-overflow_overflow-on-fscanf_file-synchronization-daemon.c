#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10] = "";
  char data[100] = "This is a large amount of data that will cause a buffer overflow.";

  scanf("%s", buffer); // Vulnerable line

  if (strcmp(buffer, data) == 0) {
    printf("File synchronization successful.\n");
  } else {
    printf("Error synchronizing file.\n");
  }

  return 0;
}
