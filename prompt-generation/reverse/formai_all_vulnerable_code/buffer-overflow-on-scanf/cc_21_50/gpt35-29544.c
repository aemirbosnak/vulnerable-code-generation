//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // set a seed for random number generation

    printf("Welcome to the Surrealist Game!\n");
    printf("You are in a dream world where anything is possible.\n");
    printf("Your goal is to reach the end of the dream world by making the right choices.\n");
    printf("Good luck!\n\n");

    int current_room = 1; // start at room 1
    int choice;

    while(current_room != 7){ // loop until player reaches the end
        printf("You are in room %d.\n", current_room);
        printf("Choose an option:\n");

        switch(current_room){
            case 1:
                printf("1. Look in the mirror.\n");
                printf("2. Jump out the window.\n");
                printf("3. Open the door.\n");
                break;

            case 2:
                printf("1. Pick up the phone.\n");
                printf("2. Go through the tunnel.\n");
                printf("3. Go back through the door.\n");
                break;

            case 3:
                printf("1. Drink the potion.\n");
                printf("2. Read the book.\n");
                printf("3. Leave the room.\n");
                break;

            case 4:
                printf("1. Cross the bridge.\n");
                printf("2. Swim across the river.\n");
                printf("3. Take the boat.\n");
                break;

            case 5:
                printf("1. Follow the yellow brick road.\n");
                printf("2. Climb the beanstalk.\n");
                printf("3. Walk through the forest.\n");
                break;

            case 6:
                printf("1. Eat the mushroom.\n");
                printf("2. Push the door open.\n");
                printf("3. Jump down the hole.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(current_room){
            case 1:
                if(choice == 1){
                    printf("You see a different version of yourself in the mirror.\n");
                    printf("You feel like you have a deeper understanding of yourself.\n");
                }
                else if(choice == 2){
                    printf("You jump out the window and start flying.\n");
                    printf("You realize that anything is possible in the dream world.\n");
                }
                else if(choice == 3){
                    printf("You open the door and enter the next room.\n");
                    current_room = 2;
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;

            case 2:
                if(choice == 1){
                    printf("You pick up the phone and hear a voice on the other end.\n");
                    printf("The voice tells you that you're on a journey to find your true self.\n");
                }
                else if(choice == 2){
                    printf("You crawl through the tunnel and find yourself in a magical cave.\n");
                    printf("You feel like you're getting closer to your destination.\n");
                    current_room = 4;
                }
                else if(choice == 3){
                    printf("You go back through the door and return to the previous room.\n");
                    current_room = 1;
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;

            case 3:
                if(choice == 1){
                    printf("You drink the potion and feel your consciousness expand.\n");
                    printf("You see the world in a new light and feel more connected to everything.\n");
                }
                else if(choice == 2){
                    printf("You read the book and gain a deeper understanding of the world.\n");
                    printf("You feel like you're on the right path.\n");
                    current_room = 5;
                }
                else if(choice == 3){
                    printf("You leave the room and enter the next one.\n");
                    current_room = 4;
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;

            case 4:
                if(choice == 1){
                    printf("You cross the bridge and feel like you're facing your fears.\n");
                    printf("You realize that you're capable of anything.\n");
                    current_room = 6;
                }
                else if(choice == 2){
                    printf("You swim across the river and feel like you're reborn.\n");
                    printf("You have a new perspective on life.\n");
                    current_room = 5;
                }
                else if(choice == 3){
                    printf("You take the boat and enjoy the peaceful ride.\n");
                    printf("You feel like you're in a dream.\n");
                    current_room = 1; // start over
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;

            case 5:
                if(choice == 1){
                    printf("You follow the yellow brick road and find a treasure chest.\n");
                    printf("You realize that the journey is worth it.\n");
                    current_room = 7; // end game
                }
                else if(choice == 2){
                    printf("You climb the beanstalk and reach the clouds.\n");
                    printf("You feel like you're on top of the world.\n");
                    current_room = 6;
                }
                else if(choice == 3){
                    printf("You walk through the forest and feel lost.\n");
                    printf("You're not sure where you're headed.\n");
                    current_room = rand() % 3 + 1; // choose a random room
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;

            case 6:
                if(choice == 1){
                    printf("You eat the mushroom and shrink in size.\n");
                    printf("You become more aware of the world around you.\n");
                    current_room = 3;
                }
                else if(choice == 2){
                    printf("You push the door open and enter a new world.\n");
                    printf("You feel like you've reached your destination.\n");
                    current_room = 7; // end game
                }
                else if(choice == 3){
                    printf("You jump down the hole and find yourself in a new room.\n");
                    current_room = rand() % 3 + 4; // choose a random room
                }
                else{
                    printf("Invalid choice.\n");
                }
                break;
        }

        printf("\n");
    }

    printf("Congratulations! You've reached the end of the dream world!\n");
    printf("Your journey has helped you find your true self.\n");
    printf("Thanks for playing The Surrealist Game!\n");

    return 0;
}