//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_ERROR(x) printf("Error: %s\n", #x)

int main() {
    int age;
    char name[50];
    float height;

    printf("Welcome to the authentic C programming experience!\n");

    // Ask the user for their name and age
    printf("What is your name? ");
    fgets(name, 50, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Print a personalized message based on the user's age
    if (age < 18) {
        printf("You're still a young one, so I'll keep it short and sweet. Hello, %s!", name);
    } else if (age >= 18 && age < 30) {
        printf("Ah, a spry young adult! You're in your prime, %s. Enjoy life to the fullest!", name);
    } else if (age >= 30 && age < 50) {
        printf("You're in your golden years, %s. Take it easy and enjoy the fruits of your labor!", name);
    } else {
        printf("Wow, you're a senior citizen now, %s. Keep on keeping on!", name);
    }

    // Ask the user for their height
    printf("How tall are you? ");
    scanf("%f", &height);

    // Print a personalized message based on the user's height
    if (height < 5.5) {
        printf("You're a little short, %s. But don't worry, being small has its advantages!", name);
    } else if (height >= 5.5 && height < 6.5) {
        printf("You're of average height, %s. Good job!", name);
    } else {
        printf("Wow, you're really tall, %s! You must be a basketball star or something!", name);
    }

    // Print a final message
    printf("It was great meeting you, %s. Have a fantastic day!", name);

    return 0;
}