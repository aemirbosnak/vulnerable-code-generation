//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

int isVirus(char *fileName);
int getChoice();

int main(void)
{
    printf("Welcome to the Medieval Antivirus Scanner!\n\n");

    int choice = getChoice();
    while(choice != 3)
    {
        switch(choice)
        {
            case 1:
                printf("Enter the name of the file to scan: ");
                char fileName[100];
                scanf("%s", fileName);
                if(isVirus(fileName))
                {
                    printf("Virus detected in file '%s'!\n\n", fileName);
                }
                else
                {
                    printf("No viruses detected in file '%s'.\n\n", fileName);
                }
                break;

            case 2:
                printf("Sorry, our Medieval Antivirus Scanner does not support scanning entire systems yet. Try scanning individual files.\n\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }

        choice = getChoice();
    }

    printf("Goodbye!\n");

    return 0;
}

int isVirus(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Could not open file '%s' for scanning.\n", fileName);
        return 0;
    }

    char fileContents[MAX_FILE_SIZE];
    fread(fileContents, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    if(strstr(fileContents, "medievalvirus") != NULL)
    {
        return 1;
    }

    return 0;
}

int getChoice()
{
    printf("What would you like to do?\n");
    printf("1. Scan a file\n");
    printf("2. Scan entire system\n");
    printf("3. Quit\n\n");

    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    return choice;
}