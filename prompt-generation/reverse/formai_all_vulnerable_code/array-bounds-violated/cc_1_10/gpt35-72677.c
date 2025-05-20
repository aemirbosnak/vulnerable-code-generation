//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_SIZE 10
#define MAX_TIME 60

char** generate_words(int num_words);
int calculate_score(float num_words_typed, float seconds_elapsed);

int main() {
  srand(time(0)); // initialize random seed

  printf("Welcome to the Typing Speed Test!\n");
  printf("You will have %d seconds to type as many words as you can.\n", MAX_TIME);
  printf("Ready? Press enter to start.\n");
  getchar();

  char** words = generate_words(50);
  int num_words_typed = 0;
  time_t start_time = time(0); // get current time

  while (difftime(time(0), start_time) < MAX_TIME) {
    int word_idx = rand() % 50;
    printf("%s ", words[word_idx]);

    char input[WORD_SIZE];
    scanf("%s", input);
    num_words_typed++;

    if (strcmp(input, words[word_idx]) != 0) {
      printf("Incorrect! The correct word was %s.\n", words[word_idx]);
    }
  }

  float seconds_elapsed = difftime(time(0), start_time);
  int score = calculate_score(num_words_typed, seconds_elapsed);

  printf("\nTime's up! You typed %d words in %.2f seconds.\n", num_words_typed, seconds_elapsed);
  printf("Your score is: %d wpm.\n", score);

  return 0;
}

char** generate_words(int num_words) {
  char* word_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine",
                       "orange", "peach", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "apricot", "blueberry", "coconut", "durian",
                       "grapefruit", "huckleberry", "jackfruit", "kumquat", "lime", "mulberry", "papaya", "pineapple", "raisin", "tamarind", "ugli fruit",
                       "vanilla", "walnut", "yam", "zucchini", "avocado", "bean", "carrot", "daikon", "eggplant", "fennel", "garlic", "hazelnut",
                       "jicama", "kale", "lettuce", "mushroom", "nutmeg", "olive", "pepper", "radish", "squash", "tomato", "watercress", "yucca",
                       "almond", "broccoli", "cauliflower", "date", "elderberry", "fig", "guava", "jalapeno", "kiwi", "leek", "mandarin",
                       "nectarine", "okra", "passionfruit", "quince", "rutabaga", "sage", "tangelo", "ume", "vanilla", "watermelon", "xigua",
                       "yuzu", "zuchinni"};
  char** words = malloc(num_words * sizeof(char*));

  for (int i = 0; i < num_words; i++) {
    int word_idx = rand() % 100;
    words[i] = word_list[word_idx];
  }

  return words;
}

int calculate_score(float num_words_typed, float seconds_elapsed) {
  float wpm = num_words_typed / (seconds_elapsed / 60.0);
  return (int) wpm;
}