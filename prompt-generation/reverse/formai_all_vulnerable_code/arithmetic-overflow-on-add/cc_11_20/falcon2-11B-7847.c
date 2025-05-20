//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed random number generator with current time

    int floors = 5; // number of floors
    int current_floor = 0; // current floor of elevator

    int calls[floors]; // array to store call events for each floor
    int call_index = 0; // index for calls array

    int up_calls[floors]; // array to store up call events for each floor
    int up_call_index = 0; // index for up_calls array

    int down_calls[floors]; // array to store down call events for each floor
    int down_call_index = 0; // index for down_calls array

    int moves[floors]; // array to store elevator moves for each floor
    int move_index = 0; // index for moves array

    int elevator_direction = 1; // 1 = up, -1 = down

    int current_time = 0; // current time in seconds

    int time_interval = 5; // time interval in seconds between each event

    int i, j, k;

    while (1) {
        // get current time
        current_time = time(0);

        int random_floor = rand() % floors; // random floor number

        if (random_floor == current_floor) { // elevator is at the same floor
            calls[random_floor] += 1; // increment call count for this floor
        } else {
            calls[current_floor] -= 1; // decrement call count for current floor
            calls[random_floor] += 1; // increment call count for new floor
            current_floor = random_floor; // set new current floor
        }

        if (current_floor == 0) { // elevator is at bottom floor
            if (rand() % 2 == 0) { // call for up
                up_calls[current_floor] += 1;
            } else { // call for down
                down_calls[current_floor] += 1;
            }
        } else if (current_floor == floors - 1) { // elevator is at top floor
            if (rand() % 2 == 0) { // call for down
                down_calls[current_floor] += 1;
            } else { // call for up
                up_calls[current_floor] += 1;
            }
        } else {
            if (rand() % 2 == 0) { // call for down
                down_calls[current_floor] += 1;
            } else { // call for up
                up_calls[current_floor] += 1;
            }
        }

        if (current_time > time_interval) {
            int max_calls = 0;
            int max_floor = 0;
            int max_floor_call_count = 0;

            for (i = 0; i < floors; i++) {
                if (calls[i] > max_calls) {
                    max_calls = calls[i];
                    max_floor = i;
                    max_floor_call_count = calls[i];
                }
            }

            if (max_floor_call_count > 0) {
                int move_direction = 1; // 1 = up, -1 = down
                if (max_floor == 0) { // call for up
                    move_direction = 1;
                } else if (max_floor == floors - 1) { // call for down
                    move_direction = -1;
                } else { // call for move to floor 0 or floor 4
                    move_direction = -1;
                }

                for (i = 0; i < floors; i++) {
                    moves[i] = 0;
                }

                moves[max_floor] = move_direction;
                moves[current_floor] = move_direction * elevator_direction;

                current_floor = max_floor;
                elevator_direction = move_direction;
            }

            current_time = 0;
        }

        printf("Time: %d\n", current_time);
        printf("Current floor: %d\n", current_floor);
        printf("Up calls: %d\n", up_calls[current_floor]);
        printf("Down calls: %d\n", down_calls[current_floor]);
        printf("Moves: %d\n", moves[current_floor]);

        fflush(stdout);
    }

    return 0;
}