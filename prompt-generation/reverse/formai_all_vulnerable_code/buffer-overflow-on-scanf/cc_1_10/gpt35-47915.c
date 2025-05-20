//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include<stdio.h>  
#include<stdlib.h> 
#include<time.h> 

int main(){  
    char playerName[20];
    printf("Welcome to the Haunted House Simulator!\n");
    printf("What is your name? ");
    scanf("%s", &playerName);
    printf("Hello %s!\n", playerName);
    printf("You have entered a dark, hauntingly silent mansion...\n");
    printf("Press enter to continue");
    getchar();
    getchar();

    int choice;
    int flashlight = 0; // 0 denotes no flashlight, 1 denotes flashlight 
    int key = 0; // 0 denotes no key, 1 denotes key 

    do {
        printf("You are in a dimly lit foyer.\n");
        printf("There are two doors in front of you.\n");
        printf("1. Take the door on the left\n");
        printf("2. Take the door on the right\n");
        printf("What is your choice? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You walk into a room filled with cobwebs and dust.\n");
                if(flashlight == 0) {
                    printf("It's too dark to see anything.\n");
                } else {
                    printf("You see a key on the floor.\n");
                    key = 1;
                }
                break;
            case 2:
                printf("You walk into a room with a spooky chandelier hanging from the ceiling.\n");
                if(key == 0) {
                    printf("You see a flashlight on the table, but it's locked.\n");
                } else {
                    printf("With the key, you unlock the flashlight on the table and switch it on.\n");
                    flashlight = 1;
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (key == 0 || flashlight == 0);

    printf("You make your way up the stairs to the second floor.\n");
    printf("You hear a strange whispering sound coming from one of the rooms.\n");

    srand(time(NULL)); // random seed. This ensures that every time you run the program, the room number will be different.
    int roomNumber = rand() % 3 + 1; // This gives us a random room number between 1 and 3. 

    switch(roomNumber) {
        case 1:
            printf("You enter a room filled with eerie, foggy mist.\n");
            printf("Suddenly, a ghostly figure appears before you and screams!\n");
            break;
        case 2:
            printf("You enter a room with an old, rickety rocking chair.\n");
            printf("The chair starts moving back and forth on its own...\n");
            break;
        case 3:
            printf("You enter a room with a creepy painting on the wall.\n");
            printf("As you walk closer, the painting seems to come alive and the eyes follow you...\n");
            break;
    }

    printf("You try to run, but the door won't open!\n");
    printf("You are trapped!\n");

    return 0;
}