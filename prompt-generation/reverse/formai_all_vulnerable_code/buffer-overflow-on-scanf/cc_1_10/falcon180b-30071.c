//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(char* fortune) {
    printf("\n%s\n", fortune);
}

// Function to generate a fortune based on a keyword
char* generate_fortune(char* keyword) {
    char* fortunes[] = {
        "You will have a successful day",
        "A new opportunity is coming your way",
        "You will meet someone special today",
        "Your hard work will pay off soon",
        "You will overcome a challenge today",
        "Good things are happening in your life",
        "Your future is bright and full of possibilities",
        "Believe in yourself and you will achieve great things",
        "You will receive good news today",
        "Your dreams are within reach, keep working towards them"
    };

    int index = rand_num(0, 9);
    char* fortune = fortunes[index];
    strcat(fortune, " ");
    strcat(fortune, keyword);
    strcat(fortune, ".\n");

    return fortune;
}

int main() {
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Retro Fortune Teller!\n");

    // Get user's name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    // Get user's birthdate
    int day, month, year;
    printf("What is your birthdate (DD/MM/YYYY)? ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Get user's favorite color
    char color[20];
    printf("What is your favorite color? ");
    scanf("%s", color);

    // Generate a fortune based on the user's birthdate
    printf("\nYour fortune based on your birthdate:\n");
    char* fortune = generate_fortune(color);
    print_fortune(fortune);

    // Generate a fortune based on the user's name
    printf("\nYour fortune based on your name:\n");
    fortune = generate_fortune(name);
    print_fortune(fortune);

    // Generate a fortune based on the current date
    printf("\nYour fortune for today:\n");
    fortune = generate_fortune("today");
    print_fortune(fortune);

    return 0;
}