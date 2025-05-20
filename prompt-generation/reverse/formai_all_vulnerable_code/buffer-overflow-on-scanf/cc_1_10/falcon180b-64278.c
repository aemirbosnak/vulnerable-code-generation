//Falcon-180B DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100

//function to generate random number between 1 and n
int rand_num(int n)
{
    return rand() % n + 1;
}

//function to generate random love words
char* rand_love_word()
{
    char* love_words[MAX_WORDS] = {"adore", "affection", "amorous", "ardor", "attraction", "beloved", "besotted", "captivate", "charm", "cherish", "crush", "dazzle", "devotion", "enamored", "enchantment", "enthrall", "fascination", "flame", "fondness", "heartthrob", "infatuation", "languish", "longing", "lovestruck", "passion", "romance", "smitten", "sweetheart", "tender", "treasure", "yearning"};
    return love_words[rand_num(MAX_WORDS) - 1];
}

//function to generate a random love poem
void rand_love_poem()
{
    printf("My love for you is like a rose,\n");
    printf("A flower that forever grows.\n");
    printf("It blossoms in the morning light,\n");
    printf("And shines so bright throughout the night.\n\n");

    printf("Your eyes are stars that guide my way,\n");
    printf("Through life's dark and stormy day.\n");
    printf("Your touch is like a gentle breeze,\n");
    printf("That carries me across the seas.\n\n");

    printf("My heart beats only for your love,\n");
    printf("A gift from the heavens above.\n");
    printf("With every breath, I feel you near,\n");
    printf("My love for you will never disappear.\n\n");
}

int main()
{
    srand(time(NULL)); //seed the random number generator with the current time

    int choice;
    do
    {
        printf("Welcome to the Love Poem Generator!\n\n");
        printf("Please select an option:\n");
        printf("1. Generate a random love poem\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                rand_love_poem();
                break;
            case 2:
                printf("Goodbye, my love.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}