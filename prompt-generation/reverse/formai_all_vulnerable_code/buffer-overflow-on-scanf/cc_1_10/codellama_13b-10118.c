//Code Llama-13B DATASET v1.0 Category: Pac-Man Game Clone ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 15

typedef struct {
  int x;
  int y;
  int score;
  int lives;
} Player;

typedef struct {
  int x;
  int y;
  int size;
} Pellet;

typedef struct {
  int x;
  int y;
  int size;
} Ghost;

void init_player(Player* player) {
  player->x = WIDTH / 2;
  player->y = HEIGHT / 2;
  player->score = 0;
  player->lives = 3;
}

void init_pellet(Pellet* pellet, int x, int y) {
  pellet->x = x;
  pellet->y = y;
  pellet->size = 2;
}

void init_ghost(Ghost* ghost, int x, int y) {
  ghost->x = x;
  ghost->y = y;
  ghost->size = 3;
}

void move_player(Player* player, int dx, int dy) {
  player->x += dx;
  player->y += dy;
}

void move_pellet(Pellet* pellet, int dx, int dy) {
  pellet->x += dx;
  pellet->y += dy;
}

void move_ghost(Ghost* ghost, int dx, int dy) {
  ghost->x += dx;
  ghost->y += dy;
}

void update_player(Player* player, Pellet* pellet, Ghost* ghost) {
  if (player->x == pellet->x && player->y == pellet->y) {
    player->score += pellet->size;
    init_pellet(pellet, rand() % WIDTH, rand() % HEIGHT);
  }
  if (player->x == ghost->x && player->y == ghost->y) {
    player->lives--;
    if (player->lives <= 0) {
      printf("GAME OVER\n");
      exit(0);
    }
    init_ghost(ghost, rand() % WIDTH, rand() % HEIGHT);
  }
}

void update_pellet(Pellet* pellet, Player* player) {
  if (pellet->x == player->x && pellet->y == player->y) {
    player->score += pellet->size;
    init_pellet(pellet, rand() % WIDTH, rand() % HEIGHT);
  }
}

void update_ghost(Ghost* ghost, Player* player) {
  if (ghost->x == player->x && ghost->y == player->y) {
    player->lives--;
    if (player->lives <= 0) {
      printf("GAME OVER\n");
      exit(0);
    }
    init_ghost(ghost, rand() % WIDTH, rand() % HEIGHT);
  }
}

void draw_player(Player* player) {
  printf("X: %d, Y: %d, Score: %d, Lives: %d\n", player->x, player->y, player->score, player->lives);
}

void draw_pellet(Pellet* pellet) {
  printf("Pellet at X: %d, Y: %d, Size: %d\n", pellet->x, pellet->y, pellet->size);
}

void draw_ghost(Ghost* ghost) {
  printf("Ghost at X: %d, Y: %d, Size: %d\n", ghost->x, ghost->y, ghost->size);
}

int main() {
  Player player;
  Pellet pellet;
  Ghost ghost;
  int dx, dy;

  srand(time(NULL));

  init_player(&player);
  init_pellet(&pellet, rand() % WIDTH, rand() % HEIGHT);
  init_ghost(&ghost, rand() % WIDTH, rand() % HEIGHT);

  while (1) {
    draw_player(&player);
    draw_pellet(&pellet);
    draw_ghost(&ghost);

    printf("Direction (up, down, left, right): ");
    scanf("%d %d", &dx, &dy);
    move_player(&player, dx, dy);
    update_player(&player, &pellet, &ghost);

    printf("Direction (up, down, left, right): ");
    scanf("%d %d", &dx, &dy);
    move_pellet(&pellet, dx, dy);
    update_pellet(&pellet, &player);

    printf("Direction (up, down, left, right): ");
    scanf("%d %d", &dx, &dy);
    move_ghost(&ghost, dx, dy);
    update_ghost(&ghost, &player);
  }

  return 0;
}