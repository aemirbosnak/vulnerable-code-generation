//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWERS 10

typedef struct Oracle {
  char answers[MAX_ANSWERS][256];
  int current_answer_index;
} Oracle;

Oracle oracle;

void initialize_oracle() {
  oracle.current_answer_index = 0;
  for (int i = 0; i < MAX_ANSWERS; i++) {
    oracle.answers[i][0] = '\0';
  }
}

void add_answer(char *answer) {
  if (oracle.current_answer_index >= MAX_ANSWERS - 1) {
    return;
  }
  strcpy(oracle.answers[oracle.current_answer_index++], answer);
}

char *get_answer() {
  if (oracle.current_answer_index == 0) {
    return NULL;
  }
  return oracle.answers[oracle.current_answer_index - 1];
}

int main() {
  initialize_oracle();

  // Get user input
  char question[256];
  printf("What is your question? ");
  scanf("%s", question);

  // Generate answer
  char answer[256];
  sprintf(answer, "The answer to your question, %s, is:", question);

  // Add answer to oracle
  add_answer(answer);

  // Print answer
  printf("%s\n", get_answer());

  return 0;
}