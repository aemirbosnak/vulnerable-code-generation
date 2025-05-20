//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets, num_inhabited_planets, num_inhabited_planets_destroyed;
    float probability_of_invasion;
    char choice;

    srand(time(0));
    num_planets = rand() % 1000 + 1;
    num_inhabited_planets = rand() % num_planets + 1;

    printf("In a distant galaxy, there are %d planets.\n", num_planets);
    printf("Of these, %d are inhabited by intelligent life forms.\n", num_inhabited_planets);

    system("clear");

    while (1) {
        printf("\nDo you want to simulate an alien invasion? (y/n): ");
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            num_inhabited_planets_destroyed = rand() % num_inhabited_planets + 1;
            probability_of_invasion = (float) num_inhabited_planets_destroyed / num_inhabited_planets * 100;

            printf("\nAn alien invasion has occurred!\n");
            printf("The probability of this happening was %.2f%%\n", probability_of_invasion);

            system("clear");

            while (1) {
                printf("\nDo you want to simulate another invasion? (y/n): ");
                scanf("%c", &choice);

                if (choice == 'y' || choice == 'Y') {
                    num_inhabited_planets_destroyed = rand() % num_inhabited_planets + 1;
                    probability_of_invasion = (float) num_inhabited_planets_destroyed / num_inhabited_planets * 100;

                    printf("\nAnother invasion has occurred!\n");
                    printf("The probability of this happening was %.2f%%\n", probability_of_invasion);

                    system("clear");
                } else {
                    break;
                }
            }
        } else {
            break;
        }
    }

    return 0;
}