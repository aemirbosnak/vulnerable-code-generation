//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 100
#define WORD_LEN 10

char words[NUM_WORDS][WORD_LEN];
int word_index;
int start_time, end_time;
float wpm;

void init_words() {
  FILE *f = fopen("words.txt", "r");
  for (int i = 0; i < NUM_WORDS; i++) {
    fscanf(f, "%s", words[i]);
  }
  fclose(f);
}

void display_word() {
  printf("%s", words[word_index]);
}

void get_input() {
  char input[WORD_LEN];
  scanf("%s", input);

  if (strcmp(input, words[word_index]) == 0) {
    word_index++;
  } else {
    printf("Error: Incorrect word typed.\n");
  }
}

void calculate_wpm() {
  end_time = clock();
  float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;
  wpm = (float)(word_index / 5) / time_taken;
}

void display_results() {
  printf("Words per minute: %.2f\n", wpm);
}

int main() {
  init_words();
  word_index = 0;

  printf("Starting typing speed test...\n");
  printf("Press any key to start.\n");
  getchar();
 
  start_time = clock();

  while (word_index < NUM_WORDS) {
    display_word();
    get_input();
  }

  calculate_wpm();
  display_results();

  return 0;
}