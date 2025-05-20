#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int throttle = 0, steering = 0;
    
    while (1) {
        printf("Enter throttle (-50 to 50): ");
        scanf("%d", &throttle);
        
        if (throttle < -50 || throttle > 50) {
            printf("Throttle out of range. Please enter a value between -50 and 50.\n");
            continue;
        }
        
        printf("Enter steering (-30 to 30): ");
        scanf("%d", &steering);
        
        if (steering < -30 || steering > 30) {
            printf("Steering out of range. Please enter a value between -30 and 30.\n");
            continue;
        }
        
        if (throttle == 0 && steering == 0) {
            printf("Vehicle stopped.\n");
        } else if (throttle > 0) {
            if (steering == 0) {
                printf("Accelerating forward.\n");
            } else if (steering > 0) {
                printf("Turning right while accelerating.\n");
            } else {
                printf("Turning left while accelerating.\n");
            }
        } else {
            if (steering == 0) {
                printf("Decelerating backward.\n");
            } else if (steering > 0) {
                printf("Turning right while decelerating.\n");
            } else {
                printf("Turning left while decelerating.\n");
            }
        }
    }
    
    return 0;
}
