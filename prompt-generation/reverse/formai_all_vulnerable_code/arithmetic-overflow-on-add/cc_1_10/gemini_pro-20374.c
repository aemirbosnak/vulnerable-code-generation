//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Sentence {
  char *text;
  int length;
};

struct Paragraph {
  struct Sentence *sentences;
  int num_sentences;
};

struct Text {
  struct Paragraph *paragraphs;
  int num_paragraphs;
};

int main() {
  struct Text text;

  // Read the text from standard input.
  char line[1024];
  while (fgets(line, sizeof(line), stdin)) {
    // Allocate memory for the paragraph.
    struct Paragraph *paragraph = malloc(sizeof(struct Paragraph));
    paragraph->sentences = NULL;
    paragraph->num_sentences = 0;

    // Tokenize the paragraph into sentences.
    char *sentence_text = strtok(line, ".");
    while (sentence_text) {
      // Allocate memory for the sentence.
      struct Sentence *sentence = malloc(sizeof(struct Sentence));
      sentence->text = strdup(sentence_text);
      sentence->length = strlen(sentence_text);

      // Add the sentence to the paragraph.
      paragraph->sentences = realloc(paragraph->sentences, (paragraph->num_sentences + 1) * sizeof(struct Sentence));
      paragraph->sentences[paragraph->num_sentences++] = *sentence;

      // Get the next sentence.
      sentence_text = strtok(NULL, ".");
    }

    // Add the paragraph to the text.
    text.paragraphs = realloc(text.paragraphs, (text.num_paragraphs + 1) * sizeof(struct Paragraph));
    text.paragraphs[text.num_paragraphs++] = *paragraph;
  }

  // Summarize the text.
  for (int i = 0; i < text.num_paragraphs; i++) {
    struct Paragraph *paragraph = &text.paragraphs[i];

    // Find the longest sentence in the paragraph.
    int longest_sentence_index = -1;
    int longest_sentence_length = 0;
    for (int j = 0; j < paragraph->num_sentences; j++) {
      struct Sentence *sentence = &paragraph->sentences[j];
      if (sentence->length > longest_sentence_length) {
        longest_sentence_index = j;
        longest_sentence_length = sentence->length;
      }
    }

    // Print the longest sentence.
    printf("%s.\n", paragraph->sentences[longest_sentence_index].text);
  }

  // Free the memory allocated for the text.
  for (int i = 0; i < text.num_paragraphs; i++) {
    struct Paragraph *paragraph = &text.paragraphs[i];
    for (int j = 0; j < paragraph->num_sentences; j++) {
      struct Sentence *sentence = &paragraph->sentences[j];
      free(sentence->text);
      free(sentence);
    }
    free(paragraph->sentences);
    free(paragraph);
  }
  free(text.paragraphs);

  return 0;
}