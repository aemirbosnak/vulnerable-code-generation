//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage() {
    printf("===================================\n");
    printf("          Fortune Teller          \n");
    printf("===================================\n");
    printf("Welcome, seeker of wisdom! I can reveal your destiny. \n");
    printf("Please share your birth date (format: YYYY MM DD): \n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clearing the input buffer
}

int getRandomIndex(int max) {
    return rand() % max;
}

void generateFortune(int day, int month, int year) {
    const char* fortunes[] = {
        "You will find happiness in unexpected places.",
        "Change is coming your way, embrace it.",
        "A thrilling adventure awaits you just around the corner.",
        "You will build strong relationships with new friends soon.",
        "Your efforts will pay off in ways you least expect.",
        "A secret admirer is watching you closely.",
        "Patience will lead you to great success.",
        "A surprise gift will come your way shortly.",
        "You will make a decision that will greatly benefit you.",
        "Be cautious of opportunities that seem too good to be true."
    };

    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    srand((year + month + day) * time(NULL)); // Seed the random number generator
    int index = getRandomIndex(numFortunes);

    printf("Here's your fortune:\n");
    printf("*********************************\n");
    printf("%s\n", fortunes[index]);
    printf("*********************************\n");
}

int main() {
    int year, month, day;

    displayWelcomeMessage();
    
    printf("Please enter your year of birth: ");
    scanf("%d", &year);
    clearInputBuffer();

    printf("Please enter your month of birth: ");
    scanf("%d", &month);
    clearInputBuffer();

    printf("Please enter your day of birth: ");
    scanf("%d", &day);
    clearInputBuffer();
    
    generateFortune(day, month, year);

    printf("Thank you for visiting the Fortune Teller. May your future be bright!\n");
    return 0;
}