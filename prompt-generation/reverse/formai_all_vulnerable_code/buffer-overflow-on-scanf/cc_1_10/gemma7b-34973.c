//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void dream_sequence(int);

int main()
{
    int choice, dreams_counter = 0;
    char dream_scape[200];

    printf("Welcome to the Surreal Dreamscape.\n");
    printf("Would you like to embark on a journey into the subconscious mind?\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        dream_sequence(dreams_counter);
    }

    return 0;
}

void dream_sequence(int dreams_counter)
{
    int dream_choice, subconscious_score = 0, dream_length = 0;
    char dream_theme[50];

    dreams_counter++;

    printf("Your mind has been transported to a surreal dream realm.\n");
    printf("Please choose a dream theme:\n");
    scanf("%s", dream_theme);

    if (strcmp(dream_theme, " Lucid Dreams") == 0)
    {
        subconscious_score += 20;
    }
    else if (strcmp(dream_theme, "Freudian Dreams") == 0)
    {
        subconscious_score += 30;
    }
    else if (strcmp(dream_theme, "Jungian Dreams") == 0)
    {
        subconscious_score += 40;
    }

    dream_length = rand() % 5 + 1;

    printf("Your dream unfolds...\n");
    for (int i = 0; i < dream_length; i++)
    {
        printf("...and then... ");
        dream_sequence(dreams_counter);
    }

    printf("Your dream ends.\n");
    printf("Your subconscious score: %d\n", subconscious_score);
}