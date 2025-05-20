//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Function to summarize the text
char *summarize(char *text, int num_sentences) {
  // Split the text into sentences
  char *sentences[100];
  char *sentence;
  int num_sentences_found = 0;
  sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences_found++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Select the top-scoring sentences
  int sentence_scores[100];
  for (int i = 0; i < num_sentences_found; i++) {
    sentence_scores[i] = 0;
    // Calculate the score for each sentence
    char *words[100];
    char *word;
    int num_words_found = 0;
    word = strtok(sentences[i], " ");
    while (word != NULL) {
      sentence_scores[i] += strlen(word);
      num_words_found++;
      word = strtok(NULL, " ");
    }
    // Average the score by the number of words
    sentence_scores[i] /= num_words_found;
  }

  // Sort the sentences by score
  for (int i = 0; i < num_sentences_found; i++) {
    for (int j = i + 1; j < num_sentences_found; j++) {
      if (sentence_scores[i] < sentence_scores[j]) {
        int temp = sentence_scores[i];
        sentence_scores[i] = sentence_scores[j];
        sentence_scores[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Concatenate the top-scoring sentences
  char *summary = malloc(1000);
  summary[0] = '\0';
  for (int i = 0; i < num_sentences && i < num_sentences_found; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to summarize: ");
  gets(text);

  // Get the number of sentences to summarize to
  int num_sentences;
  printf("Enter the number of sentences to summarize to: ");
  scanf("%d", &num_sentences);

  // Summarize the text
  char *summary = summarize(text, num_sentences);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the memory allocated for the summary
  free(summary);

  return 0;
}