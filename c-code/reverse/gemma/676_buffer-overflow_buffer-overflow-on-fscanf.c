#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void translate(char *word, char *translated) {
  translated = malloc(strlen(word) * 2 + 1);
  translated[0] = toupper(word[0]);
  for (int i = 1; word[i] != '\0'; i++) {
    translated[i] = word[i];
  }
  strcat(translated, "ay");
}

int main() {
  char *word;
  char *translated;
  FILE *file_in, *file_out;

  // Open files
  file_in = fopen("words.txt", "r");
  file_out = fopen("translated_words.txt", "w");

  // Read words from file
  fscanf(file_in, "%s", word);

  // Translate word
  translate(word, translated);

  // Write translated word to file
  fprintf(file_out, "%s\n", translated);

  // Free memory and close files
  free(translated);
  fclose(file_in);
  fclose(file_out);

  return 0;
}
