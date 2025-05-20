//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds){
    clock_t start_time = clock();
    while(clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Are you ready to enter the haunted house?(y/n)\n");
    char choice;
    scanf("%c", &choice);
    if(choice == 'y'){
        printf("Great! Please follow me.\n");
        delay(2);
        printf("As you enter the dark hallway, you hear creaking noises from the old floorboards.\n");
        delay(3);
        printf("The temperature in the hallway drops suddenly, sending a chill down your spine.\n");
        delay(3);
        printf("You see a creepy painting on the wall, its eyes seem to be following you.\n");
        delay(3);
        printf("Suddenly, a gust of wind blows out your flashlight.\n");
        delay(3);
        printf("You feel something brush past your leg, causing you to jump.\n");
        delay(3);
        printf("What would you like to do?\n");
        printf("a. Turn back\n");
        printf("b. Keep walking\n");
        char decision;
        scanf(" %c", &decision);
        if(decision == 'a'){
            printf("You turn back, ending your haunted house experience.\n");
        }
        else if(decision == 'b'){
            printf("You keep walking, careful not to trip in the dark.\n");
            delay(3);
            printf("You reach a door at the end of the hallway.\n");
            delay(3);
            printf("Do you want to open the door?(y/n)\n");
            char open_door_choice;
            scanf(" %c", &open_door_choice);
            if(open_door_choice == 'y'){
                printf("You open the door and find yourself in a dusty old bedroom.\n");
                delay(3);
                printf("Your flashlight flickers on and off, making it difficult to see.\n");
                delay(3);
                printf("You hear a strange noise coming from the closet.\n");
                delay(3);
                printf("What would you like to do?\n");
                printf("a. Open the closet\n");
                printf("b. Leave the room\n");
                char closet_choice;
                scanf(" %c", &closet_choice);
                if(closet_choice == 'a'){
                    printf("You slowly open the closet door.\n");
                    delay(3);
                    printf("Suddenly, a ghostly figure appears in front of you!\n");
                }
                else if(closet_choice == 'b'){
                    printf("You leave the room, ending your haunted house experience.\n");
                }
            }
            else if(open_door_choice == 'n'){
                printf("You decide not to open the door, ending your haunted house experience.\n");
            }
        }
    }
    else if(choice == 'n'){
        printf("Perhaps another time, thank you for considering the Haunted House Simulator.\n");
    }
    return 0;
}