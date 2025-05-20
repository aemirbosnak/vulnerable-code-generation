//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(char* fortune) {
    printf("%s\n", fortune);
}

// Function to generate a random fortune
void generate_fortune(char* fortunes[], int num_fortunes) {
    srand(time(NULL)); // Seed the random number generator with the current time
    int index = rand_num(0, num_fortunes - 1); // Generate a random index within the array
    print_fortune(fortunes[index]); // Print the fortune at the random index
}

int main() {
    // Array of fortunes
    char* fortunes[] = {
        "You will have a successful day.",
        "A new opportunity will come your way.",
        "You will meet someone special today.",
        "Good luck will follow you throughout the day.",
        "You will receive unexpected news.",
        "A friend will reach out to you for help.",
        "You will find something you thought was lost.",
        "Someone will compliment you on your work.",
        "You will have a pleasant surprise.",
        "You will learn something new today."
    };
    
    // Number of fortunes in the array
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // Loop to generate a fortune for the user
    while (1) {
        generate_fortune(fortunes, num_fortunes);
        printf("Would you like to generate another fortune? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    
    return 0;
}