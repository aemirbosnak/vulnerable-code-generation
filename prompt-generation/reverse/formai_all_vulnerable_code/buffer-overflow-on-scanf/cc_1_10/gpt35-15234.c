//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Setting up random seed
    srand(time(NULL));
    int randomNum = rand() % 10 + 1;
    int userInput;

    printf("Welcome to the Haunted House Simulator!\n\n");

    printf("You find yourself walking towards a big spooky house, do you enter? (1: Yes, 0: No)\n");
    scanf("%d", &userInput);

    if(userInput){
        printf("\nYou open the door, it creaks loudly.\nYou step inside and hear a loud thud coming from upstairs.\n");
        printf("\nDo you go upstairs to investigate? (1: Yes, 0: No)\n");
        scanf("%d", &userInput);

        if(userInput){
            printf("\nYou climb the creaky stairs and find a room with a mysterious object.\nDo you investigate the object? (1: Yes, 0: No)\n");
            scanf("%d", &userInput);

            if(userInput){
                if(randomNum > 5){
                    printf("\nThe object glows and you hear a voice saying \"You have been cursed!\"\n");
                }else{
                    printf("\nThe object glows and reveals a hidden door.\n");
                }
            }else{
                printf("\nYou leave the room and explore the rest of the house.\n");
            }
        }else{
            printf("\nYou explore the main floor and find a room with strange markings on the wall.\nDo you investigate the markings? (1: Yes, 0: No)\n");
            scanf("%d", &userInput);

            if(userInput){
                if(randomNum > 5){
                    printf("\nThe markings glow and you hear a voice saying \"You have been cursed!\"\n");
                }else{
                    printf("\nThe markings reveal a hidden passage to the basement.\n");
                }
            }else{
                printf("\nYou leave the room and explore the rest of the house.\n");
            }
        }
    }else{
        printf("\nYou decide to not enter the haunted house.\nGood choice!\n");
    }

    printf("\nThanks for playing the Haunted House Simulator!\n");

    return 0;
}