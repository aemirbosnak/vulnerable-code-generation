//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void print_red_light() {
    printf("\n  .     .\n / \\   / \\\n \\ 0   0 /\n  '-| |-'\n    /_\\ \n");
}

void print_green_light() {
    printf("\n    .'.\n   '   '\n   \\   /\n  _ _\\ /_ _\n |_     _|\n   |   |\n  ----- \n");
}

void print_yellow_light() {
    printf("\n      .\n       .\n    .-----.\n   |  o o  |\n   |   |   |\n    '-----' \n");
}

void print_traffic_light(int color) {
    switch (color) {
        case 1:
            print_red_light();
            break;
        case 2:
            print_yellow_light();
            break;
        case 3:
            print_green_light();
            break;
        default:
            printf("Invalid color code\n");
            break;
    }
}

int main() {
    int light_colors[3] = {1, 2, 3};
    int current_color = 0;

    printf("Medieval Traffic Light Controller\n");
    printf("---------------------------------\n\n");

    while (1) {
        printf("Current Light: ");

        switch (current_color) {
            case 0:
                printf("Red\n");
                break;
            case 1:
                printf("Yellow\n");
                break;
            case 2:
                printf("Green\n");
                break;
        }

        print_traffic_light(light_colors[current_color]);

        if (current_color == 0) {
            delay(3000);
            current_color = 1;
        } else if (current_color == 1) {
            delay(1000);
            current_color = 2;
        } else {
            delay(5000);
            current_color = 0;
        }

        system("clear");
    }

    return 0;
}