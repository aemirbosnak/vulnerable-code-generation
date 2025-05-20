//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main() {
    char name[20], choiceOne, choiceTwo;
    int score = 0;
    
    printf("Welcome to the Cryptic Adventure Game! Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s. Are you ready to begin your adventure? (y/n)\n", name);
    scanf(" %c", &choiceOne);
    
    if (choiceOne == 'y' || choiceOne == 'Y') {
        printf("Fantastic! You find yourself standing at the entrance of a dark, foreboding cave. Do you:\n");
        printf("A) Enter the cave.\n");
        printf("B) Turn back and leave.\n");
        scanf(" %c", &choiceTwo);
        
        if (choiceTwo == 'A' || choiceTwo == 'a') {
            printf("You enter the cave, and your eyes slowly adjust to the dark. You make out two passages before you. Do you:\n");
            printf("A) Take the left passage.\n");
            printf("B) Take the right passage.\n");
            scanf(" %c", &choiceTwo);
            
            if (choiceTwo == 'A' || choiceTwo == 'a') {
                printf("You follow the left passage, and it leads you deeper into the cave. Suddenly, you hear a loud noise!\n");
                printf("A) Investigate the noise.\n");
                printf("B) Run back the way you came.\n");
                scanf(" %c", &choiceTwo);
                
                if (choiceTwo == 'A' || choiceTwo == 'a') {
                    printf("You cautiously approach the source of the noise, and you find a pile of treasure!\n");
                    printf("You've won the game! Congratulations, %s! Your score is %d.\n", name, score + 1);
                } else {
                    printf("You turn and run back the way you came, stumbling through the darkness. You eventually make it back to the entrance, but you didn't win the game. Try again!\n");
                }
            } else {
                printf("You follow the right passage, but it suddenly forks into two more passages. Do you:\n");
                printf("A) Take the left passage.\n");
                printf("B) Take the right passage.\n");
                scanf(" %c", &choiceTwo);
                
                if (choiceTwo == 'A' || choiceTwo == 'a') {
                    printf("You follow the left passage, but it soon dead-ends in a wall. You're trapped!\n");
                    printf("You didn't win the game, but you can try again.\n");
                } else {
                    printf("You follow the right passage, and it leads you to a small room. Congratulations, %s! You've found a game map. Your score is now %d.\n", name, score + 1);
                    printf("You didn't win the game yet. The game continues...\n");
                    
                    printf("You find yourself in a large, sandy desert. In the distance, you see a town. Do you:\n");
                    printf("A) Walk towards the town.\n");
                    printf("B) Stay in the desert.\n");
                    scanf(" %c", &choiceTwo);
                    
                    if (choiceTwo == 'A' || choiceTwo == 'a') {
                        printf("You walk towards the town, but as you near it, you see that it's abandoned. In the center of the town square is a strange statue. Do you:\n");
                        printf("A) Investigate the statue.\n");
                        printf("B) Leave the town.\n");
                        scanf(" %c", &choiceTwo);
                        
                        if (choiceTwo == 'A' || choiceTwo == 'a') {
                            printf("You approach the statue, and as you get closer, you realize it's not a statue at all... it's alive!\n");
                            printf("You're in a fight for your life! Rolling the dice...\n");
                            int roll = rand() % 6 + 1;
                            if (roll >= 4) {
                                printf("You win the fight! Congratulations, %s! Your score is now %d.\n", name, score + 1);
                            } else {
                                printf("You lose the fight. Game over.\n");
                            }
                        } else {
                            printf("You turn and leave the town. As you walk away, you hear strange noises coming from behind you...\n");
                            printf("You didn't win the game, but you can try again!\n");
                        }
                    } else {
                        printf("You stay in the desert, but as night falls, you realize you made a mistake. Do you:\n");
                        printf("A) Stay where you are.\n");
                        printf("B) Try to find the town.\n");
                        scanf(" %c", &choiceTwo);
                        
                        if (choiceTwo == 'A' || choiceTwo == 'a') {
                            printf("You stay where you are, and eventually, you succumb to the harsh conditions of the desert. Game over.\n");
                        } else {
                            printf("You try to find the town, and after a long and treacherous journey, you finally arrive. Congratulations, %s! Your score is now %d.\n", name, score + 1);
                            printf("The game is not over yet, %s. The game continues...\n", name);
                        }
                    }
                }
            }
        } else {
            printf("You turn and leave the cave. The game is not over yet, %s. The adventure continues...\n", name);
        }
    } else {
        printf("That's too bad. The Cryptic Adventure Game is waiting for you whenever you're ready, %s!\n", name);
    }
    
    return 0;
}