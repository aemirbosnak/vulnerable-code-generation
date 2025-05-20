//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Procedural Space Adventure!\n");

    // Initialize variables
    char planet[30];
    int choice;
    int evidence = 0;

    // Start the investigation
    printf("Sherlock, you are now on a spaceship investigating a murder case.\n");
    printf("The victim was a renowned space explorer and was found dead on the planet named 'Xenon'.\n");
    printf("Your mission is to find the murderer and bring them to justice.\n");
    printf("You have arrived on the planet. Where would you like to investigate first?\n\n");
    
    while (evidence != 3) { // Loop until enough evidence has been found
        
        // Display options to the user
        printf("Enter a number to investigate:\n");
        printf("1. The victim's spacecraft\n");
        printf("2. The victim's research lab\n");
        printf("3. The victim's living quarters\n\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Check the victim's spacecraft
                printf("\nYou investigate the victim's spacecraft.\n");
                printf("You find a broken communication device.\n");
                printf("This evidence has been added to your investigation.\n\n");
                evidence++;
                break;
            case 2:
                // Check the victim's research lab
                printf("\nYou investigate the victim's research lab.\n");
                printf("You find a paper with 'Project X' on it.\n");
                printf("This evidence has been added to your investigation.\n\n");
                evidence++;
                break;
            case 3:
                // Check the victim's living quarters
                printf("\nYou investigate the victim's living quarters.\n");
                printf("You find a diary with the name of a suspect on it.\n");
                printf("This evidence has been added to your investigation.\n\n");
                evidence++;
                break;
            default:
                // Invalid input
                printf("Invalid input. Please enter a valid number.\n\n");
                break;
        }
    }
    
    printf("\nYou have gathered enough evidence to solve the case!\n");
    printf("Enter the name of the suspect you believe committed the murder:\n");

    // Get the user's input for the suspect name and compare it to the diary found in the living quarters
    scanf("%s", planet);
    if (strcmp(planet, "Moriarty") == 0) {
        printf("\nCongratulations, Sherlock. You have solved the case and found the murderer!\n");
        printf("The murderer was Professor Moriarty who was the victim's research partner.\n");
    }
    else {
        printf("\nSorry, Sherlock. That is not the correct suspect. You need to investigate further!\n");
    }
    
    return 0;
}