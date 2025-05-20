//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    srand(time(NULL));

    int choices[10];
    int door_num = 1;   
    int player_choice = 0;
    int prize_door = rand() % 10 + 1;  

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please choose a door between 1 and 10: ");
    scanf("%d", &player_choice);

    for (int i=0; i < 10; i++) {
        choices[i] = door_num;
        door_num++;
    }

    for (int i=0; i < 10; i++) {
        if (choices[i] == player_choice) {
            printf("You chose Door Number %d.\n", player_choice);
            break;
        }
    }

    printf("The Haunted House has opened a door.\n");
    int haunter_choice = 0;

    for (int i=0; i < 10; i++) {  
        if (choices[i] != player_choice && choices[i] != prize_door) {
            haunter_choice = choices[i];
            break;
        }
    }

    printf("Door Number %d has been opened.\n", haunter_choice);

    printf("Do you want to change your choice? Enter \"1\" for \"Yes\" or \"0\" for \"No\": ");
    int change_choice = 0;
    scanf("%d", &change_choice);

    if (change_choice == 1) {
        for (int i=0; i < 10; i++) {
            if (choices[i] != player_choice && choices[i] != haunter_choice) {
                player_choice = choices[i];
                break;
            }
        }
    }

    if (player_choice == prize_door) {
        printf("Congratulations! You have won the grand prize!\n");
    } else {
        printf("Sorry, you have not won the grand prize.\n");
    }

    return 0;
}