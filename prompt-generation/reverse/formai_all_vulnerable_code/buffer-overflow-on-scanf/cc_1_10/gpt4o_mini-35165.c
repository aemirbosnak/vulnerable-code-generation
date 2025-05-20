//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("------------------------------------------------\n");
    printf("       Welcome to the Haunted House Simulator!\n");
    printf("------------------------------------------------\n");
    printf("Prepare yourself for a thrilling adventure...\n");
    printf("Will you uncover the secrets within, or will you flee in terror?\n");
    printf("------------------------------------------------\n");
}

void corridor(int *health) {
    printf("You stand in a dimly lit corridor... the air is cold.\n");
    printf("Suddenly, you hear a strange noise coming from the shadows!\n");
    printf("Do you want to:\n");
    printf("1. Investigate the noise\n");
    printf("2. Run away! (Go back to Entrance)\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You bravely step into the shadows...\n");
        int danger = rand() % 2;
        if (danger == 0) {
            printf("A ghost appears! It's friendly and guides you deeper into the house.\n");
            (*health) += 20;
            printf("Your health is now: %d\n", *health);
        } else {
            printf("A zombie jumps out and attacks you!\n");
            (*health) -= 30;
            printf("You fought back bravely, but your health is now: %d\n", *health);
        }
    } else {
        printf("You run back to the entrance, shaking!\n");
    }
}

void room(int *health) {
    printf("You've entered a room filled with old furniture and dust.\n");
    printf("A creepy painting catches your eye.\n");
    printf("Do you want to:\n");
    printf("1. Look closer at the painting\n");
    printf("2. Search the room\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("As you approach the painting, it starts to move!\n");
        int surprise = rand() % 2;
        if (surprise == 0) {
            printf("The painting reveals a hidden door!\n");
        } else {
            printf("The painting screams and you lose your grip!\n");
            (*health) -= 10;
            printf("Your health is now: %d\n", *health);
        }
    } else {
        printf("While searching the room, you find an old diary.\n");
        printf("It contains secrets of the haunted house!\n");
    }
}

void endings(int health) {
    if (health > 50) {
        printf("Congratulations! You've successfully navigated the haunted house!\n");
        printf("You are now a legend among ghost hunters!\n");
    } else {
        printf("You barely escaped the haunted house...\n");
        printf("Next time, be braver!\n");
    }
}

int main() {
    srand(time(NULL));
    int health = 100;
    int gameRunning = 1;

    welcomeMessage();

    while (gameRunning && health > 0) {
        printf("Do you want to:\n");
        printf("1. Explore the Corridor\n");
        printf("2. Enter a Room\n");
        printf("3. Exit the game\n");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                corridor(&health);
                break;
            case 2:
                room(&health);
                break;
            case 3:
                printf("Thank you for playing! Come back soon!\n");
                gameRunning = 0;
                break;
            default:
                printf("Invalid choice! Choose again!\n");
                break;
        }

        printf("Your current health: %d\n", health);
        if (health <= 0) {
            printf("You've succumbed to the fright! Game over!\n");
            gameRunning = 0;
        }
    }

    endings(health);
    return 0;
}