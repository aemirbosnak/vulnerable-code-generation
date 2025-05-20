//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

typedef enum { Meow, Purr, Hiss, Meowerina } CatLanguage;

void TranslateToCat(char *input, CatLanguage *output)
{
    if (strcmp(input, "Hello") == 0)
    {
        *output = Meow;
    }
    else if (strcmp(input, "Thank you") == 0)
    {
        *output = Purr;
    }
    else if (strcmp(input, "No") == 0)
    {
        *output = Hiss;
    }
    else
    {
        *output = Meowerina;
    }
}

int main()
{
    char input[100];
    CatLanguage output;

    printf("Enter a human word: ");
    scanf("%s", input);

    TranslateToCat(input, &output);

    switch (output)
    {
    case Meow:
        printf("Cat translation: Meow\n");
        break;
    case Purr:
        printf("Cat translation: Purr\n");
        break;
    case Hiss:
        printf("Cat translation: Hiss\n");
        break;
    case Meowerina:
        printf("Cat translation: Meowerina\n");
        break;
    }

    return 0;
}