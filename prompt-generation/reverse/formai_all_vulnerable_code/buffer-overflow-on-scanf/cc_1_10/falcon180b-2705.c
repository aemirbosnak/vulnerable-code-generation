//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT 1000
#define MAX_DESCRIPTION 100

enum event_type {
    EVENT_TYPE_INVENT,
    EVENT_TYPE_DISCOVER,
    EVENT_TYPE_BIRTH,
    EVENT_TYPE_DEATH,
    EVENT_TYPE_BATTLE,
    EVENT_TYPE_RULER,
    EVENT_TYPE_CONSTRUCTION,
    EVENT_TYPE_DESTRUCTION,
    EVENT_TYPE_OTHER
};

struct event {
    enum event_type type;
    int year;
    char description[MAX_DESCRIPTION];
};

int main() {
    struct event events[MAX_EVENT];
    int num_events = 0;

    srand(time(NULL));
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_INVENT,
       .year = 1440,
       .description = "Johannes Gutenberg invents the printing press"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_DISCOVER,
       .year = 1492,
       .description = "Christopher Columbus discovers America"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_BIRTH,
       .year = 1729,
       .description = "Mathematician Leonhard Euler is born"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_DEATH,
       .year = 1827,
       .description = "Composer Ludwig van Beethoven dies"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_BATTLE,
       .year = 1865,
       .description = "The American Civil War ends with the surrender of Confederate General Robert E. Lee"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_RULER,
       .year = 1917,
       .description = "Tsar Nicholas II of Russia abdicates"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_CONSTRUCTION,
       .year = 1937,
       .description = "The Golden Gate Bridge is completed"
    };
    events[num_events++] = (struct event) {
       .type = EVENT_TYPE_DESTRUCTION,
       .year = 2001,
       .description = "The World Trade Center is destroyed in a terrorist attack"
    };

    int target_year;
    printf("Enter the year to travel to: ");
    scanf("%d", &target_year);

    for (int i = 0; i < num_events; i++) {
        if (events[i].year == target_year) {
            printf("%s\n", events[i].description);
        }
    }

    return 0;
}