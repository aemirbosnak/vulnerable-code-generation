//Gemma-7B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10

char passwords[MAX_PASSWORDS][100];
int num_passwords = 0;

void generate_password()
{
    char password[100];
    int i;

    printf("Enter a password: ");
    scanf("%s", password);

    if (num_passwords >= MAX_PASSWORDS)
    {
        printf("Error: maximum number of passwords exceeded.\n");
        return;
    }

    strcpy(passwords[num_passwords], password);
    num_passwords++;
}

void list_passwords()
{
    int i;

    if (num_passwords == 0)
    {
        printf("No passwords stored.\n");
        return;
    }

    printf("List of passwords:\n");
    for (i = 0; i < num_passwords; i++)
    {
        printf("%s\n", passwords[i]);
    }
}

int main()
{
    char command;

    printf("Enter 'g' to generate a password, 'l' to list passwords, or 'q' to quit: ");
    scanf(" %c", &command);

    switch (command)
    {
        case 'g':
            generate_password();
            break;
        case 'l':
            list_passwords();
            break;
        case 'q':
            exit(0);
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}