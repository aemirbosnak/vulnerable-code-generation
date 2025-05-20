//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age, birthMonth, luckyNumber;
    int fortuneNumber;  
    char fortune[100];

    printf("Welcome to the Automated Fortune Teller Program.\n");
    printf("Please enter your name: \n");
    scanf("%s", name);
    printf("Please enter your age: \n");
    scanf("%d", &age);
    printf("Please enter the month you were born: \n");
    scanf("%d", &birthMonth);
    printf("Please enter your lucky number: \n");
    scanf("%d", &luckyNumber);

    // Calculate the fortune number based on user inputs
    fortuneNumber = ((birthMonth * age) % luckyNumber) + 1;

    // Generate a random fortune based on the fortune number
    switch(fortuneNumber)
    {
        case 1:
            sprintf(fortune, "%s, you will soon receive a promotion at work! Congratulations!", name);
            break;
        case 2:
            sprintf(fortune, "A new opportunity is coming your way, %s! Keep your eyes open.", name);
            break;
        case 3:
            sprintf(fortune, "You are due for a big change, %s. Embrace it and good things will come.", name);
            break;
        case 4:
            sprintf(fortune, "Peace and prosperity will find their way to you, %s. Keep an open mind.", name);
            break;
        case 5:
            sprintf(fortune, "You will soon embark on a great adventure, %s. Enjoy the ride!", name);
            break;
        case 6:
            sprintf(fortune, "Take a leap of faith, %s. Your intuition will guide you.", name);
            break;
        default:
            sprintf(fortune, "A mysterious force surrounds your destiny, %s. The future is yours to create.", name);
            break;
    }
    
    // Print the fortune to the user
    printf("\nYour fortune for the day is:\n");
    printf("%s\n", fortune);
    
    // Log the fortune to a file with a timestamp
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timestamp[100];
    strftime(timestamp, 100, "%Y-%m-%d %H:%M:%S", timeinfo);
    
    FILE *f = fopen("fortune_log.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(f, "[%s] %s\n", timestamp, fortune);
    fclose(f);
    
    return 0;
}