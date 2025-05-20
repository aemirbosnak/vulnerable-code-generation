//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, i, j, k, flag = 0, team1_score = 0, team2_score = 0;
    char team1_name[20], team2_name[20];

    printf("Enter Team 1 Name: ");
    scanf("%s", team1_name);

    printf("Enter Team 2 Name: ");
    scanf("%s", team2_name);

    printf("Welcome to the Battle of the Roses!\n");

    while (1)
    {
        printf("Select an Option:\n");
        printf("1. Attack\n");
        printf("2. Defense\n");
        printf("3. Score\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Team 1 is attacking!\n");
                for (i = 0; i < 5; i++)
                {
                    printf("Team 2, defend! You have %d warriors left.\n", team2_score);
                    scanf("%d", &k);

                    if (k > team2_score)
                    {
                        printf("Error! You do not have enough warriors.\n");
                    }
                    else
                    {
                        team2_score -= k;
                        team1_score += k;
                        printf("Team 1 has captured %d warriors from Team 2.\n", k);
                    }
                }
                break;

            case 2:
                printf("Team 2 is defending!\n");
                for (i = 0; i < 5; i++)
                {
                    printf("Team 1, attack! You have %d warriors left.\n", team1_score);
                    scanf("%d", &k);

                    if (k > team1_score)
                    {
                        printf("Error! You do not have enough warriors.\n");
                    }
                    else
                    {
                        team1_score -= k;
                        team2_score += k;
                        printf("Team 2 has captured %d warriors from Team 1.\n", k);
                    }
                }
                break;

            case 3:
                printf("Team 1 Score: %d\n", team1_score);
                printf("Team 2 Score: %d\n", team2_score);
                break;

            case 4:
                printf("Thank you for playing! Goodbye!\n");
                flag = 1;
                break;
        }

        if (flag == 1)
        {
            break;
        }
    }

    return 0;
}