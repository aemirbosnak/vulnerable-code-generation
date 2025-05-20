//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_FORTUNES 10
#define MAX_FORTUNE_LENGTH 256

// Structure to hold a fortune
typedef struct {
    char forecast[MAX_FORTUNE_LENGTH];
} Fortune;

// Function prototypes
void generate_fortunes(Fortune fortunes[]);
void display_fortune(Fortune fortunes[], int index);
int get_random_index(int max);

int main() {
    Fortune fortunes[NUM_FORTUNES];
    int choice;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate a set of fortunes
    generate_fortunes(fortunes);
    
    // Introspective loop to ask the user for input
    while (1) {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Press 1 for your fortune or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int random_index = get_random_index(NUM_FORTUNES);
            display_fortune(fortunes, random_index);
        } else if (choice == 0) {
            printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Function to generate fortunes
void generate_fortunes(Fortune fortunes[]) {
    strcpy(fortunes[0].forecast, "You will find a hidden talent.");
    strcpy(fortunes[1].forecast, "Good news will come to you from afar.");
    strcpy(fortunes[2].forecast, "A thrilling time is in your near future.");
    strcpy(fortunes[3].forecast, "Your hard work will soon pay off.");
    strcpy(fortunes[4].forecast, "You will receive a surprise gift.");
    strcpy(fortunes[5].forecast, "An adventure is coming your way.");
    strcpy(fortunes[6].forecast, "You will meet someone special.");
    strcpy(fortunes[7].forecast, "Your patience will be rewarded.");
    strcpy(fortunes[8].forecast, "Expect the unexpected in the coming days.");
    strcpy(fortunes[9].forecast, "Your kindness will be recognized.");
}

// Function to display a fortune based on the index
void display_fortune(Fortune fortunes[], int index) {
    printf("Your fortune: %s\n", fortunes[index].forecast);
}

// Function to get a random index for the fortunes array
int get_random_index(int max) {
    return rand() % max; // Generate a random index within the bounds of the fortune list
}