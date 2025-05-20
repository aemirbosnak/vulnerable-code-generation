//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVELS 100

typedef struct {
    time_t time;
    char *description;
} time_travel;

int main() {
    time_travel travels[MAX_TIME_TRAVELS];
    int num_travels = 0;

    while (num_travels < MAX_TIME_TRAVELS) {
        printf("Enter a time travel destination (format: YYYY-MM-DD HH:MM:SS): ");
        char input[32];
        scanf("%s", input);

        struct tm tm;
        strptime(input, "%Y-%m-%d %H:%M:%S", &tm);

        time_travel new_travel = {
           .time = mktime(&tm),
           .description = strdup(input)
        };

        if (num_travels >= MAX_TIME_TRAVELS) {
            fprintf(stderr, "Maximum number of time travels reached.\n");
        } else {
            travels[num_travels++] = new_travel;
        }
    }

    printf("\nTime Travel Itinerary:\n");
    for (int i = 0; i < num_travels; i++) {
        time_t now = time(NULL);
        time_t diff = travels[i].time - now;

        if (diff < 0) {
            printf("%s (%ld seconds ago)\n", travels[i].description, -diff);
        } else {
            printf("%s (%ld seconds from now)\n", travels[i].description, diff);
        }
    }

    for (int i = 0; i < num_travels; i++) {
        free(travels[i].description);
    }

    return 0;
}