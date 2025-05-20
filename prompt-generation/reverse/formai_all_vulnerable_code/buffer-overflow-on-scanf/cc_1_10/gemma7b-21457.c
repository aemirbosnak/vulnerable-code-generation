//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("           /\n"
           "\/ \__)_\n"
           " \__) \__)\n"
           "  \__) \__)\n"
           "   \__) \__)\n"
           "    \__) \__)\n"
           "     \__) \__)\n"
           "  /|__) \__)\n"
           " |/__) \__)\n"
           " \|__) \__)\n"
           "  \__) \__)\n"
           " \__) \__)\n"
           " \__) \__)\n"
           " \__) \__)\n"
           " \__) \__)\n"
           " \__) \__)\n"
           " \__) \__)\n");

    printf("Welcome to the C Phone Book!\n");
    printf("Please enter the name of the person you want to find:");

    char name[20];
    scanf("%s", name);

    FILE *phoneBook = fopen("phonebook.txt", "r");
    char line[1024];

    while (fgets(line, 1024, phoneBook) != NULL)
    {
        char *firstName = strchr(line, ' ');
        char *phoneNumber = strchr(line, ':');

        if (strcmp(firstName, name) == 0)
        {
            printf("Phone number: %s\n", phoneNumber);
            break;
        }
    }

    fclose(phoneBook);

    printf("Sorry, the person you are looking for was not found.\n");

    return 0;
}