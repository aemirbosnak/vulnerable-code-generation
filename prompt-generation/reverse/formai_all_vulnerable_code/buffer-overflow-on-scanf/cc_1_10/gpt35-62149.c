//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char name[20];
    int age;
    char gender[7];
    char location[20];
    char answer[10];
    int score = 0;
    srand(time(NULL));

    // Introduction
    printf("Welcome to the visionary adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your gender (male/female): ");
    scanf("%s", gender);
    printf("Please enter your location: ");
    scanf("%s", location);

    printf("\n\nWelcome %s!\n", name);
    printf("You are a young and ambitious %d-year-old %s from %s.\n", age, gender, location);
    printf("Your goal is to collect a total score of 100 points or more.\n\n");

    // Part 1 - The Beach
    printf("PART 1 - THE BEACH\n");
    printf("You are on a beautiful beach, and you see a message in a bottle washed up on shore.\n");
    printf("Do you want to open it? (yes/no) ");
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        printf("The message reads: 'Travel to the island in the East to find the treasure.'\n");
        score += 30;
        printf("Your score is now %d.\n", score);
    } else {
        printf("You ignore the message and continue exploring.\n");
        score += 10;
        printf("Your score is now %d.\n", score);
    }

    // Part 2 - The Island
    printf("\nPART 2 - THE ISLAND\n");
    printf("You embark on a journey to the island in the East.\n");
    printf("After a long and treacherous journey, you finally arrive on the island.\n");
    printf("You see a fork in the road. Do you go left or right? (left/right) ");
    scanf("%s", answer);

    if (strcmp(answer, "left") == 0) {
        printf("You come across a group of hostile natives, and they attack you.\n");
        printf("You defend yourself and manage to escape, but you lose 20 points.\n");
        score -= 20;
        printf("Your score is now %d.\n", score);
    } else {
        printf("You come across a small waterfall, and you find a secret cave behind it.\n");
        printf("Inside the cave, you find a chest filled with gold and jewels.\n");
        score += 50;
        printf("Your score is now %d.\n", score);
    }

    // Part 3 - The Cave
    printf("\nPART 3 - THE CAVE\n");
    printf("You decide to explore further into the cave.\n");
    printf("You come across a deep abyss. Do you jump or turn back? (jump/turn back) ");
    scanf("%s", answer);

    if (strcmp(answer, "jump") == 0) {
        printf("You take a leap of faith and manage to grab a stalagmite protruding from the side of the abyss.\n");
        printf("You climb up and find a magical sword stuck in a rock.\n");
        score += 70;
        printf("Your score is now %d.\n", score);
    } else {
        printf("You turn back, but you get lost in the cave and lose 10 points.\n");
        score -= 10;
        printf("Your score is now %d.\n", score);
    }

    // Conclusion
    printf("\n\nCONCLUSION\n");
    printf("You emerge from the cave victorious, with a total score of %d points.\n", score);
    if (score >= 100) {
        printf("You have achieved your goal and become a legendary adventurer!\n");
    } else {
        printf("You did not achieve your goal, but you have gained valuable experience on your journey.\n");
    }

    return 0;
}