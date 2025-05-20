//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to preprocess the text
char *preprocess(char *text) {
  // Convert all characters to lowercase
  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]);
  }

  // Remove all punctuation marks
  char *new_text = malloc(strlen(text) + 1);
  int j = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      new_text[j++] = text[i];
    }
  }
  new_text[j] = '\0';

  // Return the preprocessed text
  return new_text;
}

// Function to compute the TF-IDF scores
double *compute_tf_idf(char *text, char **vocabulary, int num_words) {
  // Compute the term frequencies
  int *tf = calloc(num_words, sizeof(int));
  for (int i = 0; i < strlen(text); i++) {
    for (int j = 0; j < num_words; j++) {
      if (strstr(text + i, vocabulary[j]) != NULL) {
        tf[j]++;
      }
    }
  }

  // Compute the document frequency
  int *df = calloc(num_words, sizeof(int));
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < strlen(text); j++) {
      if (strstr(text + j, vocabulary[i]) != NULL) {
        df[i]++;
        break;
      }
    }
  }

  // Compute the TF-IDF scores
  double *tfidf = calloc(num_words, sizeof(double));
  for (int i = 0; i < num_words; i++) {
    tfidf[i] = (double)tf[i] * log((double)num_words / df[i]);
  }

  // Free the allocated memory
  free(tf);
  free(df);

  // Return the TF-IDF scores
  return tfidf;
}

// Function to summarize the text
char *summarize(char *text, char **vocabulary, int num_words) {
  // Preprocess the text
  char *preprocessed_text = preprocess(text);

  // Compute the TF-IDF scores
  double *tfidf = compute_tf_idf(preprocessed_text, vocabulary, num_words);

  // Sort the words by their TF-IDF scores
  int *sorted_indices = malloc(num_words * sizeof(int));
  for (int i = 0; i < num_words; i++) {
    sorted_indices[i] = i;
  }
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (tfidf[sorted_indices[i]] < tfidf[sorted_indices[j]]) {
        int temp = sorted_indices[i];
        sorted_indices[i] = sorted_indices[j];
        sorted_indices[j] = temp;
      }
    }
  }

  // Generate the summary
  char *summary = malloc(strlen(text) / 5 + 1);
  int j = 0;
  for (int i = 0; i < num_words; i++) {
    if (j >= strlen(text) / 5) {
      break;
    }
    strcat(summary, vocabulary[sorted_indices[i]]);
    strcat(summary, " ");
    j += strlen(vocabulary[sorted_indices[i]]);
  }

  // Free the allocated memory
  free(preprocessed_text);
  free(tfidf);
  free(sorted_indices);

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Load the vocabulary
  char **vocabulary = malloc(1000 * sizeof(char *));
  int num_words = 0;
  FILE *fp = fopen("vocabulary.txt", "r");
  while (!feof(fp)) {
    char *word = malloc(100);
    fscanf(fp, "%s", word);
    vocabulary[num_words++] = word;
  }
  fclose(fp);

  // Load the text
  char *text = malloc(10000);
  fp = fopen("text.txt", "r");
  while (!feof(fp)) {
    char *line = malloc(1000);
    fgets(line, 1000, fp);
    strcat(text, line);
  }
  fclose(fp);

  // Summarize the text
  char *summary = summarize(text, vocabulary, num_words);

  // Print the summary
  printf("%s", summary);

  // Free the allocated memory
  for (int i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
  free(text);
  free(summary);

  return 0;
}