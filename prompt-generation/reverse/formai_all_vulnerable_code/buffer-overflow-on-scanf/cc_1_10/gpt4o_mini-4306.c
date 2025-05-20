//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_intro() {
    printf("\nWelcome to Fablewood!\n");
    printf("An enchanted realm filled with mystery, magic, and adventure.\n");
    printf("You are on a quest to retrieve the Lost Amulet of Memories.\n");
    printf("Your journey begins at the edge of a dense forest.\n");
}

void print_menu() {
    printf("\nWhat would you like to do?\n");
    printf("1. Enter the forest\n");
    printf("2. Climb the nearby hill\n");
    printf("3. Check your inventory\n");
    printf("4. Exit Game\n");
}

void enter_forest() {
    printf("\nAs you step into the forest, the air becomes thick with magic.\n");
    printf("You hear sounds of rustling leaves and distant howls.\n");
    printf("Suddenly, a shimmering fairy appears before you!\n");
    printf("She offers to guide you deeper into the forest if you can answer her riddle.\n");
    
    char answer[50];
    printf("Riddle: I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I? ");
    fgets(answer, sizeof(answer), stdin);
    
    if (strncmp(answer, "echo", 4) == 0) {
        printf("The fairy giggles with delight and leads you further into the mystical woods.\n");
        printf("You find a treasure chest! You've gained the 'Key of Whispers'.\n");
    } else {
        printf("The fairy frowns and vanishes into the lush greenery.\n");
    }
}

void climb_hill() {
    printf("\nYou climb the hill and are greeted by a breathtaking view of Fablewood.\n");
    printf("In the distance, you can see a castle and the peak of a mountain which looks ominous.\n");
    printf("While enjoying the view, a gust of wind knocks you off balance! Roll a die to see your fate.\n");
    
    int die = rand() % 6 + 1;
    if (die <= 3) {
        printf("You rolled a %d! You stumble and fall down the hill, losing some courage.\n", die);
    } else {
        printf("You rolled a %d! You regain your balance and find a magic stone on the ground.\n", die);
        printf("You've gained the 'Stone of Resilience'.\n");
    }
}

void check_inventory(int *courage, char *inventory) {
    printf("\nYour current inventory contains: %s\n", inventory);
    printf("Courage Level: %d\n", *courage);
}

int main() {
    int choice;
    int courage = 10;
    char inventory[100] = "Key of Whispers, Stone of Resilience";

    print_intro();
    
    while (1) {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                enter_forest();
                break;
            case 2:
                climb_hill();
                break;
            case 3:
                check_inventory(&courage, inventory);
                break;
            case 4:
                printf("Thank you for playing! May your adventures be filled with magic!\n");
                exit(0);
            default:
                printf("Invalid choice. Please pick an option between 1 and 4.\n");
                break;
        }
    }

    return 0;
}