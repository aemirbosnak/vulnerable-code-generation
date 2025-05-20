//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
    char word[20];
    int i = 0;
    printf("Enter a word: ");
    scanf("%s", word);

    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }

    int flag = 0;
    char dictionary[10][20] = {
        {"Apple"},
        {"Banana"},
        {"Orange"},
        {"Peach"},
        {"Pear"},
        {"Grape"},
        {"Melon"},
        {"Watermelon"},
        {"Tomato"},
        {"Strawberry"}
    };

    for (i = 0; i < 10; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("The word %s is in the dictionary.\n", word);
    }
    else
    {
        printf("The word %s is not in the dictionary.\n", word);
    }

    return 0;
}