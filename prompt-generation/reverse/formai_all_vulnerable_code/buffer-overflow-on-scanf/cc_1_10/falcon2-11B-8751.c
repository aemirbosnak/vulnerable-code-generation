//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Define a list of fortunes
    const char *fortunes[] = {
        "Your future is bright!",
        "You will find love and happiness.",
        "You are destined for greatness.",
        "Your luck is about to change.",
        "Prepare for a surprise.",
        "You will encounter a new opportunity.",
        "Be careful with your health.",
        "You will experience a personal breakthrough.",
        "Your hard work will pay off.",
        "A new adventure awaits you."
    };
    
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Get the user's name
    printf("Enter your name: ");
    fflush(stdout);
    char name[100];
    scanf("%s", name);
    
    // Print the fortune
    printf("%s, your fortune is: %s\n", name, fortunes[rand() % 10]);
    
    // Get the user's feedback
    printf("Do you want another fortune? (y/n) ");
    fflush(stdout);
    char response;
    scanf(" %c", &response);
    
    // Repeat the process if the user wants another fortune
    while (response == 'y' || response == 'Y') {
        printf("Enter your name: ");
        fflush(stdout);
        scanf("%s", name);
        printf("%s, your fortune is: %s\n", name, fortunes[rand() % 10]);
        printf("Do you want another fortune? (y/n) ");
        fflush(stdout);
        scanf(" %c", &response);
    }
    
    return 0;
}