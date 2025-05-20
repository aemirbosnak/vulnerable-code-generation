//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_SLOTS 24
#define MAX_JUMP_NUM 5

typedef struct {
    int current_time;
    int current_jump;
    int next_time;
    int next_jump;
    int visited_jump;
    int total_jumps;
} TimeTraveler;

void init_time_traveler(TimeTraveler *t) {
    t->current_time = 0;
    t->current_jump = 0;
    t->next_time = 0;
    t->next_jump = 0;
    t->visited_jump = 0;
    t->total_jumps = 0;
}

void reset_time_traveler(TimeTraveler *t) {
    t->current_time = 0;
    t->current_jump = 0;
    t->next_time = 0;
    t->next_jump = 0;
    t->visited_jump = 0;
    t->total_jumps = 0;
}

void print_time_traveler(TimeTraveler t) {
    printf("Current time: %d\n", t.current_time);
    printf("Current jump: %d\n", t.current_jump);
    printf("Next time: %d\n", t.next_time);
    printf("Next jump: %d\n", t.next_jump);
    printf("Visited jump: %d\n", t.visited_jump);
    printf("Total jumps: %d\n", t.total_jumps);
}

void move_time_traveler(TimeTraveler *t, int delta_time, int delta_jump) {
    t->current_time += delta_time;
    t->current_jump += delta_jump;
    if (t->current_time >= MAX_TIME_SLOTS) {
        t->current_time -= MAX_TIME_SLOTS;
        t->next_time = t->current_time + 1;
    } else {
        t->next_time = t->current_time + 1;
    }
    if (t->current_jump >= MAX_JUMP_NUM) {
        t->current_jump -= MAX_JUMP_NUM;
        t->next_jump = t->current_jump + 1;
    } else {
        t->next_jump = t->current_jump + 1;
    }
    t->visited_jump = 1;
    t->total_jumps++;
}

int main() {
    TimeTraveler t;
    init_time_traveler(&t);

    while (1) {
        int delta_time, delta_jump;
        printf("Enter delta time and delta jump: ");
        scanf("%d %d", &delta_time, &delta_jump);
        if (delta_time == 0 && delta_jump == 0) {
            printf("Exiting program.\n");
            break;
        }
        move_time_traveler(&t, delta_time, delta_jump);
        print_time_traveler(t);
    }

    return 0;
}