//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of fortunes
#define NUM_FORTUNES 10

// Define the fortunes
char *fortunes[] = {
    "You will have good luck today.",
    "A new opportunity will come your way.",
    "You will meet someone special soon.",
    "Your hard work will pay off.",
    "A friend will offer you help when you need it most.",
    "You will receive unexpected news.",
    "You will overcome a challenge in your life.",
    "A pleasant surprise awaits you.",
    "You will experience a moment of pure joy.",
    "You will find peace in a difficult situation."
};

// Function to generate a random number
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void printFortune(int fortuneNum) {
    printf("Your fortune is:\n%s\n", fortunes[fortuneNum]);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Print a welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    
    // Ask the user how many fortunes they want
    int numFortunes;
    printf("How many fortunes would you like? ");
    scanf("%d", &numFortunes);
    
    // Generate the requested number of fortunes
    for (int i = 0; i < numFortunes; i++) {
        // Generate a random fortune
        int fortuneNum = randInt(0, NUM_FORTUNES - 1);
        
        // Print the fortune
        printFortune(fortuneNum);
        
        // Pause for a moment
        printf("\nPress enter to continue...\n");
        getchar();
    }
    
    // Print a farewell message
    printf("Thank you for using the Automated Fortune Teller!\n");
    
    return 0;
}