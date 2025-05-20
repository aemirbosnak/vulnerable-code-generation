//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayWelcome() {
    printf("Welcome to The Tranquil Forest Adventure!\n");
    printf("You find yourself standing at the edge of a serene forest.\n");
    printf("The sun peeks through the leaves, creating a calming atmosphere.\n");
    printf("What would you like to do?\n\n");
}

void displayMenu() {
    printf("1. Enter the forest\n");
    printf("2. Sit and meditate\n");
    printf("3. Leave the forest\n");
    printf("Enter your choice (1-3): ");
}

void enterForest() {
    printf("\nYou step into the forest, feeling the soft moss under your feet.\n");
    printf("As you walk, you hear birds chirping, and a gentle breeze brushes against you.\n");
    printf("You approach a fork in the path.\n");
    printf("Do you want to:\n");
    printf("1. Go left towards the river\n");
    printf("2. Go right towards the hill\n");
    printf("3. Go back to the entrance\n");
}

void visitRiver() {
    printf("\nYou walk towards the soothing sound of the river.\n");
    printf("The water sparkles in the sunlight, and you feel the tranquility embrace you.\n");
    printf("You find a small boat on the riverbank. Do you want to:\n");
    printf("1. Row the boat\n");
    printf("2. Sit by the shore and relax\n");
    printf("3. Return to the forest path\n");
}

void rowBoat() {
    printf("\nYou gently row the boat across the river, enjoying the calm waters.\n");
    printf("As you reach the other side, you notice a hidden path through the trees.\n");
    printf("Do you want to:\n");
    printf("1. Explore the hidden path\n");
    printf("2. Return to the riverbank\n");
}

void relaxByShore() {
    printf("\nYou sit by the shore, listening to the rhythmic flow of the river.\n");
    printf("You close your eyes and feel the peace of nature surrounding you.\n");
    printf("After some time, you open your eyes and decide to:\n");
    printf("1. Go back to the forest path\n");
    printf("2. Swim in the river\n");
}

void visitHill() {
    printf("\nYou head towards the hill and begin your ascent.\n");
    printf("The view from the top is stunning, with the forest sprawling beneath you.\n");
    printf("Do you want to:\n");
    printf("1. Enjoy the view\n");
    printf("2. Go back down to the forest path\n");
}

void enjoyView() {
    printf("\nYou sit down and take in the breathtaking scenery.\n");
    printf("This peaceful moment fills you with joy and contentment.\n");
    printf("After a while, you feel ready to:\n");
    printf("1. Head back down\n");
    printf("2. Explore the surroundings at the top\n");
}

void playAdventure() {
    int choice;

    displayWelcome();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enterForest();
                while (1) {
                    int pathChoice;
                    scanf("%d", &pathChoice);
                    if (pathChoice == 1) {
                        visitRiver();
                        while (1) {
                            int riverChoice;
                            scanf("%d", &riverChoice);
                            if (riverChoice == 1) {
                                rowBoat();
                                while (1) {
                                    int boatChoice;
                                    scanf("%d", &boatChoice);
                                    if (boatChoice == 1) {
                                        printf("\nYou explore the hidden path and discover a waterfall...\n");
                                        printf("You feel completely at peace, enjoying every moment.\n");
                                        return;
                                    } else if (boatChoice == 2) {
                                        return;
                                    }
                                }
                            } else if (riverChoice == 2) {
                                relaxByShore();
                                while (1) {
                                    int relaxChoice;
                                    scanf("%d", &relaxChoice);
                                    if (relaxChoice == 1) {
                                        return;
                                    } else if (relaxChoice == 2) {
                                        printf("\nYou swim, feeling the joy of the water enveloping you...\n");
                                        return;
                                    }
                                }
                            } else if (riverChoice == 3) {
                                enterForest();
                            }
                        }
                    } else if (pathChoice == 2) {
                        visitHill();
                        while (1) {
                            int hillChoice;
                            scanf("%d", &hillChoice);
                            if (hillChoice == 1) {
                                enjoyView();
                                while (1) {
                                    int viewChoice;
                                    scanf("%d", &viewChoice);
                                    if (viewChoice == 1) {
                                        return;
                                    } else if (viewChoice == 2) {
                                        printf("\nYou discover a flower field with colors you have never seen before...\n");
                                        return;
                                    }
                                }
                            } else if (hillChoice == 2) {
                                enterForest();
                            }
                        }
                    } else if (pathChoice == 3) {
                        printf("\nYou decide to leave the forest and take its tranquility with you.\n");
                        return;
                    }
                }
            case 2:
                printf("\nYou sit down and meditate, feeling the calming energy of the forest.\n");
                return;
            case 3:
                printf("\nYou have chosen to leave the forest. The experience stays in your heart.\n");
                return;
            default:
                printf("Please enter a valid choice (1-3).\n");
                break;
        }
    }
}

int main() {
    playAdventure();
    return 0;
}