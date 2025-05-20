//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>

int main(){
  printf("Welcome to the Text Summarizer Program\n");

  // Input text
  char text[10000];
  printf("Please enter the text to be summarized:\n");
  fgets(text, sizeof(text), stdin);

  // Initialize summary variables
  int num_sentences = 0;
  int num_words = 0;
  int num_chars = 0;

  // Loop through each character to count words, sentences, and characters
  for(int i=0; i < sizeof(text); i++){
    // Count characters
    if(text[i] != '\0' && text[i] != '\n'){
      num_chars++;
    }
    // Count words
    if((text[i] == ' ' || text[i] == '\n') && (text[i-1] != ' ' && text[i-1] != '\n')){
      num_words++;
    }
    // Count sentences
    if(text[i] == '.' && text[i+1] == ' '){
      num_sentences++;
    }
  }

  // Calculate average words per sentence and characters per word
  float avg_words_per_sentence = (float) num_words / (float) num_sentences;
  float avg_chars_per_word = (float) num_chars / (float) num_words;

  // Print summary statistics
  printf("\nNumber of characters: %d\n", num_chars);
  printf("Number of words: %d\n", num_words);
  printf("Number of sentences: %d\n", num_sentences);
  printf("Average words per sentence: %.2f\n", avg_words_per_sentence);
  printf("Average characters per word: %.2f\n", avg_chars_per_word);

  // Summarize text by first identifying the most common words
  char common_words[5][10] = {"the", "and", "of", "to", "a"};
  int common_word_count[5] = {0};
  int temp_count = 0;
  char temp_word[10] = "";

  for(int i=0; i < sizeof(text); i++){
    if(text[i] == ' ' || text[i] == '\n' || text[i] == '.'){
      // Check if current word is a common word
      int match = 0;
      for(int j=0; j < 5; j++){
        if(strcmp(temp_word, common_words[j]) == 0){
          common_word_count[j]++;
          match = 1;
          break;
        }
      }
      // If current word is not a common word, reset temp_count and temp_word
      if(match == 0){
        temp_count = 0;
        strcpy(temp_word, "");
      }
      // Reset temp_word if sentence is ended
      if(text[i] == '.'){
        strcpy(temp_word, "");
      }
    } else {
      strncat(temp_word, &text[i], 1);
      temp_count++;
    }
  }

  // Identify most common word
  int max_count = 0;
  char most_common_word[10] = "";
  for(int i=0; i < 5; i++){
    if(common_word_count[i] > max_count){
      max_count = common_word_count[i];
      strcpy(most_common_word, common_words[i]);
    }
  }

  // Summarize text by finding sentences with most common word
  printf("\nSummary:\n");
  temp_count = 0;
  char summary[1000] = "";
  for(int i=0; i < sizeof(text); i++){
    if(text[i] != '\0' && text[i] != '\n'){
      strncat(summary, &text[i], 1);
      temp_count++;
    }
    if(text[i] == '.' && text[i+1] == ' '){
      // Check if sentence contains most common word
      if(strstr(summary, most_common_word) != NULL){
        printf("%s ", summary);
      }
      strcpy(summary, "");
      temp_count = 0;
    }
  }

  printf("\nThank you for using the Text Summarizer Program! Goodbye.\n");
  return 0;
}