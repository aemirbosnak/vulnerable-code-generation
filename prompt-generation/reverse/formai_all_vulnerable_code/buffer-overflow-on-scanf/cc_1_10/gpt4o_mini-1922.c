//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_intro() {
    printf("Welcome to the Silly Adventure!\n");
    printf("You're on a quest for the Legendary Lollipop of Eternal Sweetness!\n");
    printf("Watch out for the wacky traps, crazy characters, and mind-boggling puzzles!\n");
    printf("Let the silliness begin!\n\n");
}

void show_choices() {
    printf("You find yourself in the Silly Forest. Which way do you want to go?\n");
    printf("1. Left towards the Giggle River\n");
    printf("2. Right towards the Wobbly Hills\n");
    printf("3. Straight into the Ticklish Thicket\n");
    printf("4. Back home to eat pizza (a risky choice)\n");
}

int choose_direction() {
    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);
    return choice;
}

void giggle_river() {
    printf("\nYou approach the Giggle River...\n");
    printf("The river is filled with jellyfish that crack jokes!\n");
    printf("One jellyfish asks you: 'Why did the scarecrow win an award?'\n");
    printf("What do you answer?\n");
    printf("1. Because he was outstanding in his field!\n");
    printf("2. Because he was a scarecrow!\n");
    printf("3. I don't want to talk to jellyfish!\n");
    
    int answer;
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 1) {
        printf("The jellyfish bursts into laughter and gives you a magic jelly candy!\n");
    } else if (answer == 2) {
        printf("The jellyfish feels confused and swims away.\n");
    } else {
        printf("The jellyfish starts crying while laughing...\n");
        printf("You're now stuck in an emotional jellyfish whirlpool!\n");
        exit(0);
    }
}

void wobbly_hills() {
    printf("\nYou stumble upon the Wobbly Hills...\n");
    printf("The hills are alive with the sound of music! Or is it just wobbly?\n");
    printf("Suddenly, a singing llama appears!\n");
    printf("Llama: 'If you can make me laugh, I'll let you pass!'\n");
    printf("What do you do?\n");
    printf("1. Tell a knock-knock joke\n");
    printf("2. Do a silly dance\n");
    printf("3. Offer the llama a carrot\n");
    
    int choice;
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You say: 'Knock knock!'\n");
        printf("Llama: 'Who's there?'\n");
        printf("You: 'Lettuce!'\n");
        printf("Llama: 'Lettuce in, it's freezing out here!'\n");
        printf("Llama laughs and lets you pass!\n");
    } else if (choice == 2) {
        printf("You do a silly dance and the llama giggles uncontrollably!\n");
        printf("You may proceed!\n");
    } else {
        printf("The llama snorts. 'I don't eat carrots, silly human!'\n");
        exit(0);
    }
}

void ticklish_thicket() {
    printf("\nYou bravely step into the Ticklish Thicket...\n");
    printf("This area is filled with ticklish bushes that laugh when touched!\n");
    printf("You need to solve a riddle to cross!\n");
    printf("Riddle: 'What has keys but can't open locks?'\n");
    
    char answer[20];
    printf("Your answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "piano") == 0) {
        printf("Correct! The thicket parts and you can walk through.\n");
    } else {
        printf("The bushes laugh at your silly answer!\n");
        exit(0);
    }
}

int main() {
    srand(time(0));
    show_intro();
    
    while (1) {
        show_choices();
        int direction = choose_direction();

        switch (direction) {
            case 1:
                giggle_river();
                break;
            case 2:
                wobbly_hills();
                break;
            case 3:
                ticklish_thicket();
                break;
            case 4:
                printf("You decide that pizza is more important than adventures!\n");
                printf("Game Over. Please order a pizza for your next adventure!\n");
                exit(0);
            default:
                printf("That's not a valid choice, silly goose!\n");
        }
        printf("\nDo you want to continue on your silly adventure? (1 for Yes, 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if (continue_choice == 0) {
            printf("Thanks for playing! May your days be filled with laughter and pizza!\n");
            break;
        }
    }

    return 0;
}