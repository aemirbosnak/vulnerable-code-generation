//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    char answer[6];
    int score = 0;

    printf("Welcome to the Happy Adventure Game! What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! How old are you?\n", name);
    scanf("%d", &age);

    if (age < 18) {
        printf("Sorry, %s. You are too young to play this game.\n", name);
        return 0;
    }

    printf("Great! Let's get started.\n");
    printf("You wake up in a sunny field. \n");
    printf("You notice a path leading to the east and a path leading to the west. Which path do you take? (east/west)\n");
    scanf("%s", answer);

    if (strcmp(answer, "west") == 0) {
        printf("You encounter a friendly unicorn named Sparkles who gives you a magical gem. (+1 point)\n");
        score++;
    } else if (strcmp(answer, "east") == 0) {
        printf("You walk towards the east and see a beautiful rainbow in the distance. (+1 point)\n");
        score++;
    } else {
        printf("Invalid input. You stumble and lose your sense of direction. (-1 point)\n");
        score--;
    }

    printf("You continue on your journey and come across a river. What do you do? (swim/jump/turn back))\n");
    scanf("%s", answer);

    if (strcmp(answer, "swim") == 0 || strcmp(answer, "jump") == 0) {
        printf("You made it across the river safely. (+1 point)\n");
        score++;
    } else if (strcmp(answer, "turn back") == 0) {
        printf("You turn back and have to start from the beginning. (-1 point)\n");
        score--;
    } else {
        printf("Invalid input. You take a wrong step and fall into the river. (-1 point)\n");
        score--;
    }

    printf("You are almost at the end of your journey when you spot a treasure chest. What do you do? (open/leave it)\n");
    scanf("%s", answer);

    if (strcmp(answer, "open") == 0) {
        printf("Congratulations, you found a treasure! (+2 points)\n");
        score += 2;
    } else if (strcmp(answer, "leave") == 0) {
        printf("You decide to leave the chest and continue on. (-1 point)\n");
        score--;
    } else {
        printf("Invalid input. The chest explodes and you lose a life. (-2 points)\n");
        score -= 2;
    }

    printf("Your journey has come to an end. You scored %d points. Thanks for playing %s!\n", score, name);

    return 0;
}