//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand(time(&t));
    int haunted_house_num = rand() % 3;
    switch (haunted_house_num) {
        case 0:
            printf("Welcome to the Haunted Victorian Mansion!\n");
            break;
        case 1:
            printf("Prepare for the Twisted Manor of Morbid Manor!\n");
            break;
        case 2:
            printf("Enter the Whispering Tower of Terror!\n");
            break;
    }

    int rooms_num = rand() % 5 + 3;
    printf("There are %d rooms in the house.\n", rooms_num);

    for (int i = 0; i < rooms_num; i++) {
        printf("You are in room %d.\n", i + 1);

        int spooky_sounds_num = rand() % 3;
        switch (spooky_sounds_num) {
            case 0:
                printf("Hear the faintest whisper.\n");
                break;
            case 1:
                printf("The wind blows through the trees, creating a chilling sound.\n");
                break;
            case 2:
                printf("A ghostly moan echoes through the halls.\n");
                break;
        }

        if (rand() % 2) {
            printf("Suddenly, a door creaks open.\n");
        }

        if (rand() % 3) {
            printf("A cold wind blows through the room, extinguishing the candles.\n");
        }

        printf("Do you want to continue exploring? (y/n) ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    printf("Thank you for visiting the Haunted House! Come again soon!\n");

    return 0;
}