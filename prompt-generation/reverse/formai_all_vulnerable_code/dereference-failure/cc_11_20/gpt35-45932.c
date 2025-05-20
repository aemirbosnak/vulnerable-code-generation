//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100000

int main() {
  printf("Wow, I can't believe I am writing a C code for a Text Summarizer!\n");
  printf("Let's get started, shall we?\n");
  printf("Please enter the text you want to summarize: ");

  char* text = (char*) malloc(MAX_WORDS * sizeof(char));
  fgets(text, MAX_WORDS, stdin);

  printf("Great, now I will summarize the text for you!\n");

  // tokenize the text into sentences
  char* pch = strtok(text, ".!?");

  char* sentences[MAX_SENTENCES];
  int num_sentences = 0;

  while (pch != NULL && num_sentences < MAX_SENTENCES) {
    sentences[num_sentences] = pch;
    pch = strtok(NULL, ".!?");
    num_sentences++;
  }

  // count the number of words in each sentence
  int word_count[num_sentences];
  int total_words = 0;

  for (int i = 0; i < num_sentences; i++) {
    char* sentence = sentences[i];

    char* word = (char*) malloc(strlen(sentence) * sizeof(char));
    int num_words = 0;

    pch = strtok(sentence, " ");

    while (pch != NULL) {
      num_words++;
      pch = strtok(NULL, " ");
    }

    word_count[i] = num_words;
    total_words += num_words;
  }

  // calculate the weight of each sentence
  float weight[num_sentences];

  for (int i = 0; i < num_sentences; i++) {
    float sentence_weight = (float) word_count[i] / (float) total_words;
    weight[i] = sentence_weight;
  }

  // select the most important sentences
  int summary_length = num_sentences / 2;
  int summary_indices[summary_length];

  for (int i = 0; i < summary_length; i++) {
    int max_weight_index = -1;
    float max_weight = -1;

    for (int j = 0; j < num_sentences; j++) {
      if (weight[j] > max_weight) {
        max_weight = weight[j];
        max_weight_index = j;
      }
    }

    summary_indices[i] = max_weight_index;
    weight[max_weight_index] = -1;
  }

  // sort the indices in ascending order
  for (int i = 0; i < summary_length; i++) {
    for (int j = i + 1; j < summary_length; j++) {
      if (summary_indices[i] > summary_indices[j]) {
        int temp = summary_indices[i];
        summary_indices[i] = summary_indices[j];
        summary_indices[j] = temp;
      }
    }
  }

  // output the summary
  printf("\nHere's the summary of your text:\n");

  for (int i = 0; i < summary_length; i++) {
    printf("%s.", sentences[summary_indices[i]]);
  }

  printf("\nThank you for trying out my Text Summarizer program. I hope you found it useful!\n");

  return 0;
}