//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables
  int seconds = 60;
  int score = 0;
  int i = 0;

  // generate random sentences
  char sentences[10][100] = {
    "The quick brown fox jumps over the lazy dog.",
    "How vexingly quick daft zebras jump!",
    "Fickle jinx bog dwarves spy math quiz.",
    "Mr. Jock, TV quiz Ph.D., bags few lynx.",
    "Crazy Fredericka bought many very exquisite opal jewels.",
    "Jackdaws love my big sphinx of quartz.",
    "The five boxing wizards jump quickly.",
    "Pack my box with five dozen liquor jugs.",
    "Sphinx of black quartz, judge my vow.",
    "Jaded zombies acted quaintly but kept driving their oxen forward."
  };

  // seed random number generator
  srand(time(NULL));

  // display instructions
  printf("Welcome to the Surrealist Typing Speed Test!\n");
  printf("You have %d seconds to type as many sentences as possible.\n", seconds);
  printf("Press enter to begin...\n");
  getchar();

  // loop through sentences
  while (i < 10) {
    printf("\n%s\n", sentences[i]);
    clock_t start = clock(); // start timer
    char input[100];
    fgets(input, 100, stdin); // read user input
    clock_t end = clock(); // end timer

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // calculate time taken
    if (time_taken < 5.0 && strcmp(sentences[i], input) == 0) { // check for accuracy and speed
      score++;
      printf("Correct! Your time: %f seconds\n", time_taken);
    } else {
      printf("Incorrect or too slow! Your time: %f seconds\n", time_taken);
    }
    i++;
  }

  // display final score
  printf("\nTime's up! You typed %d correct sentences.\n", score);
  return 0;
}