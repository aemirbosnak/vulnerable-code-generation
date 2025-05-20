//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10

typedef struct {
  char word[MAX_WORD_LENGTH];
  int length;
} Word;

void generate_words(Word words[], int num_words) {
  srand(time(NULL));

  for (int i = 0; i < num_words; i++) {
    int length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
    words[i].length = length;
    for (int j = 0; j < length; j++) {
      char c = rand() % 26 + 'a';
      words[i].word[j] = c;
    }
    words[i].word[length] = '\0';
  }
}

void shuffle_words(Word words[], int num_words) {
  for (int i = 0; i < num_words; i++) {
    int j = rand() % num_words;
    Word temp = words[i];
    words[i] = words[j];
    words[j] = temp;
  }
}

int main() {
  Word words[MAX_WORDS];
  int num_words = rand() % MAX_WORDS + 1;
  generate_words(words, num_words);
  shuffle_words(words, num_words);

  printf("Welcome to the C Typing Speed Test!\n");
  printf("You will be typing %d words.\n", num_words);
  printf("Press enter to begin...\n");
  getchar();

  int correct = 0;
  int incorrect = 0;
  int total = 0;

  for (int i = 0; i < num_words; i++) {
    printf("%s\n", words[i].word);
    char input[MAX_WORD_LENGTH];
    scanf("%s", input);
    total++;

    if (strcmp(input, words[i].word) == 0) {
      correct++;
    } else {
      incorrect++;
    }
  }

  printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
  printf("Your overall accuracy is %.2f%%\n", (float)correct / total * 100);

  return 0;
}