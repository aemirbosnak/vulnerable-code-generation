//Gemma-7B DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sys_admin(char **argv)
{
    char command[255];
    printf("Enter a command: ");
    scanf("%s", command);

    if (strcmp(command, "adduser") == 0)
    {
        printf("Enter the user's name: ");
        char name[255];
        scanf("%s", name);

        printf("Enter the user's password: ");
        char password[255];
        scanf("%s", password);

        // Add user to system
        FILE *fp = fopen("/etc/passwd", "a");
        fprintf(fp, "%s:x:%d:1001::/home/%s/%s\n", name, 1001, name, password);
        fclose(fp);

        printf("User added successfully.\n");
    }
    else if (strcmp(command, "removeuser") == 0)
    {
        printf("Enter the user's name: ");
        char name[255];
        scanf("%s", name);

        // Remove user from system
        FILE *fp = fopen("/etc/passwd", "r");
        char line[255];
        int found = 0;
        while (fgets(line, 255, fp) != NULL)
        {
            if (strcmp(line, name) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(fp);

        if (found)
        {
            FILE *fp = fopen("/etc/passwd", "w");
            char *buf = NULL;
            int size = 0;
            rewind(fp);
            while (fgets(line, 255, fp) != NULL)
            {
                if (strcmp(line, name) != 0)
                {
                    buf = realloc(buf, size + 1);
                    buf[size++] = line[0];
                }
            }
            fprintf(fp, "%s", buf);
            fclose(fp);

            printf("User removed successfully.\n");
        }
        else
        {
            printf("User not found.\n");
        }
    }
    else if (strcmp(command, "listusers") == 0)
    {
        // List users from system
        FILE *fp = fopen("/etc/passwd", "r");
        char line[255];
        printf("Users:\n");
        while (fgets(line, 255, fp) != NULL)
        {
            printf("%s\n", line);
        }
        fclose(fp);
    }
    else
    {
        printf("Invalid command.\n");
    }
}

int main(int argc, char **argv)
{
    sys_admin(argv);

    return 0;
}