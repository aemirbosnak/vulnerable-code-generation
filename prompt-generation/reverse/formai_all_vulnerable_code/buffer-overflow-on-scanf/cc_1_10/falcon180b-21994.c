//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random conspiracy theory
void generate_theory(void)
{
    int theory_type;
    char *theory_subject;

    // Generate a random theory type
    theory_type = rand() % 6;

    // Set the theory subject based on the theory type
    switch (theory_type)
    {
        case 0:
            theory_subject = "The moon landing was faked";
            break;
        case 1:
            theory_subject = "9/11 was an inside job";
            break;
        case 2:
            theory_subject = "The Illuminati control the world";
            break;
        case 3:
            theory_subject = "The Earth is flat";
            break;
        case 4:
            theory_subject = "Aliens have visited Earth";
            break;
        case 5:
            theory_subject = "Bigfoot is real";
            break;
    }

    // Print the generated theory
    printf("Random Conspiracy Theory: %s\n", theory_subject);
}

int main(void)
{
    int choice;
    char input[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user chooses to quit
    while (1)
    {
        // Print the menu
        printf("\nRandom Conspiracy Theory Generator\n");
        printf("1. Generate a new theory\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");

        // Read the user's choice
        scanf("%d", &choice);

        // Generate a new theory if the user chooses option 1
        if (choice == 1)
        {
            generate_theory();
        }
        // Quit the program if the user chooses option 2
        else if (choice == 2)
        {
            break;
        }
        // Handle invalid input
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

        // Ask the user if they want to continue
        printf("Do you want to generate another theory? (y/n): ");
        scanf("%s", input);

        // Continue the loop if the user wants to generate another theory
        if (input[0] == 'y' || input[0] == 'Y')
        {
            continue;
        }
        // Quit the loop if the user doesn't want to generate another theory
        else
        {
            break;
        }
    }

    return 0;
}