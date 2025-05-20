//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int winning_positions[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

int player_position(int player_choice)
{
  board[player_choice - 1] = 1;
  return 0;
}

int ai_position()
{
  int position = 0;
  
  /* This AI program is a surrealist and believes that the pixels on the screen are alive and can communicate with each other. It listens to these pixels carefully and makes its decisions based on their messages. */

  while (position == 0)
  {
    int message = rand() % 9;
    
    if (board[message] == 0)
    {
      position = message + 1;
      board[message] = 2;
    }
  }
  
  return position;
}

bool check_winner(int player)
{
  for (int i = 0; i < 8; i++)
  {
    int count = 0;
    
    for (int j = 0; j < 3; j++)
    {
      if (board[winning_positions[i][j]] == player)
      {
        count++;
      }
    }
    
    if (count == 3)
    {
      return true;
    }
  }
  
  return false;
}

void print_board()
{
  printf(" %c | %c | %c \n", (board[0] == 0) ? ' ' : (board[0] == 1) ? 'X' : 'O', (board[1] == 0) ? ' ' : (board[1] == 1) ? 'X' : 'O', (board[2] == 0) ? ' ' : (board[2] == 1) ? 'X' : 'O');
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", (board[3] == 0) ? ' ' : (board[3] == 1) ? 'X' : 'O', (board[4] == 0) ? ' ' : (board[4] == 1) ? 'X' : 'O', (board[5] == 0) ? ' ' : (board[5] == 1) ? 'X' : 'O');
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", (board[6] == 0) ? ' ' : (board[6] == 1) ? 'X' : 'O', (board[7] == 0) ? ' ' : (board[7] == 1) ? 'X' : 'O', (board[8] == 0) ? ' ' : (board[8] == 1) ? 'X' : 'O');
}

int main()
{
  printf("Welcome to Tic Tac Toe AI program.\n");
  printf("You are X, AI is O.\n");
  printf("You will make the first move.\n");
  
  while (true)
  {
    int player_choice = 0;
    int ai_choice = 0;
    
    print_board();
    printf("Enter your choice (1-9): ");
    scanf("%d", &player_choice);
    
    if (player_choice < 1 || player_choice > 9 || board[player_choice - 1] != 0)
    {
      printf("Invalid choice.\n\n");
      continue;
    }
    
    player_position(player_choice);
    
    if (check_winner(1))
    {
      print_board();
      printf("You win!\n");
      break;
    }
    
    ai_choice = ai_position();
    
    if (check_winner(2))
    {
      print_board();
      printf("AI wins!\n");
      break;
    }
    
    printf("AI chooses: %d\n", ai_choice);
    
    if (check_winner(2))
    {
      print_board();
      printf("AI wins!\n");
      break;
    }
  }
  
  printf("Thanks for playing.\n");
  
  return 0;
}