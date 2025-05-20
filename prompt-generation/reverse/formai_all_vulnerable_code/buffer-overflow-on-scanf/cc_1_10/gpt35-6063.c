//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that returns a random number between min and max
int random_number(int min, int max) {
    int range = max - min + 1;
    int random = rand() % range + min;
    return random;
}

// Function that generates a random fortune
void generate_fortune() {
    // Array of fortunes
    char* fortunes[] = {
        "You will find love soon.",
        "Your financial situation will improve.",
        "You will meet someone important today.",
        "You will have a great day tomorrow.",
        "Your hard work will pay off soon.",
        "You will overcome a challenge in the near future."
    };
    
    // Get a random fortune from the array
    int fortune_index = random_number(0, 5);
    char* fortune = fortunes[fortune_index];
    
    // Output the fortune to the console
    printf("\nAutomated Fortune Teller:\n%s\n", fortune);
}

// Main function
int main() {
    srand(time(NULL));  // Set the seed for the random number generator
    
    printf("---Welcome to the Automated Fortune Teller!---\n");
    
    // Repeat until the user decides to quit
    while (1) {
        printf("\nEnter '1' to generate a fortune, or '0' to quit.\n");
        
        int input;
        scanf("%d", &input);
        
        if (input == 1) {
            generate_fortune();
        } else if (input == 0) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid input. Please enter '1' or '0'.\n");
        }
    }
    
    return 0;
}