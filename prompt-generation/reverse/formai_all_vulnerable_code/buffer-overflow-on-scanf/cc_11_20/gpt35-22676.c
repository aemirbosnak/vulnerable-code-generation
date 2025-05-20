//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    srand(time(NULL)); //Initializing random seed

    //List of possible adventures
    char *adventures[] = {"forest","desert","space","ocean","mountain"};
    int num_adv = 5; //Number of possible adventures

    //Introduction
    printf("Welcome to the ephemeral adventure game!\n");
    printf("You find yourself in a strange place, not knowing how you got there.\n");
    printf("You hear a voice in your head that says 'Choose your adventure!'\n");
    printf("Your options are: \n");

    //Printing possible adventures
    for(int i = 0; i<num_adv; i++){
        printf("%d. %s\n",i+1,adventures[i]);
    }

    //Choosing the adventure
    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("\nYou have chosen the forest adventure!\n");
            break;
        case 2:
            printf("\nYou have chosen the desert adventure!\n");
            break;
        case 3:
            printf("\nYou have chosen the space adventure!\n");
            break;
        case 4:
            printf("\nYou have chosen the ocean adventure!\n");
            break;
        case 5:
            printf("\nYou have chosen the mountain adventure!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    //Random event
    int event = rand()%3;
    switch(event){
        case 0:
            printf("\nSuddenly, you hear a loud noise coming from nearby. What do you do?\n");
            printf("1. Investigate the noise\n");
            printf("2. Stay where you are\n");
            int choice2;
            printf("Enter the number of your choice: ");
            scanf("%d",&choice2);
            if(choice2==1){
                printf("\nYou investigate the noise and find a group of friendly woodland animals that guide you through the forest.\n");
            } else {
                printf("\nYou stay where you are and nothing happens.\n");
            }
            break;
        case 1:
            printf("\nYou see a strange object in the distance. What do you do?\n");
            printf("1. Investigate the object\n");
            printf("2. Ignore the object and continue on your way\n");
            int choice3;
            printf("Enter the number of your choice: ");
            scanf("%d",&choice3);
            if(choice3==1){
                printf("\nYou investigate the object and find it to be an alien spacecraft. You are abducted and taken on a trip through space!\n");
            } else {
                printf("\nYou ignore the object and continue on your way.\n");
            }
            break;
        case 2:
            printf("\nYou see a dark cave in front of you. What do you do?\n");
            printf("1. Enter the cave\n");
            printf("2. Go around the cave\n");
            int choice4;
            printf("Enter the number of your choice: ");
            scanf("%d",&choice4);
            if(choice4==1){
                printf("\nYou enter the cave and find a treasure trove full of treasure! You become rich and live happily ever after.\n");
            } else {
                printf("\nYou go around the cave and continue on your way.\n");
            }
            break;
    }

    //Conclusion
    printf("\nThank you for playing the ephemeral adventure game! Goodbye!\n");

    return 0;
}