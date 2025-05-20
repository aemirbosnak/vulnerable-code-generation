//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() //function to display the menu
{
    printf("\n-------Welcome to the Medieval File Handling-------\n");
    printf("\n1. Create a new player profile");
    printf("\n2. View a player profile");
    printf("\n3. Update a player profile");
    printf("\n4. Delete a player profile");
    printf("\n5. Exit");
}

void createProfile() //function to create a new player's profile
{
    char playerName[20], playerClass[10];
    int playerLevel, playerScore;
    FILE *fp;
    fp = fopen("playerprofiles.txt", "a"); //opening the file in append mode

    printf("\nEnter the name of the player: ");
    scanf("%s", playerName);

    printf("Enter the class of the player: ");
    scanf("%s", playerClass);

    printf("Enter the level of the player: ");
    scanf("%d", &playerLevel);

    printf("Enter the score of the player: ");
    scanf("%d", &playerScore);

    fprintf(fp, "%s %s %d %d\n", playerName, playerClass, playerLevel, playerScore); //writing the data to the file

    printf("\nPlayer profile created successfully!");
    fclose(fp);
}

void viewProfile() //function to view an existing player's profile
{
    char playerName[20], playerClass[10];
    int playerLevel, playerScore, flag = 0;
    FILE *fp;

    fp = fopen("playerprofiles.txt", "r"); //opening the file in read mode

    printf("\nEnter the name of the player whose profile you want to view: ");
    scanf("%s", playerName);

    while(fscanf(fp, "%s %s %d %d\n", playerName, playerClass, &playerLevel, &playerScore) != EOF) //scanning the file for the player's profile
    {
        if(strcmp(playerName, playerName) == 0)
        {
            printf("\nName: %s\nClass: %s\nLevel: %d\nScore: %d\n", playerName, playerClass, playerLevel, playerScore); //displaying the player's profile
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("\nSorry, profile not found!");
    }

    fclose(fp);
}

void updateProfile() //function to update an existing player's profile
{
    char playerName[20], playerClass[10], choice;
    int playerLevel, playerScore, flag = 0;
    FILE *fp, *temp;

    fp = fopen("playerprofiles.txt", "r"); //opening the file in read mode
    temp = fopen("temp.txt", "w"); //opening a temporary file in write mode

    printf("\nEnter the name of the player whose profile you want to update: ");
    scanf("%s", playerName);

    while(fscanf(fp, "%s %s %d %d\n", playerName, playerClass, &playerLevel, &playerScore) != EOF) //scanning the file for the player's profile
    {
        if(strcmp(playerName, playerName) == 0)
        {
            printf("\nCurrent profile details: \nName: %s\nClass: %s\nLevel: %d\nScore: %d\n", playerName, playerClass, playerLevel, playerScore); //displaying the player's profile
            flag = 1;

            printf("\nDo you want to update the name? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y')
            {
                printf("Enter the new name: ");
                scanf("%s", playerName);
            }

            printf("\nDo you want to update the class? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y')
            {
                printf("Enter the new class: ");
                scanf("%s", playerClass);
            }

            printf("\nDo you want to update the level? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y')
            {
                printf("Enter the new level: ");
                scanf("%d", &playerLevel);
            }

            printf("\nDo you want to update the score? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y')
            {
                printf("Enter the new score: ");
                scanf("%d", &playerScore);
            }

            fprintf(temp, "%s %s %d %d\n", playerName, playerClass, playerLevel, playerScore); //writing the updated data to the temporary file
            printf("\nPlayer profile updated successfully!");
        }
        else
        {
            fprintf(temp, "%s %s %d %d\n", playerName, playerClass, playerLevel, playerScore); //writing the unchanged data to the temporary file
        }
    }

    if(flag == 0)
    {
        printf("\nSorry, profile not found!");
    }

    fclose(fp);
    fclose(temp);
    remove("playerprofiles.txt"); //deleting the original file
    rename("temp.txt", "playerprofiles.txt"); //renaming the temporary file to the original file name
}

void deleteProfile() //function to delete an existing player's profile
{
    char playerName[20], playerClass[10];
    int playerLevel, playerScore, flag = 0;
    FILE *fp, *temp;

    fp = fopen("playerprofiles.txt", "r"); //opening the file in read mode
    temp = fopen("temp.txt", "w"); //opening a temporary file in write mode

    printf("\nEnter the name of the player whose profile you want to delete: ");
    scanf("%s", playerName);

    while(fscanf(fp, "%s %s %d %d\n", playerName, playerClass, &playerLevel, &playerScore) != EOF) //scanning the file for the player's profile
    {
        if(strcmp(playerName, playerName) == 0)
        {
            flag = 1;
            printf("\nProfile deleted successfully!");
        }
        else
        {
            fprintf(temp, "%s %s %d %d\n", playerName, playerClass, playerLevel, playerScore); //writing the unchanged data to the temporary file
        }
    }

    if(flag == 0)
    {
        printf("\nSorry, profile not found!");
    }

    fclose(fp);
    fclose(temp);
    remove("playerprofiles.txt"); //deleting the original file
    rename("temp.txt", "playerprofiles.txt"); //renaming the temporary file to the original file name
}

int main()
{
    int choice;
    do
    {
        displayMenu(); //calling the function to display the menu
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createProfile(); //calling the function to create a new player's profile
                    break;

            case 2: viewProfile(); //calling the function to view an existing player's profile
                    break;

            case 3: updateProfile(); //calling the function to update an existing player's profile
                    break;

            case 4: deleteProfile(); //calling the function to delete an existing player's profile
                    break;

            case 5: printf("\nThank you for using Medieval File Handling. Bye!"); //exiting the program
                    break;

            default: printf("\nInvalid choice. Please try again!"); //handling invalid choices
                     break;
        }
    } while(choice != 5);

    return 0;
}