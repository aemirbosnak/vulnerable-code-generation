//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//The following function adds a delay in the program
void delay(int num_sec){
    int ms = 1000 * num_sec;
    clock_t start_time = clock();
    while(clock() < start_time + ms);
}

int main(){
    char name[20];
    char answer;
    int choices;
    int door_choice, mirror_choice, book_choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("What's your name, dear player?\n");
    scanf("%s", name);

    printf("\nHello, %s. You have entered an old, deserted house and are now trapped inside. Your only way out is to explore and find the key to unlock the door.\n", name);
    printf("You start at the entrance of the house. There are two doors in front of you - one on your left and one on your right. Which door would you like to choose? Left (l) or right (r)?\n");

    //Door choice
    scanf(" %c", &answer);
    answer = tolower(answer);
    if(answer == 'l'){
        printf("\nYou open the left door and enter a dimly lit room. There is an old mirror and a bookcase in front of you. What would you like to do?\n");
        printf("1. Inspect the mirror\t2. Inspect the bookcase\n");
        scanf("%d", &choices);

        //Mirror or bookcase choice
        switch(choices){
            case 1:
                printf("\nYou approach the mirror and find that your reflection is not the only one. Suddenly, an evil spirit comes up from behind you and tries to possess you. You scream and run out of the room in horror.\n");
                delay(2);
                break;
            case 2:
                printf("\nAs you start inspecting the bookcase, you hear a loud creaking noise. Suddenly, the bookcase swivels around to reveal a secret passageway. You start walking towards it...\n");
                delay(2);
                break;
            default:
                printf("Invalid choice. Exiting now.\n");
                return 0;
        }
    }
    else if(answer == 'r'){
        printf("\nYou enter a room filled with cobwebs and spiders. There is a table with a lamp on it and a chest on the opposite end of the room. What would you like to do?\n");
        printf("1. Inspect the table\t2. Inspect the chest\n");
        scanf("%d", &choices);

        //Table or chest choice
        switch(choices){
            case 1:
                printf("\nYou approach the table and notice that the lamp is flickering. Suddenly, the lamp goes out and the room is plunged into darkness. You try to feel your way out but trip and fall onto a trap door. You are now in the basement.\n");
                delay(2);
                break;
            case 2:
                printf("\nAs you approach the chest, you hear a faint whispering. Suddenly, the chest opens up to reveal a key. You grab it and go back to the entrance.\n");
                delay(2);
                break;
            default:
                printf("Invalid choice. Exiting now.\n");
                return 0;
        }
    }
    else{
        printf("Invalid choice. Exiting now.\n");
        return 0;
    }

    printf("\nYou are now at the entrance again. You have a key, but there are two doors in front of you - one on your left and one on your right. Which door would you like to choose? Left (l) or right (r)?\n");

    //Door choice
    scanf(" %c", &answer);
    answer = tolower(answer);
    if(answer == 'l'){
        printf("\nAs you enter, you feel a cold breeze on your face. Suddenly, all the doors around you slam shut and lock themselves. There is no way out. You are now trapped inside the house forever.\n");
        delay(2);
    }
    else if(answer == 'r'){
        printf("\nYou enter a room filled with light. There is a window on the opposite end of the room. You see the keyhole on the door and run towards it. You put the key in and turn it. The door unlocks and you are free!\n");
        delay(2);
    }
    else{
        printf("Invalid choice. Exiting now.\n");
        return 0;
    }

    printf("\nCongratulations, %s! You've successfully escaped the haunted house.", name);

    return 0;
}