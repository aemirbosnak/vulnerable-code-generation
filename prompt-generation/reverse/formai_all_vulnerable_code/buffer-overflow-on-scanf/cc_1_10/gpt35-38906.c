//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hi! Welcome to my happy file handling program!\n");
    printf("What would you like to do today? Press 1 to write into a file or press 2 to read from a file.\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You chose to write into a file! Let's get started!\n");

        FILE *filePointer;

        filePointer = fopen("myHappyFile.txt", "w");

        if (filePointer == NULL)
        {
            printf("Oops! Something went wrong while creating the file!\n");
            exit(0);
        }

        printf("What would you like to write into the file?\n");

        char data[100];
        scanf(" %[^\n]*%s", data);

        fprintf(filePointer, "%s\n", data);

        fclose(filePointer);

        printf("Yay! Data successfully written into the file!\n");
    }
    else if (choice == 2)
    {
        printf("You chose to read from a file! Let's get started!\n");

        FILE *filePointer;

        filePointer = fopen("myHappyFile.txt", "r");

        if (filePointer == NULL)
        {
            printf("Oops! Something went wrong while opening the file!\n");
            exit(0);
        }

        char data[100];
        fgets(data, 100, filePointer);

        printf("The data in the file is: %s\n", data);

        fclose(filePointer);

        printf("Yay! Data successfully read from the file!\n");
    }
    else
    {
        printf("Sorry, that was an invalid choice. Please try again.\n");
    }

    printf("Thank you for using my happy file handling program! Have a fantastic day!\n");

    return 0;
}