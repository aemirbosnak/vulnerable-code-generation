//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char firstName[20], lastName[20];
    int age;

    // Greet the user
    printf("Welcome to the Automated Fortune Teller program!\n\n");

    // Get user's information
    printf("What is your first name?\n");
    scanf("%s", firstName);

    printf("What is your last name?\n");
    scanf("%s", lastName);

    printf("What is your age?\n");
    scanf("%d", &age);

    // Check if the user is of a legal age to participate
    if (age < 18)
    {
        printf("Sorry %s %s, you must be 18 or older to use this program\n", firstName, lastName);
        return 0;
    }

    // Create a random number generator
    srand(time(NULL));
    int fortuneNumber = rand() % 5;

    // Use the random number generator to select a fortune
    switch (fortuneNumber)
    {
        case 0:
            printf("%s %s, your future holds great success in your career!\n", firstName, lastName);
            break;
        case 1:
            printf("%s %s, be careful of a deceitful person in your life\n", firstName, lastName);
            break;
        case 2:
            printf("%s %s, a large sum of money is coming your way soon\n", firstName, lastName);
            break;
        case 3:
            printf("%s %s, you will soon be taking a trip to an exotic location\n", firstName, lastName);
            break;
        case 4:
            printf("%s %s, love is in the air and you will soon find it\n", firstName, lastName);
            break;
    }

    // Goodbye message
    printf("\nThank you for using the Automated Fortune Teller program!\n");

    return 0;
}