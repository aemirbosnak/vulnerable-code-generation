//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <time.h>

int main() {
  int score = 0, start_time, end_time;
  char input[1000];

  // Intro
  puts("Welcome to the Super Duper Typing Test!");
  puts("Let's see how fast your fingers can fly!");

  // Instructions
  puts("Here's the drill:");
  puts("  - A random sentence will appear on the screen.");
  puts("  - Your task is to type it exactly as it is.");
  puts("  - Accuracy matters, so take your time!");

  // Ready, set, type!
  printf("Ready to race? Press any key to start...");
  getchar();
  start_time = time(NULL);

  // Generate a random sentence
  char sentence[100];
  FILE *sentences = fopen("sentences.txt", "r");
  int random_index = rand() % 100;
  for (int i = 0; i < random_index; i++) {
    fgets(sentence, 100, sentences);
  }
  fclose(sentences);

  // Display the sentence
  printf("%s", sentence);

  // Start typing!
  fgets(input, 1000, stdin);

  // Calculate time taken
  end_time = time(NULL);

  // Check accuracy
  int correct_characters = 0;
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == input[i]) {
      correct_characters++;
    }
  }

  // Calculate score
  score = (int)((double)correct_characters / strlen(sentence) * 60 / (end_time - start_time));

  // Results
  printf("Your score: %d\n", score);
  if (score < 40) {
    puts("Oops, you've got some room for improvement!");
  } else if (score < 60) {
    puts("Nice typing skills! Keep practicing!");
  } else if (score < 80) {
    puts("Wow, you're a typing whiz!");
  } else {
    puts("Unbelievable! You're a typing ninja!");
  }

  return 0;
}