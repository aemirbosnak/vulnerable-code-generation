//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_BIRTH_YEAR 1900
#define MAX_BIRTH_YEAR 2022
#define NUM_FORTUNES 10

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    int range = max - min + 1;
    int random = rand() % range;
    return random + min;
}

// Function to print a fortune based on the user's birth year
void print_fortune(int birth_year) {
    int fortune_number = rand_range(0, NUM_FORTUNES - 1);

    switch (fortune_number) {
        case 0:
            printf("You will find great success in your personal and professional life this year.\n");
            break;
        case 1:
            printf("Your hard work and dedication will pay off in the coming months.\n");
            break;
        case 2:
            printf("Be prepared for unexpected changes and adaptability will be key.\n");
            break;
        case 3:
            printf("Trust your intuition and follow your heart this year.\n");
            break;
        case 4:
            printf("Good fortune awaits you, but be cautious of those who may seek to take advantage of your kindness.\n");
            break;
        case 5:
            printf("This year will bring new opportunities for growth and learning.\n");
            break;
        case 6:
            printf("Your creativity and artistic talents will shine this year.\n");
            break;
        case 7:
            printf("Your patience and perseverance will be rewarded in the coming months.\n");
            break;
        case 8:
            printf("This year will be a time of reflection and self-discovery.\n");
            break;
        case 9:
            printf("You will experience unexpected blessings and good fortune this year.\n");
            break;
        default:
            printf("An error occurred while generating your fortune.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int birth_year;

    printf("Welcome to the Automated Fortune Teller! Please enter your birth year:\n");
    scanf("%d", &birth_year);

    if (birth_year < MIN_BIRTH_YEAR || birth_year > MAX_BIRTH_YEAR) {
        printf("Invalid birth year. Please enter a valid birth year between %d and %d.\n", MIN_BIRTH_YEAR, MAX_BIRTH_YEAR);
        return 1;
    }

    print_fortune(birth_year);

    return 0;
}