//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

int ns_road_state = GREEN;
int ew_road_state = RED;

int ns_green_time = 10;
int ns_yellow_time = 3;
int ns_red_time = 8;

int ew_green_time = 7;
int ew_yellow_time = 2;
int ew_red_time = 9;

int ns_green_timer = 0;
int ns_yellow_timer = 0;
int ns_red_timer = 0;

int ew_green_timer = 0;
int ew_yellow_timer = 0;
int ew_red_timer = 0;

void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {};
}

void print_traffic_lights() {
    printf("\nRoad 1 - North/South Light: ");
    if (ns_road_state == GREEN) printf("GREEN\n");
    else if (ns_road_state == YELLOW) printf("YELLOW\n");
    else printf("RED\n");

    printf("Road 1 - East/West Light: ");
    if (ew_road_state == GREEN) printf("GREEN\n");
    else if (ew_road_state == YELLOW) printf("YELLOW\n");
    else printf("RED\n");

    printf("Road 2 - North/South Light: ");
    if (ns_road_state == RED) printf("GREEN\n");
    else if (ns_road_state == YELLOW) printf("YELLOW\n");
    else printf("RED\n");

    printf("Road 2 - East/West Light: ");
    if (ew_road_state == RED) printf("GREEN\n");
    else if (ew_road_state == YELLOW) printf("YELLOW\n");
    else printf("RED\n");

    printf("\n");

    printf("Road 1 - North/South Time Remaining: %d seconds\n", ns_green_time - ns_green_timer);
    printf("Road 1 - East/West Time Remaining: %d seconds\n", ew_red_time - ew_red_timer);
    printf("Road 2 - North/South Time Remaining: %d seconds\n", ns_red_time - ns_red_timer);
    printf("Road 2 - East/West Time Remaining: %d seconds\n", ew_green_time - ew_green_timer);

    printf("\n");
}

int main() {
    while (1) {
        print_traffic_lights();

        if (ns_road_state == GREEN) {
            ns_green_timer++;
            if (ns_green_timer >= ns_green_time) {
                ns_road_state = YELLOW;
                ns_green_timer = 0;
            }
        } else if (ns_road_state == YELLOW) {
            ns_yellow_timer++;
            if (ns_yellow_timer >= ns_yellow_time) {
                ns_road_state = RED;
                ns_yellow_timer = 0;
            }
        } else if (ns_road_state == RED) {
            ns_red_timer++;
            if (ns_red_timer >= ns_red_time) {
                ns_road_state = GREEN;
                ns_red_timer = 0;
            }
        }

        if (ew_road_state == GREEN) {
            ew_green_timer++;
            if (ew_green_timer >= ew_green_time) {
                ew_road_state = YELLOW;
                ew_green_timer = 0;
            }
        } else if (ew_road_state == YELLOW) {
            ew_yellow_timer++;
            if (ew_yellow_timer >= ew_yellow_time) {
                ew_road_state = RED;
                ew_yellow_timer = 0;
            }
        } else if (ew_road_state == RED) {
            ew_red_timer++;
            if (ew_red_timer >= ew_red_time) {
                ew_road_state = GREEN;
                ew_red_timer = 0;
            }
        }

        wait(1);
    }

    return 0;
}