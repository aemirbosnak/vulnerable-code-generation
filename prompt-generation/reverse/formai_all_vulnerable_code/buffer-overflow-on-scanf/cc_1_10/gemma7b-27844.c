//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPOOK_FILE "spooky.txt"

int main()
{
    int i, j, k, random_num, ghosts_count = 0;
    char name[20];
    FILE *spook_file = fopen(SPOOK_FILE, "r");
    char spook_file_contents[1024];

    if (spook_file == NULL)
    {
        printf("Error opening spooky file.\n");
        return 1;
    }

    fread(spook_file_contents, 1024, 1, spook_file);
    fclose(spook_file);

    printf("Welcome to the Haunted Mansion of Gloom Manor!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    for (i = 0; spook_file_contents[i] != '\0'; i++)
    {
        if (spook_file_contents[i] == 'G')
        {
            ghosts_count++;
        }
    }

    printf("There are a total of %d ghosts in Gloom Manor.\n", ghosts_count);

    time_t t = time(NULL);
    srand(t);

    for (j = 0; j < ghosts_count; j++)
    {
        random_num = rand() % 4;
        switch (random_num)
        {
            case 0:
                printf("BOO!\n");
                break;
            case 1:
                printf("Get out of here!\n");
                break;
            case 2:
                printf("The ghosts are coming for you!\n");
                break;
            case 3:
                printf("Your soul is ours!\n");
                break;
        }
    }

    return 0;
}