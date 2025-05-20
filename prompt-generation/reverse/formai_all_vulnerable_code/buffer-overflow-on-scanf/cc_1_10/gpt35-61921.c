//FormAI DATASET v1.0 Category: System boot optimizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* welcomeMsg = "Welcome to System Boot Optimizer!";
    char* optionMsg = "Which optimization would you like to perform?";
    char* option1 = "1) Remove unnecessary startup programs";
    char* option2 = "2) Check and repair disk errors";
    char* option3 = "3) Defragment hard drive";
    char* option4 = "4) Update system drivers";
    char* option5 = "5) Exit";

    printf("%s\n", welcomeMsg);
    printf("%s\n", optionMsg);
    printf("%s\n", option1);
    printf("%s\n", option2);
    printf("%s\n", option3);
    printf("%s\n", option4);
    printf("%s\n", option5);

    int choice = 0;
    scanf("%d", &choice);

    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                printf("Removing unnecessary startup programs...");
                // Code to remove startup programs goes here
                printf("Done!\n");
                break;
            case 2:
                printf("Checking and repairing disk errors...");
                // Code to check and repair disk errors goes here
                printf("Done!\n");
                break;
            case 3:
                printf("Defragmenting hard drive...");
                // Code to defragment hard drive goes here
                printf("Done!\n");
                break;
            case 4:
                printf("Updating system drivers...");
                // Code to update system drivers goes here
                printf("Done!\n");
                break;
            default:
                printf("Invalid choice! Please choose one of the options below:");
                break;
        }

        printf("%s\n", optionMsg);
        printf("%s\n", option1);
        printf("%s\n", option2);
        printf("%s\n", option3);
        printf("%s\n", option4);
        printf("%s\n", option5);

        scanf("%d", &choice);
    }

    printf("Exiting System Boot Optimizer. Have a nice day!\n");

    return 0;
}