//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Function declarations
void intro();
void menu();
void forest();
void river();
void mountain();
void monster();

//Global variables
int health = 100;
int gold = 0;

//Main function
int main() {
    intro();
    menu();
    return 0;
}

//Function definitions

//Intro function
void intro() {
    printf("Welcome to Adventure Game!\n");
    printf("You are stranded in the wilderness and must find your way back to civilization.\n");
    printf("You have 100 health and 0 gold.\n");
    printf("Good luck!\n\n");
}

//Menu function
void menu() {
    int choice;

    printf("Choose your path:\n");
    printf("1. Forest\n");
    printf("2. River\n");
    printf("3. Mountain\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            forest();
            break;
        case 2:
            river();
            break;
        case 3:
            mountain();
            break;
        case 4:
            printf("Thanks for playing!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            menu();
            break;
    }
}

//Forest function
void forest() {
    printf("You have entered the forest.\n");
    printf("You stumble upon a bag of gold.\n");
    gold += 50;
    printf("You gain 50 gold. You now have %d gold.\n", gold);

    printf("You hear a rustling in the bushes. Do you investigate? (y/n)\n");

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "y") == 0) {
        printf("A monster appears!\n");
        monster();
    }
    else if(strcmp(choice, "n") == 0) {
        printf("You continue on your way.\n");
        menu();
    }
    else {
        printf("Invalid choice.\n");
        forest();
    }
}

//River function
void river() {
    printf("You have arrived at the river.\n");
    printf("You see a fish in the river. Do you try to catch it? (y/n)\n");

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "y") == 0) {
        printf("You catch the fish!\n");
        gold += 20;
        printf("You gain 20 gold. You now have %d gold.\n", gold);
    }
    else if(strcmp(choice, "n") == 0) {
        printf("You ignore the fish and continue on your way.\n");
    }
    else {
        printf("Invalid choice.\n");
        river();
    }

    printf("You see a boat on the other side of the river. Do you try to swim across? (y/n)\n");

    scanf("%s", choice);

    if(strcmp(choice, "y") == 0) {
        printf("You attempt to swim across the river...\n");

        srand(time(NULL));
        int chance = rand() % 2;

        if(chance == 0) {
            printf("You make it across the river safely!\n");
            gold += 100;
            printf("You gain 100 gold. You now have %d gold.\n", gold);
        }
        else {
            printf("You are attacked by a crocodile and lose 25 health!\n");
            health -= 25;
            printf("Your health is now %d.\n", health);
            if(health <= 0) {
                printf("You have died.\n");
                exit(0);
            }
        }
    }
    else if(strcmp(choice, "n") == 0) {
        printf("You ignore the boat and continue on your way.\n");
    }
    else {
        printf("Invalid choice.\n");
        river();
    }

    menu();
}

//Mountain function
void mountain() {
    printf("You are climbing the mountain.\n");
    printf("You find a cave. Do you explore? (y/n)\n");

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "y") == 0) {
        printf("You enter the cave.\n");
        printf("You find a treasure chest!\n");

        srand(time(NULL));
        int chance = rand() % 2;

        if(chance == 0) {
            printf("You open the chest and gain 50 gold. You now have %d gold.\n", gold + 50);
            gold += 50;
        }
        else {
            printf("You open the chest and are attacked by a rock monster!\n");
            monster();
        }
    }
    else if(strcmp(choice, "n") == 0) {
        printf("You ignore the cave and continue climbing.\n");
    }
    else {
        printf("Invalid choice.\n");
        mountain();
    }

    printf("You reach the top of the mountain and see a bird flying in the distance. Do you shoot it down? (y/n)\n");

    scanf("%s", choice);

    if(strcmp(choice, "y") == 0) {
        printf("You shoot the bird down and gain 10 gold. You now have %d gold.\n", gold + 10);
        gold += 10;
    }
    else if(strcmp(choice, "n") == 0) {
        printf("You let the bird fly away peacefully.\n");
    }
    else {
        printf("Invalid choice.\n");
        mountain();
    }

    menu();
}

//Monster function
void monster() {
    srand(time(NULL));
    int chance = rand() % 2;

    if(chance == 0) {
        printf("You defeat the monster and gain 50 gold. You now have %d gold.\n", gold + 50);
        gold += 50;
    }
    else {
        printf("The monster defeats you and you lose 50 health!\n");
        health -= 50;
        printf("Your health is now %d.\n", health);
        if(health <= 0) {
            printf("You have died.\n");
            exit(0);
        }
        monster();
    }
}