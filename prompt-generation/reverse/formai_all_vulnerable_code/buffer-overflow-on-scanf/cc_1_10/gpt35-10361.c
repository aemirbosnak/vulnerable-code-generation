//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXCARS 25
#define EMPTY -1
#define ARRIVE 1
#define DEPART 0

int road[20], timeclock, eventflag, cars_on_rd, tot_cars, elapsed_time=0;
float timer;

void intro_screen() {
    printf("\nTraffic Flow Simulation\n");
    printf("----------------------\n\n");
}

void init_road() {
    for(int i=0; i<20; ++i)
        road[i] = EMPTY;
    cars_on_rd = 0;
    tot_cars = 0;
}

void display_road() {
    printf("Road:\n");
    printf("=====\n");
    for(int i=0; i<20; ++i) {
        printf("|");
        if(road[i] == EMPTY)
            printf("_");
        else
            printf("%d", road[i]);
    }
    printf("|\n\n");
}

void add_car() {
    int carpos;
    if(cars_on_rd < MAXCARS) {
        do {
            carpos = rand() % 20;
        } while(road[carpos] != EMPTY);
        road[carpos] = 0;
        ++cars_on_rd;
        ++tot_cars;
    }
}

void remove_car(int pos) {
    road[pos] = EMPTY;
    --cars_on_rd;
}

void drive() {
    for(int i=0; i<20; ++i)
        if(road[i] != EMPTY)
            if(i != 19 && road[i+1] == EMPTY) {
                road[i+1] = road[i];
                remove_car(i);
            }
    display_road();
}

void update_clock() {
    elapsed_time++;
    timer = (float)elapsed_time/timeclock;
}

void generate_event() {
    float temp;
    temp = (float)rand()/(float)RAND_MAX;

    if(temp > timer)
        eventflag = DEPART;
    else
        eventflag = ARRIVE;
}

void add_or_remove_car() {
    generate_event();

    if(eventflag == ARRIVE)
        add_car();
    else
        if(cars_on_rd > 0) {
            int co_ordinates[MAXCARS], j=0;
            for(int i=0; i<20; ++i)
                if(road[i] != EMPTY) {
                    co_ordinates[j] = i;
                    j++;
                }
            remove_car(co_ordinates[rand()%j]);
        }
}

int main() {
    srand((unsigned)time(NULL));
    intro_screen();

    printf("Enter the amount of time to simulate (in minutes): ");
    scanf("%d", &timeclock);

    init_road();
    display_road();

    while(elapsed_time < timeclock) {
        add_or_remove_car();
        drive();
        update_clock();
    }

    printf("\nTotal number of cars that reached the end of the road: %d", tot_cars);
    printf("\n\nEnd of simulation\n");

    return 0;
}