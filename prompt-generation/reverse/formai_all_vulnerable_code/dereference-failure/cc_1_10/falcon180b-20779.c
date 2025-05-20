//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible fortunes
#define NUM_FORTUNES 10
char *fortunes[NUM_FORTUNES] = {
    "You will have a happy and prosperous life.",
    "A new opportunity will come your way.",
    "You will find true love soon.",
    "Success is within your reach.",
    "Beware of a false friend.",
    "A pleasant surprise awaits you.",
    "Your hard work will pay off.",
    "You will overcome a challenge.",
    "A wise decision will lead to good fortune.",
    "A loved one will return to you."
};

// Function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the user's name
    char name[100];
    printf("What is your name? ");
    scanf("%s", name);

    // Get the user's birthdate
    int day, month, year;
    printf("What is your birthdate (DD/MM/YYYY)? ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Calculate the user's lucky number
    int lucky_num = (day + month + year) % 10;

    // Generate a random fortune
    int fortune_num = rand_int(NUM_FORTUNES);
    char *fortune = fortunes[fortune_num];

    // Replace the placeholder in the fortune with the user's name
    char *new_fortune = malloc(strlen(fortune) + strlen(name) + 1);
    strcpy(new_fortune, fortune);
    char *placeholder = strstr(new_fortune, "[[NAME]]");
    strcpy(placeholder, name);

    // Print the fortune
    printf("\n%s,\n", new_fortune);

    // Generate a lucky number
    int lucky_num2 = rand_int(100) + 1;

    // Print the lucky number
    printf("Your lucky number is %d.\n", lucky_num2);

    return 0;
}