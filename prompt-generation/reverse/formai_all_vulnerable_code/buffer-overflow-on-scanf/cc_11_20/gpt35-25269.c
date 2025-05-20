//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, c, user_age, user_choice;
    char name[20], gender;

    time_t t;
    srand((unsigned) time(&t));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your first name: ");
    scanf("%s", name);
    printf("Please enter your gender (M/F/O): ");
    scanf(" %c", &gender);
    printf("Please enter your age: ");
    scanf("%d", &user_age);

    printf("\n%s, your fortune for today is...drumroll please...\n\n", name);

    for (i = 1; i <= 7; i++)
    {
        c = rand() % 13;

        switch (c)
        {
            case 0:
                printf("You will come into a great fortune in the near future.\n");
                break;
            case 1:
                printf("You will soon meet someone special.\n");
                break;
            case 2:
                printf("You will succeed in all your endeavors today.\n");
                break;
            case 3:
                printf("You will receive some unexpected news soon. It may be good or bad, but stay resilient!\n");
                break;
            case 4:
                printf("You will meet an old friend you haven't seen in a while.\n");
                break;
            case 5:
                printf("You will be invited to a very important event soon. Make sure to dress accordingly!\n");
                break;
            case 6:
                printf("Your hard work will pay off soon. Keep pushing through!\n");
                break;
            case 7:
                printf("You will have a peaceful day today. Enjoy the calmness!\n");
                break;
            case 8:
                printf("You will have an opportunity for self-growth today. Take advantage of it!\n");
                break;
            case 9:
                printf("You will make a new friend today.\n");
                break;
            case 10:
                printf("You will receive a gift or reward today. Congratulations!\n");
                break;
            case 11:
                printf("You will have a satisfying meal today. Treat yourself to something delicious!\n");
                break;
            case 12:
                printf("You will experience a moment of clarity today. Make sure to follow through with it.\n");
                break;
        }

        printf("\n");
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    if (gender == 'M')
    {
        printf("Have a good day, Mr. %s!", name);
    } 
    else if (gender == 'F')
    {
        printf("Have a good day, Ms. %s!", name);
    }
    else
    {
        printf("Have a good day, %s!", name);
    }

    printf("\n\nWould you like to know your lucky number for today? (1 for yes, 0 for no): ");
    scanf("%d", &user_choice);

    if (user_choice == 1)
    {
        c = rand() % 20 + 1;
        printf("\nYour lucky number for today is...%d!\n", c);
    }

    return 0;
}