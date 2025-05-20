//Gemma-7B DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
// The Crimson Heart Mystery Solver

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[200], str2[200];
    int i, j, k, n, m, flag = 0, found = 0;

    printf("Enter the suspect's name: ");
    scanf("%s", str1);

    printf("Enter the location of the diamond: ");
    scanf("%s", str2);

    // Analyze the suspect's name and the location of the diamond
    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            // Check if the suspect's name is in the diamond's location
            if (str1[i] == str2[j])
            {
                flag = 1;
            }
        }
    }

    // If the flag is 1, the suspect is guilty
    if (flag == 1)
    {
        found = 1;
        printf("The suspect, %s, is guilty of stealing The Crimson Heart.\n", str1);
    }
    else
    {
        found = 0;
        printf("The suspect, %s, is not guilty.\n", str1);
    }

    // If the diamond is found, print a message
    if (found == 1)
    {
        printf("The Crimson Heart has been recovered.\n");
    }
    else
    {
        printf("The Crimson Heart has not been found.\n");
    }

    return 0;
}