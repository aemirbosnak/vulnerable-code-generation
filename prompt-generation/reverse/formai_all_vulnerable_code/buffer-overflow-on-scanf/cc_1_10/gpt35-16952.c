//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void choosePath(int choice);
void narrateGame();
void forest();
void lake();
void meadow();
void village();
void gameOver();

int main() {
    narrateGame();
    return 0;
}

void choosePath(int choice) {
    switch(choice) {
        case 1:
            forest();
            break;
        case 2:
            lake();
            break;
        case 3:
            meadow();
            break;
        case 4:
            village();
            break;
        default:
            printf("Invalid choice! Please choose a path between 1-4.\n");
            int newChoice;
            scanf("%d", &newChoice);
            choosePath(newChoice);
    }
}

void narrateGame() {
    printf("Welcome to the peaceful adventure game!\n");
    printf("You find yourself standing in the middle of a forest.\n");
    printf("You notice paths leading to a lake, a meadow, and a village.\n");
    printf("Which path will you take?\n");
    printf("1. The forest path.\n");
    printf("2. The lake path.\n");
    printf("3. The meadow path.\n");
    printf("4. The village path.\n");
    int choice;
    scanf("%d", &choice);
    choosePath(choice);
}

void forest() {
    printf("You walked through the forest and stumbled upon a cabin.\n");
    printf("You knock on the door and an old man answers.\n");
    printf("He invites you in and offers you some tea.\n");
    printf("After a pleasant conversation, you decide to continue your journey.\n");
    printf("Which path will you take now?\n");
    printf("1. The lake path.\n");
    printf("2. The meadow path.\n");
    printf("3. The village path.\n");
    int choice;
    scanf("%d", &choice);
    choosePath(choice);
}

void lake() {
    printf("You arrive at a lake and marvel at the serene and peaceful surroundings.\n");
    printf("You decide to rest by the lake for a while.\n");
    printf("After a few minutes, you notice a fisherman nearby.\n");
    printf("You strike up a conversation and he offers you a fishing rod.\n");
    srand(time(NULL));
    if(rand()%2 == 0) {
        printf("You catch a big fish and enjoy a delicious meal with the fisherman.\n");
    } else {
        printf("You don't catch anything but still enjoy the peaceful surroundings.\n");
    }
    printf("Which path will you take now?\n");
    printf("1. The forest path.\n");
    printf("2. The meadow path.\n");
    printf("3. The village path.\n");
    int choice;
    scanf("%d", &choice);
    choosePath(choice);
}

void meadow() {
    printf("You come across a beautiful meadow filled with wildflowers.\n");
    printf("You lay down and enjoy the peaceful scenery.\n");
    printf("After a while, you notice a butterfly resting on your hand.\n");
    printf("You watch in awe as it flutters its wings and takes flight.\n");
    printf("Which path will you take now?\n");
    printf("1. The forest path.\n");
    printf("2. The lake path.\n");
    printf("3. The village path.\n");
    int choice;
    scanf("%d", &choice);
    choosePath(choice);
}

void village() {
    printf("You arrive at a peaceful village and see the locals going about their daily lives.\n");
    printf("You decide to explore the village and learn about their culture.\n");
    printf("You meet the local blacksmith and admire his excellent craftsmanship.\n");
    printf("After a day of exploration, you decide to head back home.\n");
    printf("Congratulations! You have completed the peaceful adventure game!\n");
}

void gameOver() {
    printf("Game over! You failed to complete the peaceful adventure game.");
}