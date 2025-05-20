//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define VIRUS_COUNT 3
#define MAX_STRING_LENGTH 100

int virusDatabase[VIRUS_COUNT][MAX_STRING_LENGTH] = {
    { 0x6c, 0x6f, 0x76, 0x65, 0x00 }, // "love"
    { 0x68, 0x61, 0x74, 0x65, 0x00 }, // "hate"
    { 0x70, 0x65, 0x61, 0x63, 0x65 } // "peace"
};

int mathFunction(int num1, int num2)
{
    int result = 1;
    for (int i = 0; i < num2; i++) 
    {
        result = result * num1;
    }
    return result % VIRUS_COUNT;
}

int isVirus(char* input) 
{
    for (int i = 0; i < VIRUS_COUNT; i++) 
    {
        if (strstr(input, virusDatabase[i]) != NULL) 
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char input[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int result = mathFunction(strlen(input), MAX_STRING_LENGTH);

    if (isVirus(input)) 
    {
        printf("Error: Virus detected!\n");
    }
    else
    {
        printf("Result: %d\n", result);
    }

    return 0;
}