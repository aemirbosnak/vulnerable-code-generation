#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp_in, *fp_out;
  char *word, *translated_word;
  int word_length;

  fp_in = fopen("words.txt", "r");
  fp_out = fopen("translated_words.txt", "w");

  if (fp_in == NULL || fp_out == NULL) {
    perror("Error opening file");
    return 1;
  }

  word = malloc(100);
  translated_word = malloc(100);

  while (fscanf(fp_in, "%s", word) != EOF) {
    word_length = strlen(word);
    translated_word = realloc(translated_word, word_length + 5);

    translated_word[0] = toupper(word[0]) + 32;
    strcat(translated_word, word + 1);
    strcat(translated_word, "ay");

    fprintf(fp_out, "%s\n", translated_word);
  }

  fclose(fp_in);
  fclose(fp_out);

  free(word);
  free(translated_word);

  return 0;
}
