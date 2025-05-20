//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hauntedHouse() {
    int choice;
    printf("Welcome to the Haunted House!\n");
    printf("You find yourself in a dark, spooky room with three doors.\n");
    printf("Which door will you choose?\n");
    printf("1. The door with the flickering light\n");
    printf("2. The door with the cobwebs\n");
    printf("3. The door with the eerie glow\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You open the door with the flickering light and enter a long hallway.\n");
            printf("The hallway is dimly lit by candles and lined with portraits of ghostly figures.\n");
            printf("As you walk down the hallway, the portraits seem to follow you with their eyes.\n");
            printf("Suddenly, a gust of wind blows out all the candles, plunging you into darkness!\n");
            break;
        case 2:
            printf("You choose the door with the cobwebs and find yourself in a dusty old library.\n");
            printf("The shelves are filled with ancient books and scrolls, and a fireplace crackles in the corner.\n");
            printf("As you reach for a book, a spider drops down from the ceiling and lands on your hand!\n");
            printf("You scream and shake it off, but the spider has disappeared.\n");
            break;
        case 3:
            printf("You approach the door with the eerie glow and feel a chill run down your spine.\n");
            printf("As you open the door, a blinding light engulfs you and you feel yourself being pulled forward!\n");
            printf("When the light fades, you find yourself in a room filled with strange artifacts and glowing crystals.\n");
            printf("Suddenly, the crystals start to hum and vibrate, and you realize that you've awakened an ancient force!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    srand(time(0));
    int choice;

    while(1) {
        hauntedHouse();
        printf("Do you want to continue? (y/n)\n");
        scanf("%c", &choice);
        if(choice == 'n') {
            break;
        }
    }

    return 0;
}