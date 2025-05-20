//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

// a 16-bit Mersenne twister PRNG
uint32_t rng_internal_state[624];
uint32_t rng_index;

// generate a random number from 0 to 2^32-1
uint32_t rng_rand() {
    uint32_t y;
    if (rng_index >= 624) {
        rng_index = 0;
        for (size_t i = 0; i < 623; i++) {
            y = (rng_internal_state[i] & 0x80000000) | (rng_internal_state[i+1] & 0x7fffffff);
            rng_internal_state[i] = rng_internal_state[i+397] ^ (y >> 1);
            if (y % 2) {
                rng_internal_state[i] ^= 0x9908b0df;
            }
        }
        for (size_t i = 623; i < 624; i++) {
            y = (rng_internal_state[i] & 0x80000000) | (rng_internal_state[0] & 0x7fffffff);
            rng_internal_state[i] = rng_internal_state[i-227] ^ (y >> 1);
            if (y % 2) {
                rng_internal_state[i] ^= 0x9908b0df;
            }
        }
    }
    y = rng_internal_state[rng_index++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);
    return y;
}

// initialize the PRNG with a seed
void rng_seed(uint32_t seed) {
    rng_internal_state[0] = seed;
    for (size_t i = 1; i < 624; i++) {
        rng_internal_state[i] = (1812433253 * (rng_internal_state[i-1] ^ (rng_internal_state[i-1] >> 30)) + i);
    }
    rng_index = 624;
}

// roll a dice with the specified number of sides
uint32_t rng_roll_dice(uint32_t sides) {
    return (rng_rand() % sides) + 1;
}

int main(int argc, char** argv) {
    // seed the PRNG with the current time
    rng_seed(time(NULL));

    // roll a 6-sided dice 10 times
    for (size_t i = 0; i < 10; i++) {
        printf("rolled a %d\n", rng_roll_dice(6));
    }

    return 0;
}