//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    int room_num = rand() % 3;

    switch (room_num) {
        case 0:
            printf("You have entered the Haunted Dining Hall.\n");
            break;
        case 1:
            printf("You have entered the Bloodstained Library.\n");
            break;
        case 2:
            printf("You have entered the Whispering Gallery.\n");
            break;
    }

    int sound_num = rand() % 3;

    switch (sound_num) {
        case 0:
            printf("You hear a shuffling sound.\n");
            break;
        case 1:
            printf("You hear a moaning sound.\n");
            break;
        case 2:
            printf("You hear a ghostly scream.\n");
            break;
    }

    printf("Suddenly, a cold wind blows through the room.\n");
    printf("The hairs on your neck stand on end.\n");
    printf("You feel a presence lurking in the shadows.\n");

    if (strcmp(name, "Jack") == 0) {
        printf("You hear a voice calling your name.\n");
        printf("The voice whispers secrets into your ear.\n");
    }

    printf("Are you brave enough to continue? (Y/N) ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y') {
        printf("You take a deep breath and continue your journey through the haunted house.\n");
    } else {
        printf("You flee in terror.\n");
    }

    return 0;
}