//Gemma-7B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Firewall!\n");
    printf("Please enter the command: ");

    char command[100];
    scanf("%s", command);

    // Check if the command is a valid one
    if (strcmp(command, "list") == 0)
    {
        printf("Here is a list of files:\n");
        FILE *fp;
        fp = fopen("files.txt", "r");
        char file[100];
        while (fscanf(fp, "%s", file) != EOF)
        {
            printf("%s\n", file);
        }
        fclose(fp);
    }
    else if (strcmp(command, "add") == 0)
    {
        printf("Please enter the file name: ");
        char filename[100];
        scanf("%s", filename);

        FILE *fp;
        fp = fopen("files.txt", "a");
        fprintf(fp, "%s\n", filename);
        fclose(fp);

        printf("File added successfully!\n");
    }
    else if (strcmp(command, "remove") == 0)
    {
        printf("Please enter the file name: ");
        char filename[100];
        scanf("%s", filename);

        FILE *fp;
        fp = fopen("files.txt", "r");
        char file[100];
        int i = 0;
        while (fscanf(fp, "%s", file) != EOF)
        {
            if (strcmp(file, filename) == 0)
            {
                printf("File removed successfully!\n");
                break;
            }
            i++;
        }
        fclose(fp);

        if (i == 0)
        {
            printf("Error: file not found.\n");
        }
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}