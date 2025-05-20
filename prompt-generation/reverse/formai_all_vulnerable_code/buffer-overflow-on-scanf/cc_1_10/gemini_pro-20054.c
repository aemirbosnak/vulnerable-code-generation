//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_QUESTIONS 10

typedef struct player {
  char name[20];
  int score;
} player_t;

typedef struct question {
  char question[100];
  int answer;
} question_t;

int main() {
  // Initialize the players
  player_t players[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
    players[i].score = 0;
  }

  // Initialize the questions
  question_t questions[MAX_QUESTIONS];
  FILE *fp = fopen("questions.txt", "r");
  if (fp == NULL) {
    perror("Error opening questions file");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    fgets(questions[i].question, 100, fp);
    fscanf(fp, "%d", &questions[i].answer);
  }
  fclose(fp);

  // Start the game
  int current_player = 0;
  int current_question = 0;
  while (current_question < MAX_QUESTIONS) {
    // Get the current player's answer
    printf("%s, %s", players[current_player].name, questions[current_question].question);
    int answer;
    scanf("%d", &answer);

    // Check if the answer is correct
    if (answer == questions[current_question].answer) {
      // Increment the player's score
      players[current_player].score++;

      // Print the player's score
      printf("%s's score: %d\n", players[current_player].name, players[current_player].score);
    }

    // Move to the next player and question
    current_player = (current_player + 1) % MAX_PLAYERS;
    current_question++;
  }

  // Print the final scores
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("%s's final score: %d\n", players[i].name, players[i].score);
  }

  return EXIT_SUCCESS;
}