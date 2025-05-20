//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LENGTH 1000

int main(void) {
  char user_input[MAX_LENGTH];
  int word_count = 0;
  int char_count = 0;
  int j = 0;
  int k = 0;
  float time_spent = 0.0f;

  printf("Welcome to the C Typing Speed Test!\n");
  printf("Type the following paragraph as fast as you can:\n");
  
  char paragraph[] = "The quick brown fox jumps over the lazy dog";

  printf("%s\n", paragraph);

  clock_t start = clock();

  fgets(user_input, MAX_LENGTH, stdin);

  clock_t stop = clock();

  time_spent += (float)(stop - start) / CLOCKS_PER_SEC;

  printf("\nYou typed:\n%s", user_input);
  printf("\nTime taken: %.2f seconds\n", time_spent);

  while (user_input[j] != '\0') {
    if (user_input[j] == ' ') {
      word_count++;
    }
    if (user_input[j] != ' ' && user_input[j] != '\n') {
      char_count++;
    }
    j++;
  }

  printf("Number of words typed: %d\n", word_count+1);
  printf("Number of characters typed: %d\n", char_count);

  float wpm = ((float)(word_count+1) / time_spent) * 60;
  float cpm = ((float)char_count / time_spent) * 60;

  printf("Your typing speed is: %.2f wpm\n", wpm);
  printf("Your typing accuracy is: %.2f cpm\n", cpm);

  return 0;
}