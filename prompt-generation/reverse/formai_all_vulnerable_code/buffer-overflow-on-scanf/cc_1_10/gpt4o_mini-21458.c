//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Fortune Teller struct
typedef struct {
    int id;
    char fortune[256];
} Fortune;

// Function to initialize fortunes
void initializeFortunes(Fortune fortunes[]) {
    fortunes[0].id = 1;
    snprintf(fortunes[0].fortune, sizeof(fortunes[0].fortune), "You will find unexpected joy in small things.");
    
    fortunes[1].id = 2;
    snprintf(fortunes[1].fortune, sizeof(fortunes[1].fortune), "A great opportunity is coming your way soon.");
    
    fortunes[2].id = 3;
    snprintf(fortunes[2].fortune, sizeof(fortunes[2].fortune), "Expect a pleasant surprise from a friend.");
    
    fortunes[3].id = 4;
    snprintf(fortunes[3].fortune, sizeof(fortunes[3].fortune), "Your ambitions will soon be recognized by others.");
    
    fortunes[4].id = 5;
    snprintf(fortunes[4].fortune, sizeof(fortunes[4].fortune), "Stay positive; your hard work will pay off.");
    
    fortunes[5].id = 6;
    snprintf(fortunes[5].fortune, sizeof(fortunes[5].fortune), "Beware of unexpected distractions this week.");
    
    fortunes[6].id = 7;
    snprintf(fortunes[6].fortune, sizeof(fortunes[6].fortune), "Your future is as bright as your willingness to change.");
    
    fortunes[7].id = 8;
    snprintf(fortunes[7].fortune, sizeof(fortunes[7].fortune), "The answer you seek lies in your heart.");
    
    fortunes[8].id = 9;
    snprintf(fortunes[8].fortune, sizeof(fortunes[8].fortune), "Love will find you in the most unusual place.");
    
    fortunes[9].id = 10;
    snprintf(fortunes[9].fortune, sizeof(fortunes[9].fortune), "Trust your instincts; they are leading you in the right direction.");
}

// Function to get a random fortune
void getFortune(Fortune fortunes[]) {
    srand(time(NULL)); // seed for randomness
    int randomIndex = rand() % MAX_FORTUNES; // get random index

    printf("Your fortune: %s\n", fortunes[randomIndex].fortune);
}

// Function to display menu
void displayMenu() {
    printf("*****************************************\n");
    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("*****************************************\n");
    printf("1. Get your fortune\n");
    printf("2. Exit\n");
    printf("*****************************************\n");
    printf("Please choose an option: ");
}

int main() {
    Fortune fortunes[MAX_FORTUNES];
    initializeFortunes(fortunes); // Initialize fortunes

    int choice = 0;

    do {
        displayMenu();
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1:
                getFortune(fortunes); // Fetch and display a fortune
                break;
            case 2:
                printf("Thank you for visiting! Have a great day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }

    } while (choice != 2); // Repeat until exit is chosen

    return 0;
}