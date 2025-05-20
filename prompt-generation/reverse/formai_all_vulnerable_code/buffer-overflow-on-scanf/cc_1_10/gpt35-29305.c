//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char question[100];
  int answer = 0;

  printf("Hey there, I'm a chatbot! What's your name?\n");

  char name[50];
  scanf("%s", name);

  printf("\nNice to meet you, %s! I'm going to ask you a few questions to get to know you better. Are you ready?\n", name);

  printf("\nGreat! Here's your first question: How do you like your coffee? Black or with cream and sugar?\n");

  scanf("%s", question);

  if (strcmp(question, "black") == 0) {
    printf("\nInteresting choice, %s! Here's your next question: If a tree falls in a forest and no one is around to hear it, does it make a sound?\n", name);
    scanf("%s", question);

    if (strcmp(question, "yes") == 0) {
      printf("\nWow, you're a deep thinker, %s! One more question: Why did the programmer quit his job?\n", name);
      scanf("%s", question);

      if (strcmp(question, "he didn't get arrays") == 0) {
        printf("\nHaha, that's funny, %s! You definitely have a sense of humor. Thanks for chatting with me!\n", name);
        answer = 1;
      }
    }
  } else if (strcmp(question, "with cream and sugar") == 0) {
    printf("\nAh, a classic choice, %s! Here's your next question: If you could have any superpower, what would it be?\n", name);
    scanf("%s", question);

    if (strcmp(question, "flight") == 0) {
      printf("\nCool choice, %s! Here's your last question: Why do programmers prefer dark mode?\n", name);
      scanf("%s", question);

      if (strcmp(question, "less watts means less heat") == 0) {
        printf("\nVery clever, %s! Thanks for chatting with me!\n", name);
        answer = 1;
      }
    }
  }

  if (answer == 0) {
    printf("\nSorry, %s, I don't understand your answer. Let's try this again later.\n", name);
  }

  return 0;
}