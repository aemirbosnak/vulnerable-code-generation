//FormAI DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int light = 0;
    int temperature = 70;
    int password = 1234;
    int input;
    
    while (1) {
        printf("Current Light Level: %d\n", light);
        printf("Current Temperature: %d\n", temperature);
        printf("Enter password: ");
        scanf("%d", &input);
        
        if (input == password) {
            printf("Access granted.\n");
            printf("Enter a command (1 = turn on lights, 2 = turn off lights, 3 = increase temperature, 4 = decrease temperature): ");
            scanf("%d", &input);
            
            switch (input) {
                case 1:
                    light = 100;
                    printf("Lights turned on.\n");
                    break;
                case 2:
                    light = 0;
                    printf("Lights turned off.\n");
                    break;
                case 3:
                    temperature += 1;
                    printf("Temperature increased.\n");
                    break;
                case 4:
                    temperature -= 1;
                    printf("Temperature decreased.\n");
                    break;
                default:
                    printf("Invalid command.\n");
            }
        } else {
            printf("Access denied.\n");
        }
        
        // Wait 1 second before looping again
        struct timespec wait_time = {1, 0};
        nanosleep(&wait_time, NULL);
    }
    
    return 0;
}