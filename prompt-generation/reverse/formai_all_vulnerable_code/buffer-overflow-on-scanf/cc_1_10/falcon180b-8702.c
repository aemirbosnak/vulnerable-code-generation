//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function prototypes
void read_file(char *filename, char *buffer);
void shift_word(char *word);
void print_words(char *buffer);

// Main function
int main(int argc, char *argv[]) {
  char filename[MAX_LINE_SIZE];
  char buffer[MAX_LINE_SIZE];

  // Prompt user for filename
  printf("Enter filename: ");
  scanf("%s", filename);

  // Read file into buffer
  read_file(filename, buffer);

  // Shift all words in buffer
  shift_word(buffer);

  // Print shifted words
  print_words(buffer);

  return 0;
}

// Reads file into buffer
void read_file(char *filename, char *buffer) {
  FILE *file;
  char ch;
  int i = 0;

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  while ((ch = fgetc(file))!= EOF) {
    buffer[i++] = ch;
  }

  buffer[i] = '\0';

  fclose(file);
}

// Shifts all words in buffer
void shift_word(char *word) {
  int i, j;

  for (i = 0; i < strlen(word); i++) {
    if (isalpha(word[i])) {
      word[i] = tolower(word[i]);
    }
  }

  for (j = strlen(word) - 1; j >= 0; j--) {
    if (isalpha(word[j])) {
      word[j] = toupper(word[j]);
    }
  }
}

// Prints shifted words in buffer
void print_words(char *buffer) {
  char *word;
  int i;

  word = strtok(buffer, " ");

  while (word!= NULL) {
    shift_word(word);
    printf("%s ", word);
    word = strtok(NULL, " ");
  }
}