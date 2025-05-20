//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SZ 4
#define LMT 3

void bleep() {
    for (int i = 0; i < 3; i++) {
        printf("\a");
        sleep(1);
    }
}

void skewer(int *x, int n) {
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 10;
    }
}

void flash(int *x, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
        fflush(stdout);
        sleep(1);
        printf("\r \r");
        fflush(stdout);
        sleep(1);
    }
}

int probe(int *x, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &s) != 1 || s != x[i]) {
            while(getchar() != '\n');
            return 0;
        }
    }
    return 1;
}

void summon(int *x) {
    printf("Number Sequence: ");
    flash(x, LMT);
}

void scribe(int score, int rounds) {
    printf("You scored %d out of %d!\n", score, rounds);
}

int main() {
    srand(time(0));  // Time as seed
    int tempest[SZ] = {0};
    int tally = 0;

    for (int r = 0; r < 5; r++) {
        printf("Round %d:\n", r + 1);
        skewer(tempest, LMT);
        summon(tempest);
        bleep();
        printf("Recall the sequence: ");
        if (probe(tempest, LMT)) {
            printf("Correct!\n");
            tally++;
        } else {
            printf("Wrong!\n");
        }
    }
    scribe(tally, 5);
    return 0;
}