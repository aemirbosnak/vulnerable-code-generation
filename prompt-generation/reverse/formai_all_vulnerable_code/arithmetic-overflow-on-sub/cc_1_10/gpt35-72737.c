//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  char random_word[10];
  char user_input[10];
  int word_index = 0;
  int correct_characters = 0;
  int incorrect_characters = 0;
  int seconds_elapsed = 0;
  int milliseconds_elapsed = 0;
  clock_t start_time, end_time;
  
  // Array of random words to choose from
  char *words[10] = {"abacus", "gravity", "zookeeper", "pancake", "umbrella", 
                     "jigsaw", "monarchy", "mayonnaise", "syndicate", "football"};
  srand(time(NULL));
  
  // Choose a random word from the array
  strcpy(random_word, words[rand() % 10]);
  
  printf("Type the word: %s\n", random_word);
  
  // Start the timer
  start_time = clock();
  
  // Loop through each character in the random word
  while (random_word[word_index] != '\0') {
    // Get user input
    scanf("%c", &user_input[word_index]);
    
    if (user_input[word_index] == random_word[word_index]) {
      correct_characters++;
    } else {
      incorrect_characters++;
    }
    
    // Move to the next character in the word
    word_index++;
  }
  
  // End the timer
  end_time = clock();
  milliseconds_elapsed = (int) ((double) (end_time - start_time) / CLOCKS_PER_SEC * 1000);
  seconds_elapsed = milliseconds_elapsed / 1000;
  
  // Display the results
  printf("Your typing speed test results:\n");
  printf("Correct characters: %d\n", correct_characters);
  printf("Incorrect characters: %d\n", incorrect_characters);
  printf("Time elapsed: %d seconds and %d milliseconds\n", seconds_elapsed, milliseconds_elapsed % 1000);
  
  return 0;
}