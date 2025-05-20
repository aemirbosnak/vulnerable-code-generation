//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){
    printf("Welcome to Zephyr's Epic Adventure Game!\n");
    printf("Are you ready to embark on a journey?\n");
    printf("Type 'yes' to start or 'no' to quit: ");
    
    char answer[10];
    scanf("%s", answer);
    
    if(strcmp(answer, "yes") == 0){
        printf("Great! What is your name, adventurer?\n");
        char name[50];
        scanf("%s", name);
        printf("Welcome, %s. In this adventure, you will be facing challenges and making choices that will determine your fate.\n", name);
        printf("Let's begin!\n");
        printf("\n");
        
        printf("You find yourself in a dark and mysterious forest. You can hear something rustling in the bushes. What do you do?\n");
        printf("Type 'run' to run away or 'investigate' to take a closer look: ");
        
        char choice[15];
        scanf("%s", choice);
        if(strcmp(choice, "run") == 0){
            printf("You turn and run as fast as you can, but you trip over a tree root and fall to the ground.\n");
            printf("You hear the rustling getting closer and closer. Suddenly, a wolf appears out of the bushes and attacks you.\n");
            printf("You have died.\n");
        } else if(strcmp(choice, "investigate") == 0){
            printf("You cautiously walk toward the bush, trying to see what's making the noise.\n");
            printf("As you get closer, you see a small, injured bird. What do you do?\n");
            printf("Type 'help' to try to help the bird or 'ignore' to leave it: ");
            
            char decision[10];
            scanf("%s", decision);
            if(strcmp(decision, "help") == 0){
                printf("You gently pick up the bird and examine its injuries. You see that its wing is broken.\n");
                printf("You use some sticks and twine to create a makeshift splint for the bird's wing, and then you set it free.\n");
                printf("The bird flies away, and you feel proud of yourself for helping a creature in need.\n");
                printf("You continue on your journey.\n");
            } else if(strcmp(decision, "ignore") == 0){
                printf("You turn and walk away from the bird, feeling a twinge of guilt in your heart.\n");
                printf("You continue on your journey, but the bird's cries stay with you for a long time.\n");
            } else {
                printf("That's not a valid choice.\n");
            }
        } else {
            printf("That's not a valid choice.\n");
        }
    } else if(strcmp(answer, "no") == 0){
        printf("That's too bad. Maybe next time.\n");
    } else {
        printf("I didn't understand your answer. Please try again.\n");
    }
    
    printf("Thanks for playing Zephyr's Epic Adventure Game!\n");
    return 0;
}