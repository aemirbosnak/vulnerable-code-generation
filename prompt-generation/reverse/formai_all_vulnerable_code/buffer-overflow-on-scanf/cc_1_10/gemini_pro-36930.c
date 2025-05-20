//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  printf("Wriggling words, dancing across the screen,\nA surreal symphony, a whimsical dream.\n");

  char *words[] = {
    "fluffernutter",
    "pneumonoultramicroscopicsilicovolcanoconiosis",
    "onomatopoeia",
    "deliquescent",
    "flibbertigibbet",
    "sesquipedalian",
    "ecumenical",
    "harlequin",
    "serendipity",
    "ephemeral",
    "lachrymose",
    "ubiquitous",
    "mellifluous",
    "magnanimous",
    "perspicacious",
    "quixotic",
    "rumbustious",
    "sanguine",
    "ubiquitous",
    "voluptuous",
    "zealous",
  };

  int num_words = sizeof(words) / sizeof(char *);

  printf("Type as many words as you can in 60 seconds!\n");
  printf("Press enter to start...\n");
  getchar();

  time_t start_time = time(NULL);
  int count = 0;

  while (time(NULL) - start_time < 60) {
    int index = rand() % num_words;
    char *word = words[index];

    printf("%s ", word);

    char input[100];
    scanf(" %s", input);

    if (strcmp(input, word) == 0) {
      count++;
    }
  }

  printf("\nYou typed %d words in 60 seconds!\n", count);

  return 0;
}