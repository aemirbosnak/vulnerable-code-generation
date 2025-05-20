//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

// Network settings
#define MAX_PORT 65535
#define MAX_THREADS 10

// Player data
typedef struct {
  int id;
  int score;
  char* name;
} Player;

// Scan settings
typedef struct {
  char* target;
  int start_port;
  int end_port;
} ScanSettings;

// List of players
Player players[MAX_THREADS];

// Scan settings
ScanSettings settings;

// Mutex for shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function for each thread
void* scan_thread(void* arg) {
  // Get player ID
  int id = *(int*)arg;

  // Get scan settings
  ScanSettings* settings = &settings;

  // Lock mutex
  pthread_mutex_lock(&mutex);

  // Get start and end port for this thread
  int start_port = settings->start_port + id * (settings->end_port - settings->start_port) / MAX_THREADS;
  int end_port = settings->start_port + (id + 1) * (settings->end_port - settings->start_port) / MAX_THREADS;

  // Unlock mutex
  pthread_mutex_unlock(&mutex);

  // Scan ports
  for (int port = start_port; port <= end_port; port++) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set socket options
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(settings->target);

    // Connect to port
    int ret = connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    // Check if port is open
    if (ret == 0) {
      // Lock mutex
      pthread_mutex_lock(&mutex);

      // Increment player score
      players[id].score++;

      // Unlock mutex
      pthread_mutex_unlock(&mutex);
    }

    // Close socket
    close(sock);
  }

  // Return NULL
  return NULL;
}

// Main function
int main() {
  // Get input
  printf("Enter target IP address: ");
  scanf("%s", settings.target);
  printf("Enter start port: ");
  scanf("%d", &settings.start_port);
  printf("Enter end port: ");
  scanf("%d", &settings.end_port);

  // Create threads
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    // Create player
    players[i].id = i;
    players[i].score = 0;
    players[i].name = NULL;

    // Create thread
    pthread_create(&threads[i], NULL, scan_thread, &i);
  }

  // Join threads
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print results
  printf("Scan complete!\n");
  for (int i = 0; i < MAX_THREADS; i++) {
    printf("Player %d: %d points\n", players[i].id, players[i].score);
  }

  // Return 0
  return 0;
}