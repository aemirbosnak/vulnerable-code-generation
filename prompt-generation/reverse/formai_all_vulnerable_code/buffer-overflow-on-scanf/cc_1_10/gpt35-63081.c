//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, chances = 3;
    srand(time(NULL));
    printf("Welcome to the Haunted House Simulation.\n");
    printf("You have been called to investigate a haunted house.\n");
    printf("You arrive at the front door of the old mansion and step inside.\n");
    printf("As you begin to explore the house, you suddenly hear a loud noise coming from upstairs.\n");
    printf("You decide to investigate the noise.\n");

    do {
        printf("You have %d chances left.\n", chances);
        printf("What will you do?\n");
        printf("1. Go upstairs.\n");
        printf("2. Stay on the ground floor.\n");
        printf("3. Leave the house.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You cautiously climb the stairs and find yourself in a dark hallway.\n");
                printf("As you're walking down the hall, you suddenly feel an icy chill run down your spine.\n");
                printf("A ghostly apparition appears in front of you!\n");
                if(rand() % 2) {
                    printf("You pull out your trusty revolver and shoot at the ghost, but it passes right through it.\n");
                    printf("You turn and flee back down the stairs!\n");
                    chances--;
                }
                else {
                    printf("You quickly recite an exorcism spell you learned long ago and the ghost dissipates into thin air.\n");
                    printf("You continue your search of the upstairs rooms.\n");
                }
                break;
            case 2:
                printf("You decide to stay on the ground floor.\n");
                printf("As you're walking down the hallway, you suddenly hear something creeping up behind you.\n");
                if(rand() % 2) {
                    printf("You turn around to find a zombie standing right in front of you!\n");
                    printf("With lightning reflexes, you pull out your revolver and blow its brains out.\n");
                    printf("You continue your search of the downstairs rooms.\n");
                }
                else {
                    printf("You turn around to find a vampire standing right in front of you!\n");
                    printf("You quickly recite a spell that causes the vampire to turn to dust.\n");
                    printf("You continue your search of the downstairs rooms.\n");
                }
                break;
            case 3:
                printf("You turn around and flee back to your car.\n");
                printf("As you're driving away, you realize that you'll never be able to solve the mystery of the haunted house.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(chances > 0);

    printf("You have run out of chances and failed to solve the mystery of the haunted house.\n");
    printf("Better luck next time!\n");
    return 0;
}