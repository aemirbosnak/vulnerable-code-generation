//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Let's get excited about C String manipulation!
    printf("Welcome to my exciting C String manipulation program!\n\n");

    // Let's ask the user for their name!
    char name[100];
    printf("What's your name? ");
    scanf("%s", name);
    printf("\n");

    // Let's convert the user's name to uppercase!
    int i = 0;
    while(name[i])
    {
        name[i] = toupper(name[i]);
        i++;
    }

    printf("Wow, %s! Your name looks amazing in all caps!\n", name);
    printf("Let's move on to something even more exciting...\n\n");

    // Let's ask the user for their favorite color!
    char color[100];
    printf("What's your favorite color? ");
    scanf("%s", color);
    printf("\n");

    // Let's concatenate the user's name and favorite color!
    char *concatenated_string = malloc(strlen(name) + strlen(color) + 1);
    strcpy(concatenated_string, name);
    strcat(concatenated_string, color);

    printf("Amazing, %s! Your name and favorite color sound great together!\n", concatenated_string);
    printf("But wait, we can do even more with C String manipulation!\n\n");

    // Let's reverse the user's favorite color!
    char reversed_color[100];
    int j = strlen(color) - 1;
    i = 0;
    while(j >= 0)
    {
        reversed_color[i] = color[j];
        i++;
        j--;
    }
    reversed_color[i] = '\0';

    printf("Incredible, %s! Your favorite color looks even better spelled backwards!\n", reversed_color);
    printf("And there's still more we can do with C String manipulation!\n");

    // Let's see if the user's name is a palindrome!
    int palindrome = 1;
    i = 0;
    j = strlen(name) - 1;
    while(i < j)
    {
        if(name[i] != name[j])
        {
            palindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if(palindrome == 1)
    {
        printf("Unbelievable, %s! Your name is a palindrome!\n", name);
    }
    else
    {
        printf("Still amazing, %s! Your name is not a palindrome, but that's okay!\n", name);
    }

    printf("\nThanks for using my exciting C String manipulation program!\n");

    return 0;
}