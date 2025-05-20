//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Cat
{
    char name[20];
    char breed[20];
    int age;
    char favorite_food[20];
} Cat;

int main()
{
    Cat cats[MAX_WORDS] = {
        {"Fluffy", "Persian", 5, "Tuna"},
        {"Marbles", "Abyssinian", 3, "Chicken"},
        {"Socks", "Bengal", 2, "Salmon"},
        {"Tiger", "Siberian", 4, "Beef"},
        {"Snowball", "Maine Coon", 6, "Shrimp"},
        {"Luna", "Persian", 3, "Cat Food"},
        {"Oliver", "Abyssinian", 4, "Fish"},
        {"Max", "Bengal", 2, "Pizza"},
        {"Oliver", "Siberian", 5, "Pork"},
        {"Lola", "Maine Coon", 6, "Fruit"}
    };

    char input[20];
    printf("Welcome to the Meow-tastic Cat Translator!\n");
    printf("Please enter a word: ");
    scanf("%s", input);

    int i = 0;
    for (i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(input, cats[i].name) == 0)
        {
            printf("The translation for %s is: %s\n", cats[i].name, cats[i].favorite_food);
            break;
        }
    }

    if (i == MAX_WORDS)
    {
        printf("Sorry, I couldn't find a match.\n");
    }

    return 0;
}