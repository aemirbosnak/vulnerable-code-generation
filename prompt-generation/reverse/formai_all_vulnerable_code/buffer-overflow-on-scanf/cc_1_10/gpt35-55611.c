//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get random seed based on time
    srand(time(NULL));

    // Initialize variables
    int fortuneNum = rand() % 10 + 1;
    char name[20];
    int age;
    char response;

    // Welcome the user and ask for their name and age
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you? ", name);
    scanf("%d", &age);

    // Give the user their fortune based on their age and generate a lucky number
    if (age <= 18) {
        printf("You will have a successful career and many happy relationships in the future!\n");
        fortuneNum += 3;
    }
    else if (age >= 19 && age <= 40) {
        printf("You will live a long and prosperous life filled with adventure and travel!\n");
        fortuneNum += 5;
    }
    else if (age >= 41 && age <= 60) {
        printf("You will find true love and happiness in your later years!\n");
        fortuneNum += 7;
    }
    else {
        printf("You will live to see your grandchildren and great-grandchildren grow up!\n");
        fortuneNum += 9;
    }

    // Ask the user if they want to know their lucky number
    printf("Would you like to know your lucky number? (y/n) ");
    scanf(" %c", &response);

    if (response == 'y') {
        printf("Your lucky number is %d\n", fortuneNum);
    }
    else {
        printf("That's okay, maybe next time!\n");
    }

    return 0;
}