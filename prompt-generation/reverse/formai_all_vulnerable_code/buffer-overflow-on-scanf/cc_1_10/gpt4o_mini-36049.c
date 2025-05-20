//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void print_intro() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I can reveal your fortune for today. Just ask!\n");
    printf("Press ENTER to get your fortune...\n");
}

void get_fortune(char fortune[][100], int index) {
    printf("Your fortune: %s\n", fortune[index]);
}

int main() {
    char fortunes[NUM_FORTUNES][100] = {
        "You will find great joy in unexpected places.",
        "A friend will soon reveal a secret to you.",
        "Happiness is just around the corner.",
        "Beware of those who are not what they seem.",
        "An old family friend will bring good news.",
        "Your hard work will soon pay off in a big way.",
        "Adventure awaits you; embrace it boldly.",
        "You will soon embark on a journey that will change your life.",
        "Love is on the horizon; keep your heart open.",
        "A surprise gift is coming your way."
    };

    int user_input;
    srand(time(NULL)); // Seed the random number generator

    print_intro(); // Print the introduction

    // Wait for user to press ENTER
    getchar();
    
    // Generate a random index to get a fortune
    int random_index = rand() % NUM_FORTUNES;

    // Display the fortune
    get_fortune(fortunes, random_index);

    printf("\nThank you for visiting the Automated Fortune Teller!\n");
    printf("Press 1 to get another fortune or 0 to exit: ");
    
    // Loop for getting additional fortunes
    while (1) {
        scanf("%d", &user_input);
        
        if (user_input == 1) {
            random_index = rand() % NUM_FORTUNES;
            get_fortune(fortunes, random_index);
            printf("Press 1 to get another fortune or 0 to exit: ");
        } else if (user_input == 0) {
            printf("Goodbye! May your day be filled with positive energy!\n");
            break;
        } else {
            printf("Invalid input. Please enter 1 to continue or 0 to exit: ");
        }
    }
    
    return 0;
}