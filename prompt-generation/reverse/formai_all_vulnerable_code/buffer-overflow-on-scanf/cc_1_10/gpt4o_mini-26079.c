//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_intro();
void choose_path();
void encounter_frog();
void encounter_sky();
void encounter_time();
void game_over();
void victory();

int main() {
    srand(time(NULL)); // Seed random number generator
    print_intro();
    choose_path();
    return 0;
}

void print_intro() {
    printf("**************************************\n");
    printf("Welcome to the Journey of the Cabbage!\n");
    printf("In a world where vegetables talk and time flows like honey,\n");
    printf("You, a humble cabbage, must navigate your surreal garden.\n");
    printf("Choose wisely, or you may find yourself lost in the ether of dreams.\n");
    printf("**************************************\n");
}

void choose_path() {
    int choice;

    printf("You stand at a fork in the garden path.\n");
    printf("1. Take the path through the singing daisies.\n");
    printf("2. Wander down the corridor of laughing frogs.\n");
    printf("3. Follow the whispers of the sky.\n");
    printf("Choose your path (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encounter_frog();
            break;
        case 2:
            encounter_time();
            break;
        case 3:
            encounter_sky();
            break;
        default:
            printf("You have lost your way in the nacho dreams!\n");
            game_over();
            break;
    }
}

void encounter_frog() {
    int choice;
    printf("You encounter a troupe of frogs performing a ballet!\n");
    printf("1. Join their performance!\n");
    printf("2. Challenge them to a riddle!\n");
    printf("3. Just hop away.\n");
    printf("What will you do? (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You leap into the air! The frogs welcome you as you dance!\n");
        victory();
    } else if (choice == 2) {
        printf("You challenge the frog king with a riddle!\n");
        if (rand() % 2 == 0) {
            printf("The frogs are impressed! You win!\n");
            victory();
        } else {
            printf("The riddle was too tricky! You are pelted with lily pads!\n");
            game_over();
        }
    } else {
        printf("You hop away, but the frogs curse you with eternal silence.\n");
        game_over();
    }
}

void encounter_time() {
    printf("You find a clock made of lettuce spinning backward!\n");
    printf("1. Try to adjust the hands of time!\n");
    printf("2. Ask the clock for wisdom.\n");
    printf("3. Ignore it and keep walking.\n");
    
    int choice;
    printf("What will you do? (1-3): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You set the clock to midnight and a portal opens!\n");
        victory();
    } else if (choice == 2) {
        printf("The clock tells you, \"Time is but a salad of moments.\"\n");
        printf("You are enlightened! But also lost in thought.\n");
        game_over();
    } else {
        printf("Time runs away from you and you are left with no seconds!\n");
        game_over();
    }
}

void encounter_sky() {
    printf("You meet a giant floating eye in the clouds.\n");
    printf("1. Ask the eye about your destiny.\n");
    printf("2. Make shadow puppets with your hands.\n");
    printf("3. Climb up and deliver a speech.\n");
    
    int choice;
    printf("What will you do? (1-3): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The eye winks, revealing your destiny of becoming a wise salad!\n");
        victory();
    } else if (choice == 2) {
        printf("The eye is amused and offers you a cloud to rest!\n");
        victory();
    } else {
        printf("You trip and fall into the abyss of everlasting naps.\n");
        game_over();
    }
}

void game_over() {
    printf("**************************************\n");
    printf("Game Over! You have been returned to the dust of the earth.\n");
    printf("Try again, brave cabbage!\n");
    printf("**************************************\n");
    exit(0);
}

void victory() {
    printf("**************************************\n");
    printf("Congratulations! You have traversed the surreal garden!\n");
    printf("You are now the Fairy Prince or Princess of the Vegetables!\n");
    printf("The garden shall sing your praises!\n");
    printf("**************************************\n");
    exit(0);
}