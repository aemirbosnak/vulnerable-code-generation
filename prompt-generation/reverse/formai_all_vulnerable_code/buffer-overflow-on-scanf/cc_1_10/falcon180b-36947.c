//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_EVENTS 10000
#define N_ALIENS 1000
#define N_HUMANS 1000

struct event {
    int type; // 0 = alien, 1 = human
    int result; // 0 = alien wins, 1 = human wins
};

void simulate_invasion(int n_aliens, int n_humans, int* wins) {
    struct event events[N_EVENTS];
    int i, j, k;

    for (i = 0; i < N_EVENTS; i++) {
        events[i].type = rand() % 2;
        events[i].result = rand() % 2;
    }

    for (i = 0; i < n_aliens; i++) {
        for (j = 0; j < n_humans; j++) {
            int alien_wins = 0;
            int human_wins = 0;

            for (k = 0; k < N_EVENTS; k++) {
                if (events[k].type == 0 && events[k].result == 0) {
                    alien_wins++;
                } else if (events[k].type == 1 && events[k].result == 0) {
                    human_wins++;
                }
            }

            if (alien_wins > human_wins) {
                (*wins)++;
            }
        }
    }
}

int main() {
    int n_aliens, n_humans, wins = 0;

    printf("Enter the number of aliens: ");
    scanf("%d", &n_aliens);

    printf("Enter the number of humans: ");
    scanf("%d", &n_humans);

    srand(time(NULL));
    simulate_invasion(n_aliens, n_humans, &wins);

    printf("The aliens have a %.2f%% chance of winning the invasion.\n",
           (float)wins / (n_aliens * n_humans) * 100);

    return 0;
}