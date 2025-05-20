//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random fortune
void generate_fortune()
{
    // Array of fortunes
    char* fortunes[] = {
        "Your future is bright!",
        "You will find love soon.",
        "Your hard work will pay off.",
        "You have a great sense of humor.",
        "Your lucky number is 7.",
        "You will travel to a new place soon.",
        "You have a kind heart.",
        "You will make a lot of money.",
        "You are very creative.",
        "You will meet a new friend soon."
    };
    
    // Randomly select a fortune
    int rand_num = rand() % 10;
    printf("Your fortune is: %s\n", fortunes[rand_num]);
}

// Function to ask user if they want to generate another fortune
void generate_another_fortune()
{
    printf("Would you like to generate another fortune? (y/n): ");
    char choice;
    scanf("%c", &choice);
    
    if (choice == 'y')
    {
        generate_fortune();
    }
    else
    {
        printf("Goodbye!\n");
    }
}

int main()
{
    // Generate the first fortune
    generate_fortune();
    
    // Ask user if they want to generate another fortune
    generate_another_fortune();
    
    return 0;
}