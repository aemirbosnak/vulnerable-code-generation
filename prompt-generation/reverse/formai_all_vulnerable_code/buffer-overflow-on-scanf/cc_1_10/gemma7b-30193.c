//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    printf("What is your name, my dear Watson?\n");
    scanf("%s", name);

    printf("Welcome, %s, to the case of the missing diamond necklace.\n", name);

    // Gather clues
    char clue1[50];
    printf("Please tell me the first clue you found.\n");
    scanf("%s", clue1);

    char clue2[50];
    printf("What is the second clue?\n");
    scanf("%s", clue2);

    char clue3[50];
    printf("Can you describe the third clue?\n");
    scanf("%s", clue3);

    // Analyze clues
    int suspicious_person = 0;
    if (strcmp(clue1, "The maid's footprints") == 0)
    {
        suspicious_person++;
    }
    if (strcmp(clue2, "The butler's handwriting") == 0)
    {
        suspicious_person++;
    }
    if (strcmp(clue3, "The jeweler's fingerprints") == 0)
    {
        suspicious_person++;
    }

    // Conclusion
    if (suspicious_person > 0)
    {
        printf("It appears that you have stumbled upon a most sinister plot. The suspect is…\n");
    }
    else
    {
        printf("Congratulations, %s, you have solved the case!\n", name);
    }

    return 0;
}