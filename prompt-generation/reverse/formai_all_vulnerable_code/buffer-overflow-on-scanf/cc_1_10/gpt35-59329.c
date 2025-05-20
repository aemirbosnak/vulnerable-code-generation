//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Function to generate random number within a range */
int getRandomNum(int min, int max){
    return (rand() % (max - min + 1) + min);
}

int main(){
    /* Initializing variables and structures */
    int choice, guess, attempts = 0;
    char name[20], answer[2];
    srand(time(NULL));
    
    /* Introduction and prompt user's name */
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nHello %s! Would you like to enter the Haunted House? (y/n): ", name);
    scanf("%s", answer);
    printf("\n");
    
    /* Starting the game */
    if(strcmp(answer,"y") == 0){
        do{
            printf("You have entered a dark and abandoned house...\n");
            printf("You see two rooms in front of you. Which one do you choose? (1 or 2): ");
            scanf("%d", &choice);
            printf("\n");
            
            /* Room 1 */
            if(choice == 1){
                printf("You enter a room with a coffin in the center...\n");
                printf("Do you want to open the coffin? (y/n): ");
                scanf("%s", answer);
                printf("\n");
                
                /* Open coffin? */
                if(strcmp(answer,"y") == 0){
                    printf("As you lift the lid of the coffin, you see a skeleton...\n");
                    printf("Suddenly, the skeleton comes to life and attacks you!\n");
                    printf("You have been killed by the skeleton...\n");
                    printf("GAME OVER\n");
                    break;
                } else {
                    printf("You leave the room and enter a hallway...\n");
                }
            }
            
            /* Room 2 */
            if(choice == 2){
                printf("You enter a room with a mirror on the wall...\n");
                printf("As you approach the mirror, you see a ghostly figure behind you...\n");
                printf("Do you want to turn around? (y/n): ");
                scanf("%s", answer);
                printf("\n");
                
                /* Turn around? */
                if(strcmp(answer,"y") == 0){
                    printf("As you turn around, you see a ghostly figure floating in the air...\n");
                    printf("The ghostly figure attacks you!\n");
                    printf("You have been killed by the ghost...\n");
                    printf("GAME OVER\n");
                    break;
                } else {
                    printf("You leave the room and enter a hallway...\n");
                }
            }
            
            /* Hallway */
            printf("You hear strange noises coming from behind a door...\n");
            printf("Do you want to open the door? (y/n): ");
            scanf("%s", answer);
            printf("\n");
            
            /* Open door? */
            if(strcmp(answer,"y") == 0){
                printf("As you open the door, you see a stairway leading downwards...\n");
                printf("You start to walk down the stairs...\n\n");
                
                /* Guess the number game */
                printf("You enter a room with a chest in the corner...\n");
                printf("As you get closer to the chest, you notice there is a lock...\n");
                printf("You see a clue on the wall: 'I am a number between 1 and 20'...\n");
                int answerNum = getRandomNum(1,20);
                do {
                    printf("Guess the number: ");
                    scanf("%d", &guess);
                    attempts++;
                    if(guess < answerNum){
                        printf("The number is higher!\n");
                    } else if(guess > answerNum){
                        printf("The number is lower!\n");
                    } else {
                        printf("Congratulations! You have unlocked the chest!\n");
                    }
                } while(guess != answerNum);
                
                /* Endgame */
                printf("\nYou open the chest and find a key inside...\n");
                printf("You take the key and use it to open the front door...\n");
                printf("You have escaped the Haunted House!\n");
                printf("GAME OVER\n");
                printf("Total attempts: %d\n", attempts);
                
            } else {
                printf("You turn around and enter a room...\n\n");
            }
            
        } while(1);
        
    } else {
        printf("Goodbye then!\n");
    }
    
    return 0;
}