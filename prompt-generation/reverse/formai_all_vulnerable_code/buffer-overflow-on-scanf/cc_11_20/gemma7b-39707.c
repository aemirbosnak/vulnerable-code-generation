//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declare variables
    char name[20];
    int age;

    // Get the user's name and age
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);

    // Print a greeting
    printf("Hello, %s! You are %d years old.", name, age);

    // Calculate the user's horoscope sign
    int horoscope_sign = age % 12;

    // Print the horoscope sign
    switch (horoscope_sign) {
        case 0:
            printf("Your horoscope sign is Rat.");
            break;
        case 1:
            printf("Your horoscope sign is Ox.");
            break;
        case 2:
            printf("Your horoscope sign is Tiger.");
            break;
        case 3:
            printf("Your horoscope sign is Rabbit.");
            break;
        case 4:
            printf("Your horoscope sign is Dragon.");
            break;
        case 5:
            printf("Your horoscope sign is Snake.");
            break;
        case 6:
            printf("Your horoscope sign is Horse.");
            break;
        case 7:
            printf("Your horoscope sign is Goat.");
            break;
        case 8:
            printf("Your horoscope sign is Monkey.");
            break;
        case 9:
            printf("Your horoscope sign is Rooster.");
            break;
        case 10:
            printf("Your horoscope sign is Dog.");
            break;
        case 11:
            printf("Your horoscope sign is Pig.");
            break;
    }

    // Thank the user
    printf("Thank you for visiting my website, %s!", name);

    return 0;
}