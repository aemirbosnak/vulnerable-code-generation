//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 20
#define NUM_WORDS 10
#define TIME_PER_WORD 1000

char *words[NUM_WORDS] = {
  "Aardvark",
  "Baboon",
  "Cassowary",
  "Dik-dik",
  "Emu",
  "FlyingFish",
  "Giraffe",
  "Hippopotamus",
  "Iguana",
  "Jaguar"
};

int main() {
  int i;
  int score = 0;
  int total_time = 0;
  clock_t start, end;

  printf("Welcome to the C Typing Speed Test!\n");
  printf("Prepare yourself for a wild and wacky adventure!\n");
  printf("Type the following animal names as fast as you can:\n");

  for (i = 0; i < NUM_WORDS; i++) {
    char input[WORD_LENGTH];
    printf("\nType the next animal name: %s\n", words[i]);
    fgets(input, WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcasecmp(words[i], input) == 0) {
      printf("Correct! Keep going!\n");
      score++;
    } else {
      printf("Incorrect! Try again.\n");
    }

    start = clock();
    gets(input);
    end = clock();
    total_time += (end - start);
  }

  printf("\nGame Over! Your final score is: %d words typed correctly in %d milliseconds\n", score, total_time);
  printf("Don't be a sloth, come back and try to beat your score!\n");
  return 0;
}