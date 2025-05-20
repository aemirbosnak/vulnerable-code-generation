//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TABLE_SIZE 10

typedef struct {
  char name[20];
  int position;
  int score;
} Player;

typedef struct {
  int size;
  int current_player;
  Player players[MAX_PLAYERS];
} Table;

void print_table(Table *table) {
  for (int i = 0; i < table->size; i++) {
    printf("| %s (%d, %d) |", table->players[i].name, table->players[i].position, table->players[i].score);
  }
  printf("\n");
}

void roll_die(int *die) {
  *die = rand() % 6 + 1;
}

void move_player(Table *table, Player *player, int die) {
  player->position += die;
  if (player->position >= table->size) {
    player->position -= table->size;
    player->score++;
  }
}

int main() {
  srand(time(NULL));

  Table table;
  table.size = MAX_TABLE_SIZE;
  table.current_player = 0;

  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", table.players[i].name);
    table.players[i].position = 0;
    table.players[i].score = 0;
  }

  while (1) {
    int die;
    roll_die(&die);
    printf("%s rolls a %d\n", table.players[table.current_player].name, die);
    move_player(&table, &table.players[table.current_player], die);
    print_table(&table);
    if (table.players[table.current_player].score >= 3) {
      printf("%s wins!\n", table.players[table.current_player].name);
      break;
    }
    table.current_player = (table.current_player + 1) % MAX_PLAYERS;
  }

  return 0;
}