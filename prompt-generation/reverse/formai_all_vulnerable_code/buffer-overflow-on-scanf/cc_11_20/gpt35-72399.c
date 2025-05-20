//FormAI DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Let's get started by checking the status of your lights.\n");

    int light1 = 0;
    int light2 = 0;
    int light3 = 0;
    int light4 = 0;

    printf("\nCurrent status of lights:\n");
    printf("Light 1: %d\n", light1);
    printf("Light 2: %d\n", light2);
    printf("Light 3: %d\n", light3);
    printf("Light 4: %d\n", light4);

    printf("\nDo you want to turn on any lights? (y/n)\n");
    char response;
    scanf("%c", &response);

    if (response == 'y') {
        printf("\nWhich light do you want to turn on? (1/2/3/4)\n");
        int light_num;
        scanf("%d", &light_num);

        switch (light_num) {
            case 1:
                light1 = 1;
                printf("\nLight 1 has been turned on.\n");
                break;
            case 2:
                light2 = 1;
                printf("\nLight 2 has been turned on.\n");
                break;
            case 3:
                light3 = 1;
                printf("\nLight 3 has been turned on.\n");
                break;
            case 4:
                light4 = 1;
                printf("\nLight 4 has been turned on.\n");
                break;
            default:
                printf("\nInvalid input. No lights turned on.\n");
        }
    }

    printf("\nCurrent status of lights:\n");
    printf("Light 1: %d\n", light1);
    printf("Light 2: %d\n", light2);
    printf("Light 3: %d\n", light3);
    printf("Light 4: %d\n", light4);

    printf("\nDo you want to turn off any lights? (y/n)\n");
    scanf(" %c", &response);

    if (response == 'y') {
        printf("\nWhich light do you want to turn off? (1/2/3/4)\n");
        int light_num;
        scanf("%d", &light_num);

        switch (light_num) {
            case 1:
                light1 = 0;
                printf("\nLight 1 has been turned off.\n");
                break;
            case 2:
                light2 = 0;
                printf("\nLight 2 has been turned off.\n");
                break;
            case 3:
                light3 = 0;
                printf("\nLight 3 has been turned off.\n");
                break;
            case 4:
                light4 = 0;
                printf("\nLight 4 has been turned off.\n");
                break;
            default:
                printf("\nInvalid input. No lights turned off.\n");
        }
    }

    printf("\nCurrent status of lights:\n");
    printf("Light 1: %d\n", light1);
    printf("Light 2: %d\n", light2);
    printf("Light 3: %d\n", light3);
    printf("Light 4: %d\n", light4);

    printf("\nThank you for using the Smart Home Light Control System!\n");

    return 0;
}