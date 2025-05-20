//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define QUEUE_SIZE 10

// Player data structure
typedef struct {
  char name[20];
  int score;
} Player;

// Queue data structure
typedef struct {
  Player players[QUEUE_SIZE];
  int head;
  int tail;
  pthread_mutex_t lock;
  pthread_cond_t not_empty;
  pthread_cond_t not_full;
} Queue;

// Initialize the queue
void queue_init(Queue *q) {
  q->head = 0;
  q->tail = 0;
  pthread_mutex_init(&q->lock, NULL);
  pthread_cond_init(&q->not_empty, NULL);
  pthread_cond_init(&q->not_full, NULL);
}

// Enqueue a player
void queue_enqueue(Queue *q, Player player) {
  pthread_mutex_lock(&q->lock);
  while ((q->tail + 1) % QUEUE_SIZE == q->head) {
    pthread_cond_wait(&q->not_full, &q->lock);
  }
  q->players[q->tail] = player;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
  pthread_cond_signal(&q->not_empty);
  pthread_mutex_unlock(&q->lock);
}

// Dequeue a player
Player queue_dequeue(Queue *q) {
  pthread_mutex_lock(&q->lock);
  while (q->head == q->tail) {
    pthread_cond_wait(&q->not_empty, &q->lock);
  }
  Player player = q->players[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  pthread_cond_signal(&q->not_full);
  pthread_mutex_unlock(&q->lock);
  return player;
}

// Thread function for each player
void *player_thread(void *arg) {
  Queue *q = (Queue *)arg;
  Player player;
  while (1) {
    // Get the player's input
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.score = rand() % 100;

    // Enqueue the player
    queue_enqueue(q, player);

    // Wait for the player's turn
    pthread_mutex_lock(&q->lock);
    while (strcmp(q->players[q->head].name, player.name) != 0) {
      pthread_cond_wait(&q->not_empty, &q->lock);
    }
    pthread_mutex_unlock(&q->lock);

    // Play the game
    printf("It's your turn, %s! Your score is %d.\n", player.name, player.score);
    // ...

    // Dequeue the player
    queue_dequeue(q);
  }
}

int main() {
  // Create the queue
  Queue q;
  queue_init(&q);

  // Create the player threads
  pthread_t players[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_create(&players[i], NULL, player_thread, &q);
  }

  // Wait for the player threads to finish
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_join(players[i], NULL);
  }

  return 0;
}