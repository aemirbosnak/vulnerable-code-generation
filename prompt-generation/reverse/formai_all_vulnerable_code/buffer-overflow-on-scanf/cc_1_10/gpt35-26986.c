//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[20];
    int age;
    char answer[5];
    int score = 0;

    printf("Welcome to the Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s! How old are you? ", name);
    scanf("%d", &age);

    printf("\n%s, you are now on an adventure in a magical forest.\n", name);
    printf("You hear a sound in the distance. Do you investigate? (yes/no): ");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0){
        printf("You follow the sound and come across a group of elves. They are shy and quickly run away when they see you.\n");
        score += 10;
    }
    else{
        printf("You decide to stay put and rest. Nothing happens.\n");
    }

    printf("\nYou come across a fork in the path. Which way do you go? (left/right): ");
    scanf("%s", answer);

    if(strcmp(answer, "left") == 0){
        printf("You travel down the left path and come across a beautiful waterfall. You feel refreshed and continue on your adventure.\n");
        score += 20;
    }
    else{
        printf("You travel down the right path and come across a pack of wolves. They chase you, but you are able to outrun them.\n");
        score -= 10;
    }

    printf("\nAs you walk, you come across a cave. Do you enter? (yes/no): ");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0){
        printf("You enter the cave and find a treasure chest. Inside, you find gold coins and jewels. Congratulations!\n");
        score += 50;
    }
    else{
        printf("You decide to avoid the cave and continue on your adventure.\n");
    }

    printf("\n%s, your adventure is now over. You scored %d points. Thanks for playing!\n", name, score);

    return 0;
}