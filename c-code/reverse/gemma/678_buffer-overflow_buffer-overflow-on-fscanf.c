#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE* file_in = fopen("words.txt", "r");
  FILE* file_out = fopen("translated_words.txt", "w");

  fscanf(file_in, "%s", NULL); // Read and discard the first line (number of words)

  char word[100];
  while (fscanf(file_in, "%s", word) != EOF) {
    char first_letter = word[0];
    word[0] = toupper(first_letter) + 'a' - 'A' + 'a';
    strcat(word, "ay");

    fprintf(file_out, "%s\n", word);
  }

  fclose(file_in);
  fclose(file_out);

  return 0;
}
