//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double time_taken;

    int heartSize = 100;
    int hugsPerSecond = 0;
    int kissesPerSecond = 0;

    printf("My heart has a size of %d units.\n", heartSize);
    printf("Press enter to begin the hug and kiss benchmarking...\n");
    getchar();

    printf("Hugging...\n");
    start = clock();
    for (int i = 0; i < heartSize; i++) {
        hugsPerSecond++;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Benchmark complete! %d hugs per second!\n", (int) (hugsPerSecond / time_taken));

    printf("Press enter to continue to the kissing benchmark...\n");
    getchar();

    hugsPerSecond = 0;

    printf("Kissing...\n");
    start = clock();
    for (int i = 0; i < heartSize; i++) {
        kissesPerSecond++;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Benchmark complete! %d kisses per second!\n", (int) (kissesPerSecond / time_taken));

    printf("Press enter to see which one won...\n");
    getchar();

    if (hugsPerSecond > kissesPerSecond) {
        printf("Hugs win! My heart beats for hugs!\n");
    } else if (hugsPerSecond < kissesPerSecond) {
        printf("Kisses win! My heart beats for kisses!\n");
    } else {
        printf("It's a tie! My heart beats for both hugs and kisses equally!\n");
    }

    return 0;
}