//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printRoom(int, bool);
void wait(int);

int main()
{
    int room = 1;
    bool hasKey = false;
    bool hasFlashlight = false;
    bool isLocked = true;
    bool isDark = true;
    int choice;
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of an old, crumbling mansion.\n");
    printf("It looks like it hasn't been touched in years. The wind is howling \n");
    printf("and the trees are creaking. As you walk closer to the door, you notice\n");
    printf("that it's slightly ajar. You push it open and step inside...\n\n");
    
    while(room != 7) {
        switch(room) {
            case 1:
                printRoom(room, false);
                printf("Do you want to look for a key? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    if(rand() % 2 == 0) {
                        printf("\nYou found a key!\n\n");
                        hasKey = true;
                        wait(2);
                    } else {
                        printf("\nYou couldn't find a key.\n\n");
                        wait(2);
                    }
                } else {
                    printf("\nYou decided not to look for a key.\n\n");
                    wait(2);
                }
                if(hasKey) {
                    printf("Do you want to unlock the door? (1 for yes, 2 for no)\n");
                    scanf("%d", &choice);
                    if(choice == 1) {
                        printf("\nYou unlocked the door!\n\n");
                        isLocked = false;
                        wait(2);
                    } else {
                        printf("\nYou decided not to unlock the door.\n\n");
                        wait(2);
                    }
                }
                
                if(!isLocked) {
                    printf("You are now in the foyer.\n");
                    printf("Which room do you want to go to? (1 for living room, 2 for kitchen)\n");
                    scanf("%d", &choice);
                    if(choice == 1) {
                        room = 2;
                    } else {
                        room = 3;
                    }
                }
                break;
            case 2:
                printRoom(room, hasFlashlight);
                printf("Do you want to turn on your flashlight? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    if(hasFlashlight) {
                        isDark = false;
                        printf("\nYou turned on your flashlight.\n\n");
                        wait(2);
                    } else {
                        printf("\nYou don't have a flashlight.\n\n");
                        wait(2);
                    }
                } else {
                    printf("\nYou decided not to turn on your flashlight.\n\n");
                    wait(2);
                }
                
                printf("Do you want to search the room? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    if(rand() % 2 == 0) {
                        printf("\nYou found a flashlight!\n\n");
                        hasFlashlight = true;
                        wait(2);
                    } else {
                        printf("\nYou couldn't find anything.\n\n");
                        wait(2);
                    }
                } else {
                    printf("\nYou decided not to search the room.\n\n");
                    wait(2);
                }
                
                printf("Do you want to go back to the foyer? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    room = 1;
                } else {
                    printf("\nYou decided to stay in the living room.\n\n");
                    wait(2);
                }
                break;
            case 3:
                printRoom(room, hasFlashlight);
                printf("Do you want to turn on your flashlight? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    if(hasFlashlight) {
                        isDark = false;
                        printf("\nYou turned on your flashlight.\n\n");
                        wait(2);
                    } else {
                        printf("\nYou don't have a flashlight.\n\n");
                        wait(2);
                    }
                } else {
                    printf("\nYou decided not to turn on your flashlight.\n\n");
                    wait(2);
                }
                
                printf("Do you want to search the room? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    if(rand() % 2 == 0) {
                        printf("\nYou found a key!\n\n");
                        hasKey = true;
                        wait(2);
                    } else {
                        printf("\nYou couldn't find anything.\n\n");
                        wait(2);
                    }
                } else {
                    printf("\nYou decided not to search the room.\n\n");
                    wait(2);
                }
                
                printf("Do you want to go back to the foyer? (1 for yes, 2 for no)\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    room = 1;
                } else {
                    printf("\nYou decided to stay in the kitchen.\n\n");
                    wait(2);
                }
                break;
        }
    }
    
    printf("You made it to the secret room!\n\n");
    printf("Congratulations on surviving the Haunted House Simulator!\n");
    
    return 0;
}

void printRoom(int room, bool isLit) {
    printf("You are now in room %d.\n", room);
    if(isLit) {
        printf("It is well-lit.\n");
    } else {
        printf("It is dark.\n");
    }
}

void wait(int seconds) {
    int milliSeconds = 1000 * seconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}