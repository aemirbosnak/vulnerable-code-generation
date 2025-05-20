//FormAI DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Fun Image Editor!\n");

    char filename[50];
    printf("Enter the name of the image to edit: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Could not open file %s. Exiting...\n", filename);
        exit(1);
    }

    printf("Successfully opened file: %s\n", filename);

    printf("Choose the editing option:\n");
    printf("1. Add emoji\n");
    printf("2. Add speech bubble\n");
    printf("3. Add cat ears\n");
    printf("4. Add sunglasses\n");
    printf("5. Quit\n");

    int choice;
    scanf("%d", &choice);

    char output[50];
    switch(choice)
    {
        case 1:
            printf("Adding emoji to image...\n");
            sprintf(output, "emoji_%s", filename);
            break;
        case 2:
            printf("Adding speech bubble to image...\n");
            sprintf(output, "speech_%s", filename);
            break;
        case 3:
            printf("Adding cat ears to image...\n");
            sprintf(output, "cat_%s", filename);
            break;
        case 4:
            printf("Adding sunglasses to image...\n");
            sprintf(output, "sunglasses_%s", filename);
            break;
        case 5:
            printf("Quitting...\n");
            exit(0);
        default:
            printf("Invalid choice, exiting...\n");
            exit(1);
    }

    char command[100];
    sprintf(command, "cp %s %s", filename, output);
    system(command);
    printf("Successfully created output file: %s\n", output);

    printf("Want to edit some more images? Enter Y or N: ");
    char ans[5];
    scanf("%s", ans);
    if(strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0)
    {
        main();
    }
    else
    {
        printf("Thanks for using the Fun Image Editor. Goodbye!\n");
        exit(0);
    }

    return 0;
}