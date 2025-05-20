//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Cat Language dictionary
char *catDict[] = {"meow", "purr", "hiss", "scratch", "treat", "nap"};

// English Language dictionary
char *engDict[] = {"Hello", "How are you?", "What's wrong?", "Stop it!", "Can I have some food?", "Want to take a nap?"};

// Function to translate from Cat Language to English Language
void catToEng(char *catStr)
{
    int i, flag = 0;

    for (i = 0; i < 6; i++)
    {
        if (strcmp(catStr, catDict[i]) == 0)
        {
            printf("%s\n", engDict[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Sorry, I cannot understand what the cat is saying.\n");
    }
}

// Function to translate from English Language to Cat Language
void engToCat(char *engStr)
{
    int i, flag = 0;

    for (i = 0; i < 6; i++)
    {
        if (strcmp(engStr, engDict[i]) == 0)
        {
            printf("%s\n", catDict[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Sorry, I cannot understand what you are saying in English.\n");
    }
}

// Main function to run the translator program
int main()
{
    int option;
    char str[50];

    printf("Welcome to the Cat Language Translator!\n");
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Translate from Cat Language to English Language\n");
        printf("2. Translate from English Language to Cat Language\n");
        printf("3. Exit the program\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
            case 1:
                printf("\nEnter the cat's message: ");
                fgets(str, 50, stdin);
                str[strlen(str)-1] = '\0';
                catToEng(str);
                break;
            
            case 2:
                printf("\nEnter your message in English: ");
                fgets(str, 50, stdin);
                str[strlen(str)-1] = '\0';
                engToCat(str);
                break;
            
            case 3:
                printf("\nThank you for using the Cat Language Translator!\n");
                return 0;
            
            default:
                printf("\nInvalid option! Please choose again.\n");
                break;
        }
    }
    return 0;
}