//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showInstructions() {
    printf("Welcome to the Grateful Quest!\n");
    printf("In this adventure, you will explore a small village and help its inhabitants.\n");
    printf("Make your choices wisely and see how they affect your journey!\n");
    printf("You can type 'help' to see these instructions again anytime.\n");
    printf("Good luck on your quest!\n");
}

void villageEncounter() {
    int choice;
    printf("\nYou enter a small village filled with kind villagers.\n");
    printf("1. Talk to the baker\n");
    printf("2. Visit the herbalist\n");
    printf("3. Explore the forest nearby\n");
    printf("What do you want to do? (1-3): ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nThe baker greets you with a warm smile.\n");
            printf("\"Thank you for visiting! Would you like to help me gather some ingredients for my bread?\"\n");
            printf("You agree and soon find yourself in the bakery, creating delicious loaves!\n");
            break;
        case 2:
            printf("\nThe herbalist welcomes you with open arms.\n");
            printf("\"I've lost my precious herbs in the forest. Can you help me find them?\"\n");
            printf("You venture into the forest, searching high and low until you retrieve the herbs!\n");
            break;
        case 3:
            printf("\nYou decide to explore the forest. The trees whisper secrets and the wildlife is abundant.\n");
            printf("Suddenly, you hear a cry for help!\n");
            break;
        default:
            printf("\nThat's not a valid option. Please choose again.\n");
            villageEncounter();
            break;
    }
}

void forestEncounter() {
    int choice;
    printf("\nYou find a young girl trapped under a fallen branch. What do you want to do?\n");
    printf("1. Help her lift the branch\n");
    printf("2. Look for help\n");
    printf("3. Call for her parents\n");
    printf("What will you do? (1-3): ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nWith a great effort, you lift the branch and free the girl.\n");
            printf("She smiles brightly and thanks you, \"You saved me! I am forever grateful.\"\n");
            break;
        case 2:
            printf("\nYou rush to find help. It takes some time, but eventually, you return with her parents.\n");
            printf("They thank you profusely for your quick thinking.\n");
            break;
        case 3:
            printf("\nYou call for her parents, and soon they arrive. They are grateful for your concern.\n");
            break;
        default:
            printf("\nThat's not a valid option. Please choose again.\n");
            forestEncounter();
            break;
    }
}

void mainQuest() {
    printf("\nYou've encountered a grateful village and helped its people!\n");
    printf("Your acts of kindness have filled the village with joy.\n");
    printf("As a reward, the villagers thank you with a grand feast.\n");
    printf("You have completed the Grateful Quest. Thank you for playing!\n");
}

int main() {
    char input[20];

    showInstructions();

    while(1) {
        printf("\nWhat would you like to do? (type 'help' for options or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            printf("Thank you for joining the Grateful Quest! Farewell!\n");
            break;
        } else if (strcmp(input, "help") == 0) {
            showInstructions();
        } else {
            villageEncounter();
            forestEncounter();
            mainQuest();
            break; // Break after encountering to avoid looping
        }
    }

    return 0;
}