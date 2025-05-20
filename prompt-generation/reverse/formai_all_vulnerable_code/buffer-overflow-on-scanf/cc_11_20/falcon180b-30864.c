//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define LIGHT_ON 1
#define LIGHT_OFF 0

int main() {
    int light_status = LIGHT_OFF;
    int motion_detected = FALSE;
    int light_timer = 0;
    int motion_timer = 0;

    printf("Welcome to the Smart Home Light Control System!\n");

    while(TRUE) {
        system("clear");
        printf("Current Light Status: %s\n", light_status == LIGHT_ON? "ON" : "OFF");
        printf("Motion Detected: %s\n", motion_detected? "YES" : "NO");
        printf("Light Timer: %d seconds\n", light_timer);
        printf("Motion Timer: %d seconds\n", motion_timer);

        printf("\nEnter your choice:\n");
        printf("1. Turn light on\n");
        printf("2. Turn light off\n");
        printf("3. Set light timer\n");
        printf("4. Set motion timer\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                light_status = LIGHT_ON;
                light_timer = 0;
                printf("Light turned on.\n");
                break;
            case 2:
                light_status = LIGHT_OFF;
                light_timer = 0;
                printf("Light turned off.\n");
                break;
            case 3:
                printf("Enter light timer value (in seconds): ");
                scanf("%d", &light_timer);
                printf("Light timer set.\n");
                break;
            case 4:
                printf("Enter motion timer value (in seconds): ");
                scanf("%d", &motion_timer);
                printf("Motion timer set.\n");
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if(light_status == LIGHT_ON && light_timer > 0) {
            light_timer--;
            if(light_timer == 0) {
                light_status = LIGHT_OFF;
                printf("Light turned off due to timer.\n");
            }
        }

        if(motion_detected && motion_timer > 0) {
            motion_timer--;
            if(motion_timer == 0) {
                motion_detected = FALSE;
                printf("Motion timer expired.\n");
            }
        }

        if(light_status == LIGHT_ON &&!motion_detected) {
            motion_detected = TRUE;
            printf("Motion detected, turning on light.\n");
        }

        sleep(1);
    }

    return 0;
}