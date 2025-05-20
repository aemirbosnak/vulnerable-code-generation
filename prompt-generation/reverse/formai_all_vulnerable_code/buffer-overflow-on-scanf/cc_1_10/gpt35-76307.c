//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char username[20];
    int age;
    
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    scanf("%s", username);
    
    printf("\nHi %s! Welcome to your fortune. Let's begin!\n", username);
    
    printf("\nPlease enter your age: ");
    scanf("%d", &age);
    
    if (age < 18)
    {
        printf("\nSorry %s, you are too young to use this program. Come back when you are older!\n", username);
        return 0;
    }
    
    // Random number generator
    srand(time(0));
    int fortune_num = rand() % 5;
    
    // Fortune teller array
    char *fortunes[] = {
        "You will have a wonderful day today!",
        "Your future looks very bright!",
        "You will meet someone special very soon!",
        "You are destined for greatness!",
        "You will receive some good news very soon!"
    };
    
    printf("\n%s, are you ready to find out your fortune? Press enter to continue...", username);
    getchar();
    getchar(); // Wait for user to press enter
    
    printf("\nDrumroll please...\n\n");
    printf("Your fortune is: %s\n", fortunes[fortune_num]);
    
    // Closing message
    printf("\nThanks for using the Automated Fortune Teller, %s! Come back again soon!\n", username);

    return 0;
}