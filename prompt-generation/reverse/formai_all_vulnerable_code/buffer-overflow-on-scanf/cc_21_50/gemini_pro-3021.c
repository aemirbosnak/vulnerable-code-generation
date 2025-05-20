//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define RED 0
#define GREEN 1
#define YELLOW 2
#define OFF 3

int main() {
    printf("Enter the traffic light mode (0 for RED, 1 for GREEN, 2 for YELLOW, 3 for OFF): ");
    uint8_t mode;
    scanf("%hhu", &mode);

    while (true) {
        switch (mode) {
            case RED:
                printf("RED light is ON\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("YELLOW light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("GREEN light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("CROSSWALK light is OFF\n");
                break;
            case GREEN:
                printf("RED light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("YELLOW light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("GREEN light is ON\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("CROSSWALK light is OFF\n");
                break;
            case YELLOW:
                printf("RED light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("YELLOW light is ON\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("GREEN light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("CROSSWALK light is OFF\n");
                break;
            case OFF:
                printf("RED light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("YELLOW light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("GREEN light is OFF\n");
                for (int i = 0; i < 5; i++) {
                    putchar(' ');
                }
                printf("CROSSWALK light is OFF\n");
                break;
            default:
                printf("Invalid mode! Enter 0 for RED, 1 for GREEN, 2 for YELLOW, or 3 for OFF: ");
                scanf("%hhu", &mode);
        }

        sleep(1);

        if (mode == RED) {
            mode = GREEN;
        } else if (mode == GREEN) {
            mode = YELLOW;
        } else if (mode == YELLOW) {
            mode = RED;
        }
    }

    return 0;
}