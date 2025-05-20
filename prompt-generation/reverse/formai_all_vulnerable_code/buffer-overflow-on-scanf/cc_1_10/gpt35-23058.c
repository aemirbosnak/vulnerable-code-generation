//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Global variable for length of array
#define ARRAY_LENGTH 10

//Function prototypes
void generateConspiracyTheory();

int main()
{
    //Seed for random number generator using current time
    srand(time(NULL));

    printf("\nWelcome to the Random Conspiracy Theory Generator!\n");

    int choice = 0;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Generate a conspiracy theory\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateConspiracyTheory();
                break;
            case 2:
                printf("Thanks for using the Random Conspiracy Theory Generator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

void generateConspiracyTheory()
{
    //Conspiracy theory array
    char conspiracyTheories[ARRAY_LENGTH][100] = {"The moon landing was faked by the government.",
                                                  "9/11 was an inside job.",
                                                  "The government is hiding the cure for cancer.",
                                                  "Aliens are living among us.",
                                                  "The Earth is flat and the government is covering it up.",
                                                  "Chemtrails are being used for mind control.",
                                                  "The government is hiding the existence of Bigfoot.",
                                                  "The Illuminati is controlling world events.",
                                                  "The pharmaceutical industry is hiding the cure for all diseases.",
                                                  "The government is using HAARP to manipulate the weather."};

    int randomIndex = rand() % ARRAY_LENGTH;

    printf("\n%s\n\n", conspiracyTheories[randomIndex]);
}