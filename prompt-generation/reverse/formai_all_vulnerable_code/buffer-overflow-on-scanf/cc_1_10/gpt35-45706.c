//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Setup random seed
    srand(time(0));
    
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    
    // Ask for the user's name
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    
    // Output a personalized greeting message
    printf("\nHello %s! Are you ready to receive your fortune?\n", name);
    
    // Generate random fortune number
    int fortuneNumber = generateRandom(1, 10);
    
    // Print fortune based on the fortuneNumber
    switch(fortuneNumber) {
        case 1:
            printf("\nYour future is looking bright! Expect good things to come your way soon.\n");
            break;
        case 2:
            printf("\nYou may encounter some challenges in the near future, but don't worry - you'll come out on top!\n");
            break;
        case 3:
            printf("\nYou will soon embark on an exciting journey that will change your life forever.\n");
            break;
        case 4:
            printf("\nYou should take some time to reflect and recharge. A new opportunity will present itself soon.\n");
            break;
        case 5:
            printf("\nYour hard work will pay off in the near future. Keep pushing forward!\n");
            break;
        case 6:
            printf("\nYou will meet someone special in the next few days that will have a profound impact on your life.\n");
            break;
        case 7:
            printf("\nYour kindness and generosity will be reciprocated tenfold in the coming weeks. Keep spreading positivity!\n");
            break;
        case 8:
            printf("\nYou are destined for greatness. Believe in yourself and you will achieve amazing things.\n");
            break;
        case 9:
            printf("\nYou may face some difficult decisions in the near future, but trust your instincts - they will guide you to the right path.\n");
            break;
        case 10:
            printf("\nYour creativity and innovation will be recognized soon, leading to new exciting opportunities.\n");
            break;
    }
    
    // Thank the user and exit the program
    printf("\nThank you for using the Automated Fortune Teller! Good luck on your future endeavors, %s!\n", name);
    return 0;
}