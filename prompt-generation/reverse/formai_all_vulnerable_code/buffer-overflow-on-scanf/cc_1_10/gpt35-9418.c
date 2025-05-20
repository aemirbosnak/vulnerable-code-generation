//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int num = rand()%100;
    int choice, count = 0;

    printf("You are standing in front of a haunted house...\n");
    printf("Press 1 to enter the house or 2 to run away: ");
    scanf("%d", &choice);

    if(choice==1){
        printf("\nYou open the door and step into the spooky hallway...\n");
        printf("As you walk, you start to feel a sense of dread...\n");
        printf("Suddenly, a voice booms through the hallway...\n");
        printf("I am the ghost of the previous owner, and I will not let you leave unless you solve my riddle...\n");
        printf("Are you ready to accept my challenge? Press 1 for yes or 2 for no: ");
        scanf("%d", &choice);

        if(choice==1){
            printf("\nGood. Here is your riddle...\n");
            printf("I am taken from a mine, and shut up in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?\n");
            printf("Enter your answer: ");

            char answer[100];
            scanf("%s", answer);

            if(strcmp(answer, "pencil")==0){
                printf("\nYou have solved my riddle! You may proceed...\n");
                while(count < 3){
                    printf("You enter a room that is completely dark and hear some strange noises from afar...\n");
                    printf("As you start to move around, you realize that there are objects protruding out of the walls...\n");
                    printf("You try to avoid them but one of them impales you...\n");
                    printf("OUCH! You have been killed by a spike. Try again.\n");
                    printf("Press 1 to try again or 2 to give up: ");
                    scanf("%d", &choice);

                    if(choice==1){
                        count++;
                        printf("You have %d out of 3 chances remaining...\n", 3-count);
                    }
                    else{
                        printf("You have given up and there is no escaping. You are trapped inside this haunted house forever...\n");
                        exit(0);
                    }
                }
                printf("\nCongratulations! You have successfully avoided all the traps and reached the end of the haunted house...\n");
                printf("But alas, you see another door...\n");
                printf("Press 1 to open the door or 2 to give up: ");
                scanf("%d", &choice);

                if(choice==1){
                    printf("\nYou open the door and realize that you have been tricked again...\n");
                    printf("You have been swallowed by a giant mouth belonging to a creature that was waiting there...\n");
                    printf("GAME OVER.");
                    exit(0);
                }
                else{
                    printf("You have given up and there is no escaping. You are trapped inside this haunted house forever...\n");
                    exit(0);
                }
            }
            else{
                printf("\nWrong answer! You have been cursed and can no longer see.\n");
                printf("Press 1 to try again or 2 to give up: ");
                scanf("%d", &choice);

                if(choice==1){
                    printf("\nYou have been given a second chance, but be careful...\n");
                    printf("Enter your answer carefully: ");

                    char answer[100];
                    scanf("%s", answer);

                    if(strcmp(answer, "pencil")==0){
                        printf("\nYou have solved my riddle and have been freed from the curse...\n");
                        exit(0);
                    }
                    else{
                        printf("\nWrong answer again! You are now trapped inside this haunted house forever...\n");
                        exit(0);
                    }
                }
                else{
                    printf("\nYou have given up and there is no escaping. You are trapped inside this haunted house forever...\n");
                    exit(0);
                }
            }
        }
        else{
            printf("\nThe ghost was not pleased with your answer...\n");
            printf("He cast a spell and you have been teleported to a different dimension...\n");
            printf("GAME OVER.");
            exit(0);
        }
    }
    else{
        printf("\nYou run away from the haunted house in fear...\n");
        printf("You have a feeling that you missed out on something important...\n");
        printf("You missed your chance to challenge the ghost and solve his riddle...\n");
        printf("You have lost an opportunity to overcome your fears...\n");
        printf("GAME OVER.");
        exit(0);
    }
    return 0;
}