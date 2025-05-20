//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tellFortune();

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("----------------------------------------\n");
    // For generating random numbers
    srand(time(NULL));
    // Run the fortune teller
    tellFortune();

    return 0;
}

// Function for telling fortune
void tellFortune()
{
    // Possible fortunes
    char *fortunes[] = {"You will have great success in your career.", 
                        "You will meet the love of your life soon.", 
                        "Good fortune lies ahead of you.", 
                        "You will travel to many exciting places in your life.", 
                        "Luck will always be on your side.", 
                        "You will make a significant achievement in your life soon.", 
                        "A great opportunity will come knocking on your door soon.", 
                        "Expect good news in the near future.", 
                        "Your hard work will soon pay off.", 
                        "You will find happiness and contentment in your life."};

    // Get a random fortune
    int randomIndex = rand() % 10;
    char *fortune = fortunes[randomIndex];

    // Print the fortune
    printf("\n\nYour Fortune: \n");
    printf("---------------\n");
    printf("%s\n", fortune);

    // Ask if user wants another fortune
    char choice;
    printf("\n\nDo you want to know your fortune again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        tellFortune();
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("\n\nThank you for using Automated Fortune Teller! Goodbye!\n");
    }
    else
    {
        printf("\n\nInvalid choice! Goodbye!\n");
    }
}