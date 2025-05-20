//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGS 100
#define MAX_BAGGAGE_HANDLERS 10

typedef struct {
    int bag_id;
    int destination_code;
    int handler_id;
} Bag;

int main() {
    srand(time(0));
    int num_bags = rand() % MAX_BAGS + 1;
    int num_handlers = rand() % MAX_BAGGAGE_HANDLERS + 1;
    Bag bags[num_bags];
    int handler_ids[num_handlers];
    int i, j;

    for (i = 0; i < num_bags; i++) {
        bags[i].bag_id = rand() % MAX_BAGS + 1;
        bags[i].destination_code = rand() % MAX_BAGS + 1;
        bags[i].handler_id = -1;
    }

    for (i = 0; i < num_handlers; i++) {
        handler_ids[i] = rand() % MAX_BAGGAGE_HANDLERS + 1;
    }

    int num_bags_with_handler = 0;
    int num_bags_with_multiple_handlers = 0;
    int num_bags_with_no_handler = 0;

    for (i = 0; i < num_bags; i++) {
        if (handler_ids[rand() % num_handlers]!= -1) {
            bags[i].handler_id = handler_ids[rand() % num_handlers];
            num_bags_with_handler++;
        } else {
            bags[i].handler_id = -1;
            num_bags_with_no_handler++;
        }

        if (bags[i].handler_id!= -1) {
            if (bags[i].handler_id!= bags[j].handler_id && j!= -1) {
                num_bags_with_multiple_handlers++;
            }
        }
    }

    printf("Number of bags with a handler: %d\n", num_bags_with_handler);
    printf("Number of bags with multiple handlers: %d\n", num_bags_with_multiple_handlers);
    printf("Number of bags with no handler: %d\n", num_bags_with_no_handler);

    return 0;
}