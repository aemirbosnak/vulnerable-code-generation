//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void giveFortune() {
    // Define arrays of possible fortunes
    char *loveFortunes[] = {
        "You will meet the love of your life tomorrow.",
        "Your soulmate is thinking of you right now.",
        "Your heart will be full of joy and happiness.",
        "Love is on the horizon for you.",
        "Your love life will soon be filled with passion and adventure.",
        "You will fall deeply in love with someone unexpected.",
        "The stars are aligned in your favor for a romantic encounter.",
        "You will have a beautiful and long-lasting relationship."};
    char *moneyFortunes[] = {
        "A financial windfall is in your future.",
        "You will receive unexpected money soon.",
        "Your bank account will be overflowing.",
        "An opportunity to increase your wealth is coming your way.",
        "Good fortune is on its way to you.",
        "Your hard work will pay off financially.",
        "The universe is abundant and prosperity is yours.",
        "You will achieve financial stability soon."};
    char *careerFortunes[] = {
        "Your career will soon take a positive turn.",
        "An opportunity for career advancement is on the horizon.",
        "Your hard work will be recognized and rewarded in your career.",
        "You are destined for a successful career.",
        "Your dream career is within reach.",
        "Your professional accomplishments will bring you great satisfaction.",
        "Your talents and abilities will lead to career success.",
        "Success is yours for the taking in your career."};

    // Get the user's name
    char name[50];
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    fgets(name, 50, stdin);

    // Remove the new line character from the end of the name
    name[strcspn(name, "\n")] = 0;

    // Get the user's birth year
    int birthYear;
    printf("Thanks, %s! Please enter your birth year: ", name);
    scanf("%d", &birthYear);

    // Generate random numbers to select fortunes from the arrays
    srand(time(NULL));
    int loveIndex = rand() % 8;
    int moneyIndex = rand() % 8;
    int careerIndex = rand() % 8;

    // Output the fortunes to the user
    printf("\n%s, here are your fortunes:\n\n", name);
    printf("Love: %s\n", loveFortunes[loveIndex]);
    printf("Money: %s\n", moneyFortunes[moneyIndex]);
    printf("Career: %s\n", careerFortunes[careerIndex]);
}

int main() {
    giveFortune();
    return 0;
}