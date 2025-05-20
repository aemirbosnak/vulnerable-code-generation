//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define CHAR_COUNT 20

int main() {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
    int age;
    int i, j;
    char ch;

    // Print a fancy header
    printf("===============================\n");
    printf("Welcome to the C Programming Challenge!\n");
    printf("===============================\n\n");

    // Ask for the user's name
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character

    // Ask for the user's password
    printf("What is your secret password? ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove the newline character

    // Check if the password is correct
    if (strcmp(password, "secret") == 0) {
        printf("Congratulations, you have passed the first challenge! \n");
    } else {
        printf("Incorrect password. Try again! \n");
    }

    // Ask for the user's age
    printf("How old are you? ");
    scanf("%d", &age);

    // Print a random joke
    srand(time(NULL));
    j = rand() % 10;
    switch (j) {
        case 0:
            printf("Why was the math book sad? Because it had too many problems. \n");
            break;
        case 1:
            printf("Why did the computer go to the doctor? It had a virus! \n");
            break;
        case 2:
            printf("What do you call a fake noodle? An impasta! \n");
            break;
        default:
            printf("I don't know, what do you call a fake noodle? \n");
            break;
    }

    // Print a fancy footer
    printf("===============================\n");
    printf("Thanks for playing the C Programming Challenge! \n");
    printf("===============================\n");

    return 0;
}