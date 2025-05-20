//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quirkyDelay(int seconds) {
    printf("Hold on tight! We're waiting for %d seconds...\n", seconds);
    for (int i = seconds; i > 0; i--) {
        printf("... %d seconds left ...\n", i);
        sleep(1);
    }
}

void benchmark(int iterations, void (*func)()) {
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Commence the benchmarking madness!\n");
    printf("Get ready to roll the dice on %d iterations of fun...\n", iterations);

    start_time = clock();
    
    for (int i = 0; i < iterations; i++) {
        func();
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("The result of our shenanigans: %f seconds for %d iterations!\n", cpu_time_used, iterations);
}

void funkyFunction() {
    int magicNumber = 42;
    for (int i = 0; i < magicNumber; i++) {
        printf("Have you heard the one about the programmer who couldn’t stop writing? They just kept coding and coding...\n");
    }
}

void sillyFunction() {
    int randomness = rand() % 5;
    if (randomness == 0) {
        printf("Why did the programmer go broke? Because he used up all his cache!\n");
    } else if (randomness == 1) {
        printf("Why do programmers prefer dark mode? Because light attracts bugs!\n");
    } else if (randomness == 2) {
        printf("How many programmers does it take to change a light bulb? None, that’s a hardware problem!\n");
    } else if (randomness == 3) {
        printf("There are 10 types of people in the world: those who understand binary, and those who don’t!\n");
    } else {
        printf("To understand what recursion is, you must first understand recursion.\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int iterations = 10;

    printf("Welcome to the C Benchmarking Circus!\n");
    printf("We are about to juggle some functions like a bunch of clowns.\n");
    
    quirkyDelay(3);
    
    benchmark(iterations, funkyFunction);
    quirkyDelay(2);
    benchmark(iterations, sillyFunction);
    
    printf("And that concludes our performance, folks!\n");
    printf("Remember: you can always come back for another laugh with benchmarking!\n");
    return 0;
}