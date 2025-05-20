//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Declare variables
    char name[MAX_NAME_LEN];
    int age;
    int choice;

    // Print welcome message
    printf("Welcome to the C Programming Challenge!\n");

    // Print name and age prompts
    printf("What is your name? ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("What is your age? ");
    scanf("%d", &age);

    // Print out a poem based on the user's name and age
    if (age >= 18 && age <= 30) {
        printf("You are a young adult, full of life and energy. May your\n");
        printf("adventures be many and your heart be filled with joy. \n");
    } else if (age >= 31 && age <= 50) {
        printf("You are a wise and experienced individual, with a wealth of\n");
        printf("knowledge and wisdom to share. May your days be filled with\n");
        printf("purpose and your nights be filled with peace. \n");
    } else {
        printf("You are a wise and experienced elder, with a lifetime of\n");
        printf("stories to tell and lessons to share. May your final years be\n");
        printf("filled with love and your heart be filled with joy. \n");
    }

    // Print out a quote based on the user's name
    if (strcmp(name, "Alice") == 0) {
        printf("As Alice once said, 'Curiouser and curiouser!' May your\n");
        printf("curiosity lead you on many adventures and your heart be filled\n");
        printf("with wonder. \n");
    } else if (strcmp(name, "Bob") == 0) {
        printf("As Bob once said, 'The world is your oyster, go out and\n");
        printf("explore it!' May your travels be safe and your heart be filled\n");
        printf("with excitement. \n");
    } else {
        printf("As the great philosopher, Bob, once said, 'Life is what\n");
        printf("happens when you're busy making other plans.' May your\n");
        printf("plans be filled with joy and your heart be filled with love. \n");
    }

    // Print out a riddle based on the user's age
    if (age >= 18 && age <= 30) {
        printf("Here is a riddle for you, young one: What has keys but can't open\n");
        printf("locks?\n");
    } else if (age >= 31 && age <= 50) {
        printf("Here is a riddle for you, wise one: What has a head, a tail,\n");
        printf("but no body?\n");
    } else {
        printf("Here is a riddle for you, elder: What has a face, but no eyes,\n");
        printf("nose, or mouth?\n");
    }

    // Print out a final message based on the user's name and age
    if (age >= 18 && age <= 30) {
        printf("May your youth be filled with excitement and your heart be\n");
        printf("filled with love. \n");
    } else if (age >= 31 && age <= 50) {
        printf("May your wisdom be a beacon of light and your heart be\n");
        printf("filled with joy. \n");
    } else {
        printf("May your final years be filled with love and your heart be\n");
        printf("filled with peace. \n");
    }

    // Print out a final message based on the user's name and age
    printf("Thank you for playing the C Programming Challenge!\n");

    return 0;
}