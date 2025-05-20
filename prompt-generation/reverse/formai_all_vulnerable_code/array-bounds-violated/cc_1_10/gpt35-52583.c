//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 10000
#define MAX_SENTENCES 500

int count_words(char *string);
float find_average(char *string, int num_sentences);
void summarize_text(char *string, float average_score, int num_sentences);

int main() {
  char string[MAX_STRING_LEN];
  printf("Enter the text to summarize:\n");
  fgets(string, MAX_STRING_LEN, stdin);

  int num_sentences = 0;
  char *token = strtok(string, ".?!");

  while (token != NULL && num_sentences < MAX_SENTENCES) {
    num_sentences++;
    token = strtok(NULL, ".?!");
  }

  float average_score = find_average(string, num_sentences);
  summarize_text(string, average_score, num_sentences);

  return 0;
}

int count_words(char *string) {
  int num_words = 0;
  char *token = strtok(string, " ");
  while (token != NULL) {
    num_words++;
    token = strtok(NULL, " ");
  }
  return num_words;
}

float find_average(char *string, int num_sentences) {
  int num_words = count_words(string);
  float average_score = (float) num_words / num_sentences;
  return average_score;
}

void summarize_text(char *string, float average_score, int num_sentences) {
  int num_words = count_words(string);
  float threshold = 0.7 * average_score;
  char *token = strtok(string, " ");
  int sentence_scores[num_sentences];

  for (int i = 0; i < num_sentences; i++) {
    sentence_scores[i] = 0;
  }

  int sentence_num = 0;
  int num_tokens_in_sentence = 0;

  while (token != NULL) {
    if (strchr(".?!", token[strlen(token) - 1]) != NULL) {
      float score = (float) sentence_scores[sentence_num] / num_tokens_in_sentence;
      if (score > threshold && num_tokens_in_sentence > 2) {
        printf("%s ", token);
        sentence_num++;
      }
      num_tokens_in_sentence = 0;
    } else {
      num_tokens_in_sentence++;
      sentence_scores[sentence_num]++;
      printf("%s ", token);
    }
    token = strtok(NULL, " ");
  }
}