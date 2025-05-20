//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define PED_REQUEST 3
#define PED_REQUEST_TIMEOUT 4
#define MAX_PED_REQUEST_TIME 5

int state = RED;
int ped_request_state = PED_REQUEST;
int ped_request_time = 0;

void change_state(int new_state) {
    state = new_state;
    printf("State changed to %d\n", state);
}

void ped_request() {
    printf("Pedestrian request received\n");
    ped_request_state = PED_REQUEST;
    ped_request_time = time(NULL);
}

void check_ped_request() {
    if (ped_request_state == PED_REQUEST) {
        ped_request_time++;
        if (ped_request_time - ped_request_time % MAX_PED_REQUEST_TIME == 0) {
            change_state(YELLOW);
            printf("State changed to %d\n", state);
        } else if (ped_request_time > MAX_PED_REQUEST_TIME) {
            change_state(GREEN);
            printf("State changed to %d\n", state);
        }
    } else if (ped_request_state == PED_REQUEST_TIMEOUT) {
        ped_request_time++;
        if (ped_request_time > MAX_PED_REQUEST_TIME + 10) {
            change_state(GREEN);
            printf("State changed to %d\n", state);
        }
    }
}

int main() {
    srand(time(NULL));
    change_state(RED);
    int r = rand() % 3;
    if (r == 0) {
        ped_request();
    }
    while (1) {
        check_ped_request();
        sleep(1);
    }
    return 0;
}