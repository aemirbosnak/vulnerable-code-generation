//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Function prototypes
void display_intro();
void get_fortune();
void draw_fortune(int fortune_index);

const char *fortunes[NUM_FORTUNES] = {
    "You will have a great day!",
    "Adventure awaits you around the corner.",
    "You will encounter a pleasant surprise!",
    "A new opportunity is in your near future.",
    "An old friend will make contact soon.",
    "Expect the unexpected!",
    "Your hard work will soon pay off.",
    "You will be the architect of your own destiny.",
    "Believe in yourself and good things will follow.",
    "A financial opportunity will arise, seize it!"
};

int main() {
    int user_choice;
    
    // Seed the random number generator
    srand(time(NULL));
    
    display_intro();
    
    do {
        get_fortune();
        
        printf("Would you like to get another fortune? (1 for yes, 0 for no): ");
        scanf("%d", &user_choice);
        
    } while (user_choice == 1);
    
    printf("Thank you for visiting the Fortune Teller. Goodbye!\n");
    
    return 0;
}

void display_intro() {
    printf("*****************************************\n");
    printf("*          Welcome to the Fortune      *\n");
    printf("*              Teller Program           *\n");
    printf("*****************************************\n");
    printf("Get ready to uncover the mysteries of your future!\n");
}

void get_fortune() {
    int fortune_index = rand() % NUM_FORTUNES; // Randomize fortune selection
    draw_fortune(fortune_index); // Display the selected fortune
}

void draw_fortune(int fortune_index) {
    printf("Your fortune:\n");
    printf("\"%s\"\n", fortunes[fortune_index]);
    printf("*****************************************\n");
}