//FormAI DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
// Welcome to the Text Summarizer Program!
// This program uses state-of-the-art algorithms to summarize text and help you save time!

#include <stdio.h>

int main() {
  char text[1000];
  printf("Enter the text that you would like summarized: \n");
  scanf("%[^\n]s", text);

  int num_sentences = 0;
  for (int i = 0; i < strlen(text); i++) {
    // Count the number of sentences in the text
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      num_sentences++;
    }
  }

  // Divide the text into an array of sentences
  char sentences[num_sentences][1000];
  int curr_sentence = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      curr_sentence++;
    } else {
      sentences[curr_sentence][i%1000] = text[i];
    }
  }

  int rankings[num_sentences];
  // Assign a ranking to each sentence based on its length
  for (int i = 0; i < num_sentences; i++) {
    int length = strlen(sentences[i]);
    rankings[i] = length;
  }

  // Sort the sentences based on their ranking
  for (int i = 0; i < num_sentences; i++) {
    for (int j = i+1; j < num_sentences; j++) {
      if (rankings[i] < rankings[j]) {
        char temp[1000];
        strcpy(temp, sentences[i]);
        strcpy(sentences[i], sentences[j]);
        strcpy(sentences[j], temp);
        int temp_ranking = rankings[i];
        rankings[i] = rankings[j];
        rankings[j] = temp_ranking;
      }
    }
  }

  printf("Here is the summary of your text: \n");

  // Print the top 3 ranked sentences
  for (int i = 0; i < 3; i++) {
    if (sentences[i][0] != '\0') {
      printf("%s", sentences[i]);
    }
  }

  return 0;
}