//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHARS 50

char words[MAX_WORDS][MAX_CHARS];
char input[MAX_CHARS];
int scores[MAX_WORDS] = {0};
int current_word = 0;

void print_word() {
  printf("%s\n", words[current_word]);
}

int main() {
  FILE *fp;
  clock_t start, end;
  double time_spent;

  fp = fopen("medieval_words.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int i = 0;
  while (fgets(words[i], sizeof(words[i]), fp) != NULL) {
    // remove newline character
    words[i][strlen(words[i]) - 1] = '\0';
    i++;
  }
  fclose(fp);

  start = clock();

  while (current_word < MAX_WORDS) {
    print_word();
    scanf("%s", input);
    if (strcmp(input, words[current_word]) == 0) {
      scores[current_word]++;
    }
    current_word++;
  }

  end = clock();
  time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\nTotal correct words: %d\n", current_word);
  printf("Time spent: %.2fs\n", time_spent);
  for (int i = 0; i < current_word; i++) {
    printf("%s: %d\n", words[i], scores[i]);
  }

  return 0;
}