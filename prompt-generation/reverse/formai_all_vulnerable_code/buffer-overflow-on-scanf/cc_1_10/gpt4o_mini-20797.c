//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_intro() {
    printf("Welcome to the Tranquil Forest Adventure!\n");
    printf("You find yourself at the edge of a gentle forest, filled with the sound of chirping birds and rustling leaves.\n");
    printf("What would you like to do? Explore the forest, rest by the brook, or climb a hill?\n");
}

void explore_forest() {
    printf("\nYou take a deep breath and step into the forest.\n");
    printf("The trees sway gently around you, and sunlight filters through the leaves.\n");
    printf("Suddenly, you see a deer standing gracefully. You can approach it or quietly observe.\n");
    char choice[20];
    scanf("%s", choice);
    
    if (strcmp(choice, "approach") == 0) {
        printf("\nYou approach the deer slowly. It allows you to come close, and you share a serene moment together.\n");
    } else if (strcmp(choice, "observe") == 0) {
        printf("\nYou quietly watch the deer as it wanders gracefully, feeling a sense of calm wash over you.\n");
    } else {
        printf("\nIndecisive, you stand still, letting the moment pass by.\n");
    }
}

void rest_by_brook() {
    printf("\nYou walk towards the gentle sound of flowing water.\n");
    printf("The brook sparkles under the sunlight, calling out to you.\n");
    printf("You can sit on the bank and relax or dip your feet in the cool water.\n");
    char choice[20];
    scanf("%s", choice);
    
    if (strcmp(choice, "sit") == 0) {
        printf("\nYou sit by the brook and close your eyes. The sound of water refreshes your spirit.\n");
    } else if (strcmp(choice, "dip") == 0) {
        printf("\nYou dip your feet into the cool water. A delightful sensation spreads through your body.\n");
    } else {
        printf("\nYou remain standing, letting the serene environment wash over you.\n");
    }
}

void climb_hill() {
    printf("\nYou decide to climb the gentle hill nearby.\n");
    printf("As you reach the top, the view of the forest stretches out before you, a sea of green and tranquility.\n");
    printf("You can sit down and enjoy the view or shout joyfully into the wind.\n");
    char choice[20];
    scanf("%s", choice);
    
    if (strcmp(choice, "sit") == 0) {
        printf("\nYou sit down and take in the breathtaking view, feeling grateful for this moment of peace.\n");
    } else if (strcmp(choice, "shout") == 0) {
        printf("\nYou shout joyfully, your voice echoed by the trees. A thrilling respite from the everyday.\n");
    } else {
        printf("\nYou simply stand there, mesmerized by the beauty around you.\n");
    }
}

int main() {
    char action[20];

    show_intro();

    while (1) {
        printf("\nWhat would you like to do next? (explore, rest, climb, quit): ");
        scanf("%s", action);
        
        if (strcmp(action, "explore") == 0) {
            explore_forest();
        } else if (strcmp(action, "rest") == 0) {
            rest_by_brook();
        } else if (strcmp(action, "climb") == 0) {
            climb_hill();
        } else if (strcmp(action, "quit") == 0) {
            printf("\nThank you for visiting the Tranquil Forest. Until next time!\n");
            break;
        } else {
            printf("\nI didn't quite understand that. Please choose explore, rest, climb, or quit.\n");
        }
    }

    return 0;
}