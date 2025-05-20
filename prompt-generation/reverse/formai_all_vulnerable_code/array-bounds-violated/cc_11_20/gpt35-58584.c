//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char word[100];
  char input_data[10000];
  int n = 0, count = 0, word_len = 0, space_count = 0, encoded = 1;

  printf("Enter a sentence: ");
  fgets(input_data, 10000, stdin); 

  while (input_data[n] != '\0') {

    if (input_data[n] == '\n') {
      input_data[n] = '\0'; 
      break;
    }

    if ((input_data[n] >= 'a' && input_data[n] <= 'z') || (input_data[n] >= 'A' && input_data[n] <= 'Z')) {
      word[word_len] = input_data[n];
      word_len++;
      encoded = 0;
    }
    else if (!encoded) {

      word[word_len] = '\0';
      count++;

      for (int i = strlen(word); i > 0; i--)
        printf("%c", word[i-1]);
      printf(":%d ", strlen(word));
      
      word_len = 0;
      encoded = 1;

    }

    space_count = (input_data[n] == ' ') ? space_count+1 : space_count;
    n++;

  }

  if ((input_data[n-1] >= 'a' && input_data[n-1] <= 'z') || (input_data[n-1] >= 'A' && input_data[n-1] <= 'Z')) {

    word[word_len] = '\0';
    count++;
  
    for (int i = strlen(word); i > 0; i--)
      printf("%c", word[i-1]);
    printf(":%d", strlen(word));

  }

  printf("\nTotal word count: %d", count);

  return 0;

}