//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 100

void surrealist_fitness_tracker(int n) {
    int i;
    char buffer[MAX_LEN];
    struct timespec start, end;

    printf("Welcome to the Surrealist Fitness Tracker!\n");
    printf("Please enter the number of exercises you would like to track:\n");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer value for the number of exercises.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter exercise #%d:\n", i + 1);
        scanf("%s", buffer);

        if (strlen(buffer) > MAX_LEN) {
            printf("Please enter a valid exercise name with a maximum of %d characters.\n", MAX_LEN);
            continue;
        }

        clock_gettime(CLOCK_REALTIME, &start);

        printf("Begin exercise %s!\n", buffer);

        sleep(5); // Replace with your desired exercise duration

        clock_gettime(CLOCK_REALTIME, &end);

        float time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

        printf("Exercise %s completed in %.2f seconds.\n", buffer, time_elapsed);
    }

    printf("Thank you for using the Surrealist Fitness Tracker!\n");
}

int main() {
    int n;
    printf("Enter the number of exercises to track: ");
    scanf("%d", &n);

    surrealist_fitness_tracker(n);

    return 0;
}