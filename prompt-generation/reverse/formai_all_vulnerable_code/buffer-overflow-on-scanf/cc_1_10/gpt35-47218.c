//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
int toss();
int computerTurn(int remain);
int playerTurn(int remain);
void win(int player);

int main() {
  int player, remain = 21, move;
  srand(time(NULL));
  intro();
  player = toss();
  while (remain > 1) {
    printf("It is %s turn.\n", (player == 1) ? "Player" : "Computer");
    if (player == 1) move = playerTurn(remain);
    else move = computerTurn(remain);
    remain -= move;
    if (remain <= 1) win(player);
    player = (player == 1) ? 2 : 1;
  }
  return 0;
}

void intro() {
  printf("Welcome to the Table Game!\n");
  printf("The rules are simple: There are 21 sticks on the table.\n");
  printf("Players take turns picking up 1-4 sticks, whoever picks up the last stick loses.\n");
}

int toss() {
  int result;
  printf("Let's toss a coin to see who goes first!\n");
  printf("Heads or Tails? (1 for Heads, 0 for Tails)\n");
  scanf("%d", &result);
  result = rand() % 2 == result ? 1 : 2;
  printf("Player %d will go first!\n", result);
  return result;
}

int computerTurn(int remain) {
  printf("Computer is thinking...\n");
  int max = remain >= 4 ? 4 : remain;
  int min = remain == 1 ? 1 : 1 + (remain-2)%4;
  int move = min + rand() % (max-min+1);
  printf("Computer picked up %d stick%s.\n", move, (move == 1) ? "" : "s");
  return move;
}

int playerTurn(int remain) {
  int move;
  do {
    printf("Pick up 1-4 stick(s): ");
    scanf("%d", &move);
  } while (move < 1 || move > 4 || move > remain);
  printf("Player picked up %d stick%s.\n", move, (move == 1) ? "" : "s");
  return move;
}

void win(int player) {
  printf("Player %d loses and is a Loser.\n", player);
  printf("The game is over. Goodbye!\n");
}