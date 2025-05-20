//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 30

int main(){
    int choice;
    char input[MAX_INPUT];

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the cryptic adventure game!\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", input);

    printf("\nHello, %s. You find yourself in a dark and mysterious world.\n", input);

    printf("\nYou come across a fork in the road, with two paths to choose from.\n");
    printf("Which path will you take?\n");
    while(1){
        printf("Enter 1 for Path A, 2 for Path B: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nYou choose Path A and begin your journey.\n");
            break;
        }
        else if(choice == 2){
            printf("\nYou choose Path B and begin your journey.\n");
            break;
        }
        else{
            printf("\nI do not understand. Please try again.\n");
        }
    }

    printf("\nAs you travel down the path, you encounter a strange creature.\n");
    printf("It looks like a cross between a dragon and a spider, with razor-sharp teeth and claws.\n");
    printf("What will you do?\n");
    while(1){
        printf("Enter 1 to attack, 2 to run away: ");
        scanf("%d", &choice);
        if(choice == 1){
            int attack = rand() % 20 + 1; // generate random attack value
            int defense = rand() % 20 + 1; // generate random defense value
            printf("\nYou attack the creature!\n");
            if(attack > defense){
                printf("You successfully defeat the creature and continue on your journey.\n");
                break;
            }
            else{
                printf("The creature is too strong for you and defeats you. Game over.\n");
                return 0;
            }
        }
        else if(choice == 2){
            printf("\nYou decide to run away and continue on your journey.\n");
            break;
        }
        else{
            printf("\nI do not understand. Please try again.\n");
        }
    }

    printf("\nAfter a while, you come to a large door blocking your path.\n");
    printf("It has a cryptic inscription on it that reads:\n\n");

    // generate random inscription
    int r = rand() % 5;
    switch(r){
        case 0:
            printf("In darkness, seek light\n");
            break;
        case 1:
            printf("Your heart is the key\n");
            break;
        case 2:
            printf("The answer lies within\n");
            break;
        case 3:
            printf("Solve the riddle and pass\n");
            break;
        case 4:
            printf("The way is barred to the unworthy\n");
            break;
    }

    printf("\nWhat do you do?\n");
    while(1){
        printf("Enter a sentence as your answer: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        if(strlen(input) > 0){
            printf("\nThe door opens and you continue on your journey.\n");
            break;
        }
        else{
            printf("\nI do not understand. Please try again.\n");
        }
    }

    printf("\nYou come across a large cavern with a river running through it.\n");
    printf("There is a boat on the shore, but it looks like it has seen better days.\n");
    printf("What will you do?\n");
    while(1){
        printf("Enter 1 to take the boat, or 2 to cross the river on foot: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nYou get into the boat and begin to paddle across the river.\n");
            break;
        }
        else if(choice == 2){
            printf("\nYou decide to wade through the river on foot.\n");
            break;
        }
        else{
            printf("\nI do not understand. Please try again.\n");
        }
    }

    printf("\nAs you cross the river, you feel something grab your leg.\n");
    printf("You look down and see a giant octopus dragging you down.\n");
    printf("What will you do?\n");
    while(1){
        printf("Enter 1 to fight the octopus, or 2 to try and escape: ");
        scanf("%d", &choice);
        if(choice == 1){
            int attack = rand() % 20 + 1; // generate random attack value
            int defense = rand() % 20 + 1; // generate random defense value
            printf("\nYou fight the octopus!\n");
            if(attack > defense){
                printf("You successfully defeat the octopus and continue on your journey.\n");
                break;
            }
            else{
                printf("The octopus is too strong for you and defeats you. Game over.\n");
                return 0;
            }
        }
        else if(choice == 2){
            printf("\nYou try to escape the octopus, but it catches you and defeats you. Game over.\n");
            return 0;
        }
        else{
            printf("\nI do not understand. Please try again.\n");
        }
    }

    printf("\nAfter all of your adventures, you finally reach the end of your journey.\n");
    printf("Congratulations, %s. You have completed the cryptic adventure game!\n", input);

    return 0;
}