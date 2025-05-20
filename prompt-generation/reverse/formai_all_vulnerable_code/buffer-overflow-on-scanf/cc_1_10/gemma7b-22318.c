//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
  char name[20];
  int frequency;
} Word;

Word words[MAX_WORDS] = {
  {"Sword", 10},
  {"Shield", 8},
  {"Dragon", 6},
  {"Knight", 5},
  {"Magic", 4},
  {"Elf", 3},
  {"Dwarf", 2},
  {"Orc", 1},
  {"Goblin", 1},
  {"Troll", 1}
};

int main() {
  time_t start_time, end_time;
  int i, words_per_minute, total_words = 0;
  char input[20];

  start_time = time(NULL);

  printf("Enter a word: ");
  scanf("%s", input);

  for (i = 0; i < MAX_WORDS; i++) {
    if (strcmp(input, words[i].name) == 0) {
      words[i].frequency++;
      total_words++;
    }
  }

  end_time = time(NULL);

  words_per_minute = (total_words * 60) / (end_time - start_time);

  printf("Word frequency:**\n");
  for (i = 0; i < MAX_WORDS; i++) {
    printf("%s: %d\n", words[i].name, words[i].frequency);
  }

  printf("Words per minute: %d\n", words_per_minute);

  return 0;
}