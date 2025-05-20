//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int drone_health = 100;
    int drone_power = 50;
    int drone_armor = 25;
    int controller_health = 100;
    int controller_power = 50;
    int controller_armor = 25;
    int drone_attack_choice;
    int controller_attack_choice;

    printf("\n---------------------------------------------\n");
    printf("------Cyberpunk C Drone Remote Control--------\n");
    printf("---------------------------------------------\n");

    while (drone_health > 0 && controller_health > 0) {
        printf("\n---------------------------------------------\n");
        printf("------ Current Status ------\n");
        printf("Drone Health: %d\n", drone_health);
        printf("Controller Health: %d\n", controller_health);
        printf("---------------------------------------------\n");

        printf("\nController, choose your attack:\n");
        printf("1. Power Surge\n");
        printf("2. EMP Blast\n");
        printf("3. Hacking\n");
        printf("4. Shield Boost\n");
        printf("Enter choice: ");
        scanf("%d", &controller_attack_choice);

        printf("\nDrone, choose your attack:\n");
        printf("1. Laser Attack\n");
        printf("2. Missiles\n");
        printf("3. Ramming Speed\n");
        printf("4. Stealth Mode\n");
        printf("Enter choice: ");
        scanf("%d", &drone_attack_choice);

        switch (controller_attack_choice) {
            case 1:
                printf("\nController uses Power Surge!\n");
                printf("Drone loses %d health points!\n", controller_power);
                drone_health -= controller_power;
                break;
            case 2:
                printf("\nController uses EMP Blast!\n");
                printf("Drone loses %d armor points!\n", controller_armor);
                drone_armor -= controller_armor;
                break;
            case 3:
                printf("\nController uses Hacking!\n");
                printf("Drone's power is decreased by %d points!\n", controller_power);
                drone_power -= controller_power;
                break;
            case 4:
                printf("\nController uses Shield Boost!\n");
                printf("Controller's armor is increased by %d points!\n", controller_armor);
                controller_armor += controller_armor;
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

        switch (drone_attack_choice) {
            case 1:
                printf("\nDrone uses Laser Attack!\n");
                printf("Controller loses %d armor points!\n", drone_armor);
                controller_armor -= drone_power;
                break;
            case 2:
                printf("\nDrone uses Missiles!\n");
                printf("Controller loses %d health points!\n", drone_power);
                controller_health -= drone_power;
                break;
            case 3:
                printf("\nDrone uses Ramming Speed!\n");
                printf("Controller loses %d health points!\n", drone_power * 2);
                controller_health -= (drone_power * 2);
                break;
            case 4:
                printf("\nDrone uses Stealth Mode!\n");
                printf("Drone's armor is increased by %d points!\n", drone_armor);
                drone_armor += drone_armor;
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

        if (drone_health <= 0) {
            printf("\nDrone is destroyed. Controller wins!\n");
        } else if (controller_health <= 0) {
            printf("\nController is down. Drone wins!\n");
        } else {
            printf("\nBoth remain standing!\n");
        }

        //Pause for dramatic effect
        printf("\n\n");
        system("PAUSE");

        system("cls"); //clear console window
    }

    printf("\n---------------------------------------------");
    printf("\n--------------Battle Over!-------------------");
    printf("\n---------------------------------------------\n");

    return 0;
}