//Gemma-7B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 255

int main()
{
    char cmd[MAX_CMD_LEN];
    int i = 0;
    FILE *fp;

    printf("Welcome to the serene C System Administration Terminal.\n");

    // Loop until the user enters "quit"
    while (strcmp(cmd, "quit") != 0)
    {
        // Get the user command
        printf("Enter a command: ");
        scanf("%s", cmd);

        // Check if the command is valid
        if (strcmp(cmd, "list") == 0)
        {
            fp = fopen("system.txt", "r");
            if (fp)
            {
                // Read the system file and print its contents
                while ((i = fgets(cmd, MAX_CMD_LEN, fp)) != NULL)
                {
                    printf("%s", cmd);
                }
                fclose(fp);
            }
        }
        else if (strcmp(cmd, "add") == 0)
        {
            // Get the new command to add
            printf("Enter the new command: ");
            scanf("%s", cmd);

            // Append the command to the system file
            fp = fopen("system.txt", "a");
            if (fp)
            {
                fprintf(fp, "%s\n", cmd);
                fclose(fp);
            }
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            // Get the command to remove
            printf("Enter the command to remove: ");
            scanf("%s", cmd);

            // Remove the command from the system file
            fp = fopen("system.txt", "r");
            if (fp)
            {
                char line[MAX_CMD_LEN];
                int found = 0;
                while ((i = fgets(line, MAX_CMD_LEN, fp)) != NULL)
                {
                    if (strcmp(line, cmd) == 0)
                    {
                        found = 1;
                        continue;
                    }
                    fprintf(fp, "%s", line);
                }
                fclose(fp);

                if (!found)
                {
                    printf("Error: command not found.\n");
                }
            }
        }
        else
        {
            printf("Invalid command.\n");
        }

        // Clear the command buffer
        memset(cmd, 0, MAX_CMD_LEN);
    }

    printf("Thank you for using the serene C System Administration Terminal.\n");

    return 0;
}