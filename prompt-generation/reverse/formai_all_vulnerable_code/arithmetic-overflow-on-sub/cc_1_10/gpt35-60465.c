//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SERVERS 10

struct Server {
  char* name;
  int status;
  int last_checked;
};

struct Server servers[SERVERS];

int main() {

  // Initialize servers
  servers[0].name = "BlackIce Mainframe";
  servers[1].name = "The Grid";
  servers[2].name = "StateCops Database";
  servers[3].name = "Cyberbrain Biosphere";
  servers[4].name = "BTL Distribution Network";
  servers[5].name = "Quantum Entanglement Array";
  servers[6].name = "Diamond Matrix Storage";
  servers[7].name = "Neon City Server Farm";
  servers[8].name = "Watchdog Security System";
  servers[9].name = "Netwatch Central Hub";

  // Set initial server statuses and timestamps
  srand(time(NULL));
  for (int i = 0; i < SERVERS; i++) {
    servers[i].status = rand() % 2;
    servers[i].last_checked = time(NULL);
  }

  // Main loop
  while (1) {

    // Check server statuses and print status updates
    for (int i = 0; i < SERVERS; i++) {
      int current_time = time(NULL);
      int time_since_last_check = current_time - servers[i].last_checked;
      if (servers[i].status) {
        if (time_since_last_check > 10) {
          servers[i].status = 0;
          printf("%s is offline!\n", servers[i].name);
        }
      } else {
        if (time_since_last_check > 5) {
          servers[i].status = 1;
          printf("%s is online.\n", servers[i].name);
        }
      }
      servers[i].last_checked = current_time;
    }
  }

  return 0;
}