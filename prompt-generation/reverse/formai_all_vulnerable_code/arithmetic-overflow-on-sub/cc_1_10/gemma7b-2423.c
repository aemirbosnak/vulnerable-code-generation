//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MAX_SPEED 10

typedef struct Car {
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 60) {
        for (Car* current = head; current; current = current->next) {
            current->position++;
            if (current->position >= NUM_LANES * MAX_SPEED) {
                current->position = 0;
            }

            switch (current->lane) {
                case 0:
                    current->speed = rand() % MAX_SPEED + 1;
                    break;
                case 1:
                    current->speed = rand() % MAX_SPEED + 2;
                    break;
                case 2:
                    current->speed = rand() % MAX_SPEED + 3;
                    break;
            }

            sleep(current->speed);
        }
    }
}

int main() {
    Car* head = malloc(sizeof(Car));
    head->lane = 0;
    head->speed = 5;
    head->position = 0;
    head->next = NULL;

    simulateTrafficFlow(head);

    return 0;
}