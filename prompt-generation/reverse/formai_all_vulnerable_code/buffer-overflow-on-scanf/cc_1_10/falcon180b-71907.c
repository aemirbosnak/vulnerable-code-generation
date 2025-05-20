//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_NUM_PLAYERS 10
#define MAX_NUM_PRIMES 100

typedef struct {
    int prime;
    int player_num;
} prime_t;

int main() {
    int num_players, num_primes = 0;
    int primes[MAX_NUM_PRIMES];
    char input[MAX_NUM_PRIMES];
    prime_t primes_found[MAX_NUM_PRIMES];
    int i, j, player_num;
    srand(time(NULL));

    // get number of players
    printf("Enter the number of players (up to %d): ", MAX_NUM_PLAYERS);
    scanf("%d", &num_players);

    // generate primes
    for (i = 0; i < MAX_NUM_PRIMES && num_primes < num_players; i++) {
        while (!isPrime(i)) {
            i++;
        }
        primes[num_primes++] = i;
    }

    // shuffle primes
    for (i = 0; i < num_primes; i++) {
        j = rand() % num_primes;
        prime_t temp = primes_found[i];
        primes_found[i] = primes_found[j];
        primes_found[j] = temp;
    }

    // assign primes to players
    for (i = 0; i < num_players; i++) {
        printf("Player %d, enter your name: ", i + 1);
        scanf("%s", input);
        printf("Player %s, your prime number is: %d\n", input, primes_found[i].prime);
    }

    // check if players entered correct primes
    for (i = 0; i < num_players; i++) {
        printf("Player %d, enter your prime number: ", i + 1);
        scanf("%d", &player_num);
        if (player_num == primes_found[i].prime) {
            printf("Player %s wins!\n", input);
        } else {
            printf("Player %s loses.\n", input);
        }
    }

    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}