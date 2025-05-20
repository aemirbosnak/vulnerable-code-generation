//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define STOP 4

int main() {
    int choice, speed, direction;
    char input[3];
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please enter your choice: ");
    scanf("%s", input);
    if (strcmp(input, "start") == 0) {
        printf("Vehicle started.\n");
        while (1) {
            printf("Please enter your choice:\n1. Forward\n2. Backward\n3. Turn left\n4. Turn right\n5. Stop\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Vehicle moving forward.\n");
                    break;
                case 2:
                    printf("Vehicle moving backward.\n");
                    break;
                case 3:
                    printf("Vehicle turning left.\n");
                    break;
                case 4:
                    printf("Vehicle turning right.\n");
                    break;
                case 5:
                    printf("Vehicle stopped.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    } else if (strcmp(input, "stop") == 0) {
        printf("Vehicle stopped.\n");
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}