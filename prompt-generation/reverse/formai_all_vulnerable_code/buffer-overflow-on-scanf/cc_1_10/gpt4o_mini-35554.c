//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

const char *fortunes[NUM_FORTUNES] = {
    "You will find great fortune in unexpected places.",
    "A thrilling time is in your immediate future.",
    "Your hard work will soon pay off.",
    "Love is just around the corner; keep your eyes open!",
    "An old friend will re-enter your life.",
    "A new opportunity will arise when you least expect it.",
    "You will soon embark on a journey that will change your life.",
    "Your positive energy will attract good luck.",
    "Great success is headed your way; stay focused!",
    "Adventure is out there; embrace the unknown."
};

void show_intro() {
    printf("=====================================\n");
    printf("        C Automated Fortune Teller   \n");
    printf("          By Your Name              \n");
    printf("=====================================\n");
    printf("Welcome to the automated fortune teller.\n");
    printf("Get ready to receive your fortune!\n");
}

void show_fortune(int index) {
    printf("Your fortune: %s\n", fortunes[index]);
}

void ask_replay() {
    char response;
    printf("Would you like to receive another fortune? (y/n): ");
    scanf(" %c", &response);
    
    if(response == 'y' || response == 'Y') {
        return;
    }
    else {
        printf("Thank you for visiting the Fortune Teller. Goodbye!\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    show_intro();

    while (1) {
        int random_index = rand() % NUM_FORTUNES; // Select a random fortune
        show_fortune(random_index);
        ask_replay();
    }

    return 0;
}