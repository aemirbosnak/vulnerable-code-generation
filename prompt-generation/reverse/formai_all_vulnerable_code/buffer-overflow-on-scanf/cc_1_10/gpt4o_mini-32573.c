//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_intro() {
    printf("Welcome to 'The Whispering Shadows'.\n");
    printf("In this introspective text-based adventure, you will explore the depths of your own thoughts.\n");
    printf("Make choices that shape your journey and reveal the hidden corners of your mind.\n");
    printf("Press [Enter] to begin...\n");
    getchar();
}

void choice_narration(int choice) {
    switch (choice) {
        case 1:
            printf("You decide to explore the dark forest filled with shadows. Each step echoes with whispers of memories long forgotten.\n");
            break;
        case 2:
            printf("You choose to enter the old library, a place where knowledge intertwines with nostalgia.\n");
            break;
        case 3:
            printf("You find yourself at the edge of a tranquil lake, its surface reflecting the sky, like your own thoughts waiting to materialize.\n");
            break;
        default:
            printf("Your mind wanders, and you lose track of time in this introspective journey.\n");
            break;
    }
}

void explore_forest() {
    printf("In the dark forest, you encounter a strange figure that seems to hold your past. Do you:\n");
    printf("1. Approach the figure \n");
    printf("2. Run away in fear\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely approach. The figure reveals memories, both cherished and painful. You reflect on their impact.\n");
    } else {
        printf("You run from the figure but the shadows follow you, whispering insecurities.\n");
    }
}

void explore_library() {
    printf("The library is filled with towering shelves and dusty tomes. A single book glows softly, drawing your attention. Do you:\n");
    printf("1. Open the glowing book\n");
    printf("2. Search for something familiar\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You open the book and find your own story written within its pages. You begin to question your own narrative.\n");
    } else {
        printf("You search for a familiar book, finally finding one that takes you back to childhood. It brings a comforting warmth to your heart.\n");
    }
}

void explore_lake() {
    printf("At the tranquil lake, the water beckons you. Do you:\n");
    printf("1. Sit by the shore and reflect\n");
    printf("2. Dive into the water\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You sit by the shore, letting the calmness wash over you, realizing the importance of self-reflection.\n");
    } else {
        printf("You dive into the water, cleansing yourself of past regrets. You emerge renewed, ready to face the world.\n");
    }
}

int main() {
    int choice;
    
    display_intro();
    
    printf("Where would you like to journey? Choose:\n");
    printf("1. The Dark Forest\n");
    printf("2. The Old Library\n");
    printf("3. The Tranquil Lake\n");
    printf("Choice: ");
    
    scanf("%d", &choice);
    
    choice_narration(choice);
    
    switch (choice) {
        case 1:
            explore_forest();
            break;
        case 2:
            explore_library();
            break;
        case 3:
            explore_lake();
            break;
        default:
            printf("Your choice leads to an undefined path, reflecting the uncertainty of life.\n");
            break;
    }

    printf("\nThank you for playing 'The Whispering Shadows'. Remember, the journey within is just as important as the one outside.\n");
    
    return 0;
}