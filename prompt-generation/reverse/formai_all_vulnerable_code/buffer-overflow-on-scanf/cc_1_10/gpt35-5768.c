//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char answer[100];

    printf("Welcome to the C Element Periodic Table Quiz!\n");

    printf("What is the symbol for Carbon? ");
    scanf("%s", answer);

    if(strcmp(answer, "C") == 0)
    {
        printf("You got it! C is the symbol for Carbon!\n");
    }
    else
    {
        printf("Sorry, %s is not the correct answer. The symbol for Carbon is C. Better luck next time!\n", answer);
    }

    printf("What is the symbol for Helium? ");
    scanf("%s", answer);

    if(strcmp(answer, "He") == 0)
    {
        printf("You're on fire! He is the symbol for Helium!\n");
    }
    else
    {
        printf("Oh no, %s is incorrect. The symbol for Helium is He. Don't worry, you'll get it next time!\n", answer);
    }

    printf("Next up, what is the symbol for Boron? ");
    scanf("%s", answer);

    if(strcmp(answer, "B") == 0)
    {
        printf("Boom! B is the symbol for Boron!\n");
    }
    else
    {
        printf("Ouch, %s is not the correct answer. The symbol for Boron is B. Keep trying!\n", answer);
    }

    printf("What about Oxygen? Do you know the symbol? ");
    scanf("%s", answer);

    if(strcmp(answer, "O") == 0)
    {
        printf("Bingo! O is the symbol for Oxygen!\n");
    }
    else
    {
        printf("Nope, %s is incorrect. The symbol for Oxygen is O. Keep your head up!\n", answer);
    }

    printf("On to the final question - what is the symbol for Sodium? ");
    scanf("%s", answer);

    if(strcmp(answer, "Na") == 0)
    {
        printf("Yay! Na is the symbol for Sodium!\n");
    }
    else
    {
        printf("Oh man, %s is not the right answer. The symbol for Sodium is Na. Try again next time!\n", answer);
    }

    printf("You've reached the end of the quiz. Thank you for playing and learning with us!\n");

    return 0;
}