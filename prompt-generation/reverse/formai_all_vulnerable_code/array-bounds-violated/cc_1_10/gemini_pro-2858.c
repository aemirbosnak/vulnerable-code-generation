//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LEN 20

typedef struct {
  char word[MAX_LEN];
  int len;
} Word;

Word words[MAX_WORDS];
int num_words;

void generate_words() {
  FILE *fp = fopen("/usr/share/dict/words", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char line[MAX_LEN];
  while (fgets(line, MAX_LEN, fp) != NULL) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    if (strlen(line) > 0) {
      strcpy(words[num_words].word, line);
      words[num_words].len = strlen(line);
      num_words++;
    }
  }

  fclose(fp);
}

int main() {
  generate_words();

  srand(time(NULL));

  int i, j, k;
  int correct = 0;
  int total = 0;
  char input[MAX_LEN];

  for (i = 0; i < 10; i++) {
    j = rand() % num_words;

    printf("%s: ", words[j].word);
    scanf("%s", input);

    total++;
    if (strcmp(input, words[j].word) == 0) {
      correct++;
    }
  }

  printf("Correct: %d\n", correct);
  printf("Total: %d\n", total);
  printf("Accuracy: %.2f%%\n", (float)correct / total * 100);

  return 0;
}