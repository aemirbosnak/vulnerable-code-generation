//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_SIZE 50 //maximum size of summary in words
#define MAX_SENTENCE_SIZE 100 //maximum size of sentence in characters
#define MAX_WORD_SIZE 20 //maximum size of word in characters
#define MAX_INPUT_SIZE 100000 //maximum size of input text in characters

// function to check if a character is a punctuation mark
int is_punct(char c) {
  char punctuations[] = {'.', ',', ';', ':', '!', '?', '-', '(', ')', '[', ']', '{', '}', '\"', '\''};
  int i;
  
  for (i = 0; i < strlen(punctuations); i++) {
    if (c == punctuations[i])
      return 1;
  }
  
  return 0;
}

int main() {
  char input_text[MAX_INPUT_SIZE]; //input text
  char temp_sentence[MAX_SENTENCE_SIZE]; //temporary sentence for processing
  char summary[MAX_SUMMARY_SIZE][MAX_WORD_SIZE]; //array to store summary words
  char temp_word[MAX_WORD_SIZE]; //temporary word for processing
  int word_count = 0; //total number of words in input text
  int sentence_count = 0; //total number of sentences in input text
  int summary_count = 0; //total number of words in summary
  int i, j, k;
  
  printf("Enter the input text:\n");
  fgets(input_text, MAX_INPUT_SIZE, stdin); //read input text from standard input
  
  // remove new line character from input text
  if (input_text[strlen(input_text) - 1] == '\n')
    input_text[strlen(input_text) - 1] = '\0';
  
  // process input text to extract sentences and words
  i = 0;
  while (input_text[i] != '\0') {
    // ignore white spaces at the beginning
    while (isspace(input_text[i]))
      i++;
      
    // start of a new sentence
    if (isupper(input_text[i])) {
      j = i;
      k = 0;
      while (input_text[j] != '\0') {
        temp_sentence[k] = input_text[j]; //copy sentence to temporary variable
        // end of sentence
        if (input_text[j] == '.' || input_text[j] == '?' || input_text[j] == '!') {
          temp_sentence[k + 1] = '\0';
          sentence_count++; //increment sentence count
          k = 0;
          i = j + 1;
          
          // process sentence to extract words
          j = 0;
          while (temp_sentence[j] != '\0') {
            // ignore white spaces at the beginning
            while (isspace(temp_sentence[j]))
              j++;
              
            k = 0;
            while (!isspace(temp_sentence[j]) && !is_punct(temp_sentence[j])) {
              temp_word[k] = temp_sentence[j]; //copy word to temporary variable
              k++;
              j++;
            }
            temp_word[k] = '\0';
            word_count++; //increment word count
            
            // check if word is a summary word
            if ((word_count <= MAX_SUMMARY_SIZE) && (summary_count + strlen(temp_word) <= MAX_SUMMARY_SIZE * MAX_WORD_SIZE)) {
              strcpy(summary[summary_count], temp_word); //copy word to summary array
              summary_count += strlen(temp_word) + 1; //increment summary count
            }
          }
          
          break;
        }
        k++;
        j++;
      }
    }
    // ignore other characters
    else
      i++;
  }
  
  // print summary
  printf("Summary:\n");
  for (i = 0; i < summary_count; i += strlen(summary[i]) + 1) {
    printf("%s ", summary[i]);
  }
  printf("\n");
  
  return 0;
}