//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int choice;

    while(1) {
        printf("Welcome to the Haunted House!\n");
        printf("Please choose your path:\n");
        printf("1. Enter the house\n");
        printf("2. Leave the house\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("clear");
                printf("You entered the house...\n");
                printf("You feel a cold breeze and hear strange noises.\n");
                printf("Do you want to continue exploring? (y/n)\n");
                char cont;
                scanf(" %c", &cont);

                if(cont == 'y' || cont == 'Y') {
                    system("clear");
                    printf("You continue exploring the house...\n");
                    printf("Suddenly, a ghost appears in front of you!\n");
                    printf("Do you want to fight the ghost or run away? (f/r)\n");
                    char fightorrun;
                    scanf(" %c", &fightorrun);

                    if(fightorrun == 'f' || fightorrun == 'F') {
                        system("clear");
                        printf("You decide to fight the ghost...\n");
                        printf("You use your flashlight as a weapon and defeat the ghost!\n");
                        printf("Congratulations, you survived the haunted house!\n");
                        break;
                    } else if(fightorrun == 'r' || fightorrun == 'R') {
                        system("clear");
                        printf("You decide to run away...\n");
                        printf("You run as fast as you can and escape the haunted house!\n");
                        printf("Congratulations, you survived the haunted house!\n");
                        break;
                    } else {
                        printf("Invalid choice. Please try again.\n");
                    }
                } else {
                    printf("You decide to leave the house...\n");
                    printf("Congratulations, you survived the haunted house!\n");
                    break;
                }
                break;

            case 2:
                printf("You leave the house...\n");
                printf("Congratulations, you survived the haunted house!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}