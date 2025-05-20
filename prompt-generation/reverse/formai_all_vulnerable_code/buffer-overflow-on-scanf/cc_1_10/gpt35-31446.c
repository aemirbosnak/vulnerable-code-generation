//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function that generates a random fortune */
char *generate_fortune() {
    /* List of possible fortunes */
    char *fortunes[] = {
        "A new journey will begin",
        "You will meet someone special soon",
        "Good things come to those who wait",
        "Be patient and success will come",
        "Your hard work will pay off",
        "You will overcome your fears",
        "Believe in yourself and you can do anything",
        "The future is bright for you",
        "Luck is on your side today",
        "You will make great progress in the coming weeks",
        "Something amazing is about to happen",
        "Your creativity will bring you success",
        "Trust your instincts and make a bold move",
        "You will find happiness in unexpected ways",
        "Your determination will bring you success",
        "Take a risk and you will be rewarded",
        "Your potential is limitless",
        "You will have great success in your future endeavors"
    };
    
    /* Get the total number of fortunes */
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    /* Generate a random index */
    int random_index = rand() % num_fortunes;
    
    /* Return the selected fortune */
    return fortunes[random_index];
}

/* Main function */
int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Print welcome message */
    printf("Welcome to the Automated Fortune Teller!\n");
    
    /* Ask the user for their name */
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    
    /* Generate a random fortune */
    char *fortune = generate_fortune();
    
    /* Print the fortune */
    printf("%s, your fortune for today is:\n\n%s\n", name, fortune);
    
    /* Exit program */
    return 0;
}