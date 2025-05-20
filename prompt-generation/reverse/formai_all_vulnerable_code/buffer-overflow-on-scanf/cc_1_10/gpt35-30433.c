//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are stranded on a strange planet and must find a way back home.\n");
    printf("You look around and see a spacecraft in the distance, but it seems to be damaged.\n");
    printf("You decide to approach it and see if you can fix it.\n");
    printf("As you get closer, you realize that the spacecraft is not from Earth.\n");
    printf("You see strange markings on the exterior and wonder who or what could have created it.\n");
    printf("You decide to investigate further.\n");

    srand(time(NULL)); // generate random numbers based on current time
    int fuel = rand() % 101 + 50; // generate random fuel amount between 50 and 150
    int health = rand() % 101 + 50; // generate random health amount between 50 and 150

    printf("You enter the spacecraft and notice that the control panels are unlike anything you've ever seen before.\n");
    printf("You begin to fiddle around with the buttons and levers, hoping to find a way to get home.\n");
    printf("Suddenly, the spacecraft comes to life and the engines roar to life!\n");
    printf("You quickly realize that the spacecraft is not under your control and you are being taken on an unexpected journey.\n");

    int distance = rand() % 100001 + 50000; // generate random distance between 50,000 and 150,000
    int time = distance / (rand() % 51 + 50); // generate random time based on distance and speed

    printf("The spacecraft accelerates and you are hurtled through space at breakneck speed.\n");
    printf("As you look out the window, you see galaxies and planets passing by in a blur.\n");
    printf("You have no idea where you are or where you're going, but you know that you must survive.\n");
    printf("You check the fuel gauge and see that you have %d units of fuel left.\n", fuel);
    printf("You check your health monitor and see that you are at %d%% health.\n", health);
    printf("You estimate that you have about %d hours before you run out of fuel.\n", time);

    int choice = 0;
    while (choice != 4) {
        printf("What do you want to do?\n");
        printf("1. Search for resources\n");
        printf("2. Repair the spacecraft\n");
        printf("3. Contact home\n");
        printf("4. Quit the game\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You search the spacecraft and find some spare parts and fuel.\n");
                fuel += rand() % 51 + 25; // generate random fuel amount between 25 and 75
                health += rand() % 26; // generate random health amount between 0 and 25
                printf("You now have %d units of fuel and %d%% health.\n", fuel, health);
                break;
            case 2:
                printf("You attempt to repair the spacecraft, but it proves to be a daunting task.\n");
                printf("You manage to fix some of the damage, but not enough to get home.\n");
                health -= rand() % 26; // generate random health amount between 0 and 25
                printf("Your health is now at %d%%.\n", health);
                break;
            case 3:
                printf("You attempt to contact home, but all you get is static.\n");
                health -= rand() % 26; // generate random health amount between 0 and 25
                printf("Your health is now at %d%%.\n", health);
                break;
            case 4:
                printf("You have decided to quit the game.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        if (health <= 0 || fuel <= 0) {
            printf("You have run out of health or fuel and have perished in space.\n");
            break;
        }

        if (distance <= 0) {
            printf("You have successfully completed your adventure and have returned home!\n");
            break;
        }
        
        distance -= rand() % 5001 + 2500; // generate random distance between 2500 and 7500
        fuel -= rand() % 11 + 5; // generate random fuel amount between 5 and 15
        health -= rand() % 11; // generate random health amount between 0 and 10
    }

    printf("Thank you for playing Procedural Space Adventure!\n");

    return 0;
}