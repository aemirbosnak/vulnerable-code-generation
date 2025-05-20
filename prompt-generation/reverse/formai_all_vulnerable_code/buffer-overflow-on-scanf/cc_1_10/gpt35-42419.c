//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int limit)
{
    srand(time(NULL));    // Seed the random number generator
    int randomNumber = rand() % limit + 1;
    return randomNumber;
}

// Function to display the fortune message based on the random number generated
void displayFortune(int randomNumber)
{
    switch(randomNumber)
    {
        case 1:
            printf("Thou shall have great fortune and riches shall come thy way.\n");
            break;
        case 2:
            printf("Thou shall face great danger ahead, beware!\n");
            break;
        case 3:
            printf("Thou shall meet a wise hermit who will guide you on thy path.\n");
            break;
        case 4:
            printf("Thou shall be blessed with good health and longevity.\n");
            break;
        case 5:
            printf("Thou shall come across a hidden treasure, keep thy eyes open.\n");
            break;
        case 6:
            printf("Thou shall face a great battle and emerge victorious.\n");
            break;
        case 7:
            printf("Thou shall be betrayed by a close friend, be vigilant.\n");
            break;
        case 8:
            printf("Thou shall find true love and live happily ever after.\n");
            break;
        case 9:
            printf("Thou shall embark on a great journey and meet many challenges.\n");
            break;
        case 10:
            printf("Thou shall be blessed with a child, a great joy awaits thee.\n");
            break;
        default:
            printf("The stars cannot predict thy fortune at this time, try again later.\n");
    }
}

int main()
{
    printf("Greetings, I am a medieval fortune teller. Please provide me with your name:\n");
    char name[50];
    scanf("%s", name);

    printf("Greetings, %s. Please ask for thy fortune by entering a number between 1 and 10:\n", name);
    int fortuneNumber;
    scanf("%d", &fortuneNumber);

    int randomNumber = generateRandomNumber(10);   // Generate a random number between 1 and 10

    printf("Ah, I see the fates have spoken. Your fortune is as follows:\n");
    printf("------------------------------------------\n");
    displayFortune(randomNumber);   // Display the fortune message based on the random number generated
    printf("------------------------------------------\n");

    printf("Thank you for consulting me for thy fortune, %s. Farewell!\n", name);

    return 0;
}