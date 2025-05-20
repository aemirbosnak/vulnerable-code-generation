//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in front of an old, decrepit mansion.\n");
    printf("Do you want to enter? (Y/N) ");
    
    char choice;
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("You cautiously push open the creaky door and step into the dimly lit entrance hall.\n");
        
        delay(2);
        printf("Suddenly, you hear a loud bang from upstairs!\n");
        printf("Do you want to investigate? (Y/N) ");

        char choice2;
        scanf("%s", &choice2);

        if (choice2 == 'Y' || choice2 == 'y') {
            printf("You slowly climb the stairs, trying to make as little noise as possible.\n");
            
            delay(2);
            printf("As you reach the top of the stairs, you feel a cold blast of air.\n");
            printf("Do you want to turn back? (Y/N) ");

            char choice3;
            scanf("%s", &choice3);

            if (choice3 == 'N' || choice3 == 'n') {
                printf("You cautiously move forward and enter a dark hallway.\n");

                delay(2);
                printf("Suddenly, you hear a child's voice giggling.\n");
                printf("Do you want to follow the sound? (Y/N) ");

                char choice4;
                scanf("%s", &choice4);

                if (choice4 == 'Y' || choice4 == 'y') {
                    printf("You follow the sound and arrive at a door.\n");
                    printf("Do you want to open it? (Y/N) ");

                    char choice5;
                    scanf("%s", &choice5);

                    if (choice5 == 'Y' || choice5 == 'y') {
                        printf("You open the door, and find a small child playing with a doll on a rocking chair.\n");
                        printf("As you approach, the child turns around, revealing a white, ghostly face!\n");
                        printf("You turn around and run for your life!\n");
                    } else {
                        printf("You decide not to open the door and turn around.\n");
                        printf("As you do so, you feel a cold hand grab your shoulder!\n");
                        printf("You turn around and see a ghostly apparition floating in front of you!\n");
                        printf("You scream and run for the exit!\n");
                    }
                } else {
                    printf("You decide not to follow the sound and turn around.\n");
                    printf("As you do so, you feel a cold hand grab your shoulder!\n");
                    printf("You turn around and see a ghostly apparition floating in front of you!\n");
                    printf("You scream and run for the exit!\n");
                }
            } else {
                printf("You turn back and head down the stairs, only to find the entrance door locked!\n");
                printf("You are trapped in the haunted house forever!\n");
            }
        } else {
            printf("You decide not to investigate and turn around to leave the house.\n");
            printf("As you do so, you feel a cold hand grab your shoulder!\n");
            printf("You turn around and see a ghostly apparition floating in front of you!\n");
            printf("You scream and run for the exit!\n");
        }
    } else {
        printf("You decide not to enter the haunted house.\n");
        printf("As you turn around, you feel a cold hand grab your shoulder!\n");
        printf("You turn around and see a ghostly apparition floating in front of you!\n");
        printf("You scream and run away!\n");
    }

    return 0;
}