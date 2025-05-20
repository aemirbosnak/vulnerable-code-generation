//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare some mysterious fortunes
const char *fortunes[] = {
    "A shadowy figure will cross your path.",
    "The winds of change are coming your way.",
    "An unexpected gift awaits you soon.",
    "Beware of those who speak too much.",
    "Your future holds a golden opportunity.",
    "You will travel far and meet strange people.",
    "A ghost from the past will return in a dream.",
    "Fortune favors the brave but challenges the cautious.",
    "The stars are aligned for a transformation.",
    "A road less traveled will lead to great rewards.",
    "Your intuition is your guide; trust it.",
    "The answer lies in a forgotten memory.",
    "Someone close to you is not what they seem.",
    "A journey will offer you wisdom of the ages.",
    "Your sense of humor will bring joy in dark times.",
    "Tomorrow will bring a fresh perspective.",
    "Change is afoot; prepare for the unexpected.",
    "A secret admirer watches you in silence.",
    "An old friend will reach out to you.",
    "Your ambition will unlock new doors.",
    "You are the architect of your own destiny."
};

void display_welcome_message() {
    printf("========================================\n");
    printf("          Welcome to the Mystic       \n");
    printf("           Automated Fortune Teller   \n");
    printf("========================================\n");
    printf("Prepare to gaze into the crystal ball...\n");
}

int get_user_choice() {
    int choice;
    printf("Would you like to receive a fortune? (1 for Yes / 0 for No): ");
    scanf("%d", &choice);
    
    if (choice != 1 && choice != 0) {
        printf("Ah, indecision can cloud your path... Let's try again.\n");
        return get_user_choice();
    }
    return choice;
}

void read_fortune() {
    // Get current time for random seed
    srand(time(NULL));
    
    // Generate a random index to select a fortune
    int index = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));
    
    printf("Your fortune is:\n");
    printf("   '%s'\n", fortunes[index]);
}

void farewell_message() {
    printf("========================================\n");
    printf("         Until we meet again,         \n");
    printf("        may your path be clear!       \n");
    printf("========================================\n");
}

int main() {
    display_welcome_message();

    int choice = get_user_choice();
    
    if (choice == 1) {
        read_fortune();
    } else {
        printf("You have chosen wisely. May you ponder your thoughts.\n");
    }

    farewell_message();
    
    return 0;
}