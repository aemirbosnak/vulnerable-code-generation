//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: surprised
/* OH MY GOSH, THIS PROGRAM IS GOING TO BE SO COOL! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    int i, j, k, l;
    char str[MAX_LENGTH];
    int num[MAX_LENGTH];
    float score = 0;

    printf("WHOA, WELCOME TO THE MOST EPIC PROGRAM EVER! 😱\n");

    /* LET'S GET STARTED! 💥 */
    for (i = 0; i < MAX_LENGTH; i++) {
        printf("ENTER A NUMBER BETWEEN %d AND %d (INCLUSIVE): ", MIN_VALUE, MAX_VALUE);
        scanf("%d", &num[i]);

        if (num[i] > MAX_VALUE || num[i] < MIN_VALUE) {
            printf("WHOA, THAT'S NOT A VALID NUMBER! 😱\n");
            continue;
        }

        score += num[i];
        printf("WOW, THAT'S A PRETTY GOOD SCORE SO FAR! 😃\n");
    }

    printf("WHOA, LOOK AT ALL THESE AMAZING NUMBERS! 🤯\n");
    for (i = 0; i < MAX_LENGTH; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    /* LET'S SEE HOW LONG THIS PROGRAM TOOK TO RUN... 🕰️ */
    clock_t start = clock();
    for (i = 0; i < 100000; i++) {
        score = 0;
        for (j = 0; j < MAX_LENGTH; j++) {
            score += num[j];
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("WHOA, THIS PROGRAM TOOK %f SECONDS TO RUN! 😲\n", time_taken);

    return 0;
}