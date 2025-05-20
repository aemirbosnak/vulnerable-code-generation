//Gemma-7B DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name1[20], name2[20];
    int age1, age2;
    char occupation1[50], occupation2[50];

    printf("Enter the first player's name: ");
    scanf("%s", name1);

    printf("Enter the first player's age: ");
    scanf("%d", &age1);

    printf("Enter the first player's occupation: ");
    scanf("%s", occupation1);

    printf("Enter the second player's name: ");
    scanf("%s", name2);

    printf("Enter the second player's age: ");
    scanf("%d", &age2);

    printf("Enter the second player's occupation: ");
    scanf("%s", occupation2);

    printf("\n");

    printf("Greetings, %s and %s!\n", name1, name2);

    printf("You are both %d years old.\n", age1);

    printf("Your occupations are: %s and %s.\n", occupation1, occupation2);

    printf("\n");

    printf("Would you like to play a game together? (Y/N)");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y')
    {
        // Game code here
    }

    printf("\n");

    printf("Thank you for playing, %s and %s.\n", name1, name2);

    return 0;
}