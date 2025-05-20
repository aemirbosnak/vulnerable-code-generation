//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[50];
    int age, rand_num;
    const char* fortunes[] = {"You will be a millionaire one day", "Your dreams will come true in the near future", "You will find love soon", "A great opportunity will present itself to you soon", "You will travel to a new and exciting place"};

    // Get input from user
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Generate a random number seed and select a fortune
    srand(time(0)); // Seed the random number generator with current time
    rand_num = rand() % 5; // Generate a random number between 0 and 4

    // Output the fortune to the user
    printf("\nHello, %s! Your fortune is:\n\n", name);
    printf("%s\n", fortunes[rand_num]);

    // Add personalized messages based on user age
    if (age < 18)
    {
        printf("\nSince you are under 18, we advise you to seek parental guidance before making any major decisions.\n");
    }
    else if (age >= 18 && age < 30)
    {
        printf("\nYou are young and have your whole life ahead of you. Don't be afraid to take risks and chase your dreams!\n");
    }
    else if (age >= 30 && age < 50)
    {
        printf("\nYou are in the prime of your life. Keep working hard and success will be yours!\n");
    }
    else if (age >= 50 && age < 70)
    {
        printf("\nYou have a wealth of experience and wisdom. Share your knowledge with the world and make a difference!\n");
    }
    else
    {
        printf("\nAge is just a number. You are never too old to learn and grow. Keep pushing your boundaries!\n");
    }

    // Add a goodbye message
    printf("\nThank you for using the Automated Fortune Teller. Have a great day!\n");

    return 0;
}