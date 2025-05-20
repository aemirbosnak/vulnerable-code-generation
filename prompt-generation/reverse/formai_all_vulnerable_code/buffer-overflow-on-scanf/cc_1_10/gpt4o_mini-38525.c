//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void display_intro() {
    printf("Welcome to 'Love Quest: A Journey to Lily's Heart'!\n");
    printf("You are Alex, on a quest to win the heart of the beautiful Lily.\n");
    printf("Choose wisely, as each decision you make will shape your future.\n");
    printf("Let's begin your romantic adventure!\n\n");
}

void display_choices(const char *prompt, const char *option1, const char *option2, const char *option3) {
    printf("%s\n", prompt);
    printf("1. %s\n", option1);
    printf("2. %s\n", option2);
    printf("3. %s\n", option3);
    printf("Please select an option (1-3): ");
}

void romance_score(int score) {
    if (score < 5) {
        printf("Lily seems distant... You need to try harder.\n");
    } else if (score < 10) {
        printf("Lily is smiling! You're making progress.\n");
    } else {
        printf("Lily's heart is yours! You've won her love!\n");
    }
}

int main() {
    int choice;
    int score = 0;
    char name[30];

    // Seed for random numbers
    srand(time(NULL));

    display_intro();
    printf("Before we start, please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    // Scene 1: First Impression
    display_choices("You see Lily at the park, enjoying a book. What will you do?", 
                    "Approach her and compliment her choice of book.", 
                    "Sit on a nearby bench and observe her.", 
                    "Walk by without saying anything.");

    scanf("%d", &choice);
    if (choice == 1) {
        score += 3;
        printf("She blushes at your compliment! Score: %d\n\n", score);
    } else if (choice == 2) {
        score += 1;
        printf("She notices you watching her. Score: %d\n\n", score);
    } else {
        score -= 2;
        printf("She doesn't notice you at all. Score: %d\n\n", score);
    }

    // Scene 2: The Surprise Gift
    display_choices("You decide to give her a surprise gift. What will you choose?", 
                    "A bouquet of her favorite flowers.", 
                    "A personalized book with a note inside.", 
                    "Nothing, save your money for now.");

    scanf("%d", &choice);
    if (choice == 1) {
        score += 4;
        printf("Her eyes light up! Score: %d\n\n", score);
    } else if (choice == 2) {
        score += 2;
        printf("She appreciates the gesture. Score: %d\n\n", score);
    } else {
        score -= 3;
        printf("She seems a bit disappointed. Score: %d\n\n", score);
    }

    // Scene 3: The Romantic Date
    display_choices("It's time for your romantic date. What will you plan?", 
                    "A candlelit dinner under the stars.", 
                    "A walk on the beach during sunset.", 
                    "A movie night at home.");

    scanf("%d", &choice);
    if (choice == 1) {
        score += 5;
        printf("The dinner is magical! Score: %d\n\n", score);
    } else if (choice == 2) {
        score += 3;
        printf("They shared laughs and stories! Score: %d\n\n", score);
    } else {
        score += 1;
        printf("It was nice, but not very memorable. Score: %d\n\n", score);
    }

    // Final Scene: The Confession
    printf("It's time to confess your feelings for Lily.\n");
    printf("After spending beautiful moments together, you take her hand and say...\n");
    printf("'%s, I have feelings for you! Will you be my girlfriend?'\n", name);
    
    // Make a final decision based on score
    if (score >= 10) {
        printf("Lily smiles and says 'Yes!' You both embrace, and the world fades away.\n");
    } else if (score >= 5) {
        printf("Lily says, 'I really enjoy our time together, let’s see where this goes.'\n");
    } else {
        printf("Lily gently declines, saying she values your friendship.\n");
    }
    
    printf("Thank you for playing 'Love Quest: A Journey to Lily's Heart'!\n");
    
    return 0;
}