//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the game board
char board[9][9];

// Declare the player's position
int playerX, playerY;

// Declare the enemy's position
int enemyX, enemyY;

// Declare the score
int score;

// Initialize the game board
void initBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = '.';
    }
  }
}

// Draw the game board
void drawBoard() {
  printf("\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Place the player on the game board
void placePlayer() {
  playerX = rand() % 9;
  playerY = rand() % 9;
  board[playerX][playerY] = 'P';
}

// Place the enemy on the game board
void placeEnemy() {
  enemyX = rand() % 9;
  enemyY = rand() % 9;
  board[enemyX][enemyY] = 'E';
}

// Move the player
void movePlayer(int dx, int dy) {
  if (playerX + dx >= 0 && playerX + dx < 9 && playerY + dy >= 0 && playerY + dy < 9) {
    board[playerX][playerY] = '.';
    playerX += dx;
    playerY += dy;
    board[playerX][playerY] = 'P';
  }
}

// Move the enemy
void moveEnemy() {
  int dx = playerX - enemyX;
  int dy = playerY - enemyY;
  if (abs(dx) > abs(dy)) {
    if (dx > 0) {
      enemyX++;
    } else {
      enemyX--;
    }
  } else {
    if (dy > 0) {
      enemyY++;
    } else {
      enemyY--;
    }
  }
  board[enemyX][enemyY] = 'E';
}

// Check if the player has won
int hasPlayerWon() {
  return enemyX == playerX && enemyY == playerY;
}

// Check if the player has lost
int hasPlayerLost() {
  return playerX == enemyX && playerY == enemyY;
}

// Main game loop
int main() {
  srand(time(NULL));
  initBoard();
  placePlayer();
  placeEnemy();
  drawBoard();

  while (!hasPlayerWon() && !hasPlayerLost()) {
    // Get the player's input
    int dx, dy;
    printf("Enter your move (w, a, s, d): ");
    scanf(" %c", &dx);
    switch (dx) {
      case 'w':
        dy = -1;
        break;
      case 'a':
        dy = 0;
        dx = -1;
        break;
      case 's':
        dy = 1;
        break;
      case 'd':
        dy = 0;
        dx = 1;
        break;
    }

    // Move the player
    movePlayer(dx, dy);

    // Move the enemy
    moveEnemy();

    // Draw the game board
    drawBoard();
  }

  if (hasPlayerWon()) {
    printf("You win!\n");
  } else if (hasPlayerLost()) {
    printf("You lose!\n");
  }

  return 0;
}