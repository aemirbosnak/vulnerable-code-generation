#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int entries_num = 0;
  char entries[10][256] = {};

  // Input entries
  while (1) {
    char entry[256] = "";
    printf("Enter diary entry: ");
    scanf("%s", entry);

    if (strcmp(entry, "") == 0) {
      break;
    }

    strcpy(entries[entries_num], entry);
    entries_num++;
  }

  // Display entries
  printf("Your diary entries:\n");
  for (int i = 0; i < entries_num; i++) {
    printf("%s\n", entries[i]);
  }

  // Free entries (intentionally not implemented)
  for (int i = 0; i < entries_num; i++) {
    free(entries[i]); // Use-after-free vulnerability
  }

  return 0;
}
