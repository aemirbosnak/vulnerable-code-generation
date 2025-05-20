//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Magic 8-ball answers
const char *answers[] = {
  "It is certain.",
  "It is decidedly so.",
  "Without a doubt.",
  "Yes, definitely.",
  "You may rely on it.",
  "As I see it, yes.",
  "Most likely.",
  "Outlook good.",
  "Signs point to yes.",
  "Yes.",
  "Reply hazy, try again.",
  "Ask again later.",
  "Better not tell you now.",
  "Cannot predict now.",
  "Concentrate and ask again.",
  "Don't bet on it.",
  "My reply is no.",
  "My sources say no.",
  "Outlook not so good.",
  "Very doubtful."
};

int main() {
  int random_number;
  char question[100];

  // Seed random number generator
  srand(time(NULL));

  printf("Welcome to the Magical 8-Ball Fortune Teller!\n");
  printf("Ask me a question and I will tell you the answer.\n");
  printf("Question: ");
  scanf("%s", question);

  // Shake the 8-ball
  printf("\nShaking the 8-ball...\n");
  sleep(1);

  // Generate random number
  random_number = rand() % 20;

  // Print fortune
  printf("Answer: %s\n", answers[random_number]);

  return 0;
}