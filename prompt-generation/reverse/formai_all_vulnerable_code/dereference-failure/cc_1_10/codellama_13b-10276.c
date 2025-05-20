//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

typedef struct {
  char text[MAX_TEXT_LENGTH];
  int length;
} Text;

Text* create_text(char* text) {
  Text* t = malloc(sizeof(Text));
  strcpy(t->text, text);
  t->length = strlen(text);
  return t;
}

void summarize(Text* text) {
  int i, j;
  int word_count = 0;
  int sentence_count = 0;
  char sentence[MAX_TEXT_LENGTH];

  for (i = 0; i < text->length; i++) {
    if (text->text[i] == '.' || text->text[i] == '!' || text->text[i] == '?') {
      sentence_count++;
      word_count = 0;
    } else if (text->text[i] == ' ') {
      word_count++;
    }
  }

  for (i = 0, j = 0; i < text->length && sentence_count > 0; i++) {
    if (text->text[i] == '.' || text->text[i] == '!' || text->text[i] == '?') {
      sentence[j] = '\0';
      printf("%s\n", sentence);
      sentence_count--;
      j = 0;
    } else if (text->text[i] != ' ') {
      sentence[j] = text->text[i];
      j++;
    }
  }

  free(text);
}

int main() {
  char text[] = "The quick brown fox jumps over the lazy dog. The dog is brown.";
  Text* t = create_text(text);
  summarize(t);
  return 0;
}