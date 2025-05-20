//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You are on a quest to find the lost treasures of the mystical forest.\n");
    printf("Beware of creatures lurking in the shadows!\n");
    printf("Make your choices wisely to survive.\n\n");
    printf("Press Enter to start your adventure...");
    getchar();
}

void choose_path(int *choice) {
    printf("You stand at a crossroad with two paths ahead:\n");
    printf("1. The LEFT path winding through ancient trees.\n");
    printf("2. The RIGHT path, lined with bright flowers.\n");
    printf("Which path will you choose? (1/2): ");
    scanf("%d", choice);
}

void encounter_creature() {
    int creature = rand() % 2;
    if (creature == 0) {
        printf("You encountered a friendly elf!\n");
        printf("The elf offers you a magical potion. Do you want to take it? (1 for YES, 0 for NO): ");
        int take_potion;
        scanf("%d", &take_potion);
        if (take_potion) {
            printf("You feel energized and your health is restored!\n");
        } else {
            printf("The elf leaves you with a warning to be cautious.\n");
        }
    } else {
        printf("Oh no! A wild goblin appears!\n");
        printf("Do you want to FIGHT (1) or RUN (0)? ");
        int action;
        scanf("%d", &action);
        if (action) {
            printf("You bravely fought the goblin and emerged victorious!\n");
        } else {
            printf("You ran away and lived to fight another day.\n");
        }
    }
}

void treasure_found() {
    printf("You stumble upon a hidden treasure chest!\n");
    printf("Inside you find:\n");
    printf("- A magical sword\n");
    printf("- A golden crown\n");
    printf("- A pile of sparkling jewels\n");
    printf("Congratulations! You've found the treasures!\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice;
    intro();
    
    choose_path(&choice);
    
    if (choice == 1) {
        printf("You chose the LEFT path.\n");
        encounter_creature();
        treasure_found();
    } else if (choice == 2) {
        printf("You chose the RIGHT path.\n");
        encounter_creature();
        treasure_found();
    } else {
        printf("Invalid choice. You stand frozen in fear!\n");
    }

    printf("Thank you for playing the Enchanted Forest Adventure!\n");
    return 0;
}