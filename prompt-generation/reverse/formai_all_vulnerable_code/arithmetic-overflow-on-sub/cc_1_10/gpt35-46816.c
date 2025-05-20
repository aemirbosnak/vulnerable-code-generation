//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 30
#define TOTAL_WORDS 10

char word_list[TOTAL_WORDS][MAX_WORD_LENGTH] = {
  "paranoid", "security", "encryption", "hacker", "firewall", 
  "password", "virus", "malware", "intruder", "authentication"
};

int main() {
  printf("Welcome to the Paranoid Typing Speed Test!\n\n");
  printf("You will be given 10 random words to type as fast and accurately as possible.\n");
  printf("Don't worry, we won't be tracking your keystrokes... or will we?\n");
  printf("Just kidding, we're not that paranoid... or are we?\n");

  srand(time(NULL));
  char input_word[MAX_WORD_LENGTH];
  int total_correct_words = 0;
  int total_wrong_words = 0;
  for(int i = 0; i < TOTAL_WORDS; i++) {
    int random_index = rand() % TOTAL_WORDS;
    printf("\nWord %d: %s\n", i+1, word_list[random_index]);
    printf("Type the word and press Enter: ");

    fgets(input_word, MAX_WORD_LENGTH, stdin);
    input_word[strcspn(input_word, "\n")] = 0; // Remove newline character

    bool is_correct_word = (strcmp(input_word, word_list[random_index]) == 0);
    if(is_correct_word) {
      printf("Correct!\n");
      total_correct_words++;
    } else {
      printf("Wrong!\n");
      total_wrong_words++;
    }

    // Make a paranoid delay before displaying the next word
    int delay = rand() % 501 + 500; // Random delay between 500ms and 1000ms
    printf("Analyzing typing patterns... Please wait for %d milliseconds.\n", delay);
    clock_t start_time = clock();
    while((clock() - start_time) < delay * CLOCKS_PER_SEC / 1000); 
    
    if(i == (TOTAL_WORDS - 1)) {
      printf("\nFinished!\n");
      printf("Total words typed: %d\n", total_correct_words + total_wrong_words);
      printf("Total correct words: %d\n", total_correct_words);
      printf("Total wrong words: %d\n", total_wrong_words);
      printf("Paranoid Score: %.2f%%\n", (float)total_correct_words / TOTAL_WORDS * 100);
    }
  }

  return 0;
}