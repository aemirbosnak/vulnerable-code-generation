//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT_MAX 100000

int main() {
  // Initialize word count array
  int words[WORD_COUNT_MAX];
  memset(words, 0, sizeof(words));

  // Get the file name from the user
  printf("Enter the file name: ");
  char file_name[50];
  scanf("%s", file_name);

  // Open the file
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error: File not found!\n");
    return 1;
  }

  // Read the file and count the words
  char buffer[100];
  while (fgets(buffer, 100, file) != NULL) {
    // Ignore empty lines
    if (strlen(buffer) == 0) continue;

    // Split the line into words
    char *words_array[5];
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL && i < 5) {
      words_array[i++] = token;
      token = strtok(NULL, " ");
    }

    // Count the words
    for (int j = 0; j < i; j++) {
      words[words_array[j][0] - 'a']++;
    }
  }

  // Print the word count
  printf("Word Count:\n");
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", i + 'a', words[i]);
  }

  // Close the file
  fclose(file);

  return 0;
}