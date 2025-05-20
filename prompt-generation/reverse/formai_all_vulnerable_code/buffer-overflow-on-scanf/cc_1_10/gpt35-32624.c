//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

void addPassword(char password[][MAX_SIZE], int *size)
{
    char input[MAX_SIZE];
    printf("Enter new password: ");
    fgets(input, MAX_SIZE, stdin);
    strtok(input, "\n");
    if (*size >= MAX_SIZE)
    {
        printf("Maximum number of passwords exceeded!\n");
        return;
    }
    strcpy(password[*size], input);
    (*size)++;
}

void removePassword(char password[][MAX_SIZE], int *size)
{
    char input[MAX_SIZE];
    printf("Enter password to remove: ");
    fgets(input, MAX_SIZE, stdin);
    strtok(input, "\n");
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(password[i], input) == 0)
        {
            for (int j = i; j < *size - 1; j++)
            {
                strcpy(password[j], password[j+1]);
            }
            (*size)--;
            printf("Password removed successfully.\n");
            return;
        }
    }
    printf("Password not found.\n");
}

void viewPasswords(char password[][MAX_SIZE], int size)
{
    printf("Password List: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s\n", i+1, password[i]);
    }
}

int main()
{
    int choice, size = 0;
    char password[MAX_SIZE][MAX_SIZE];
    do {
        printf("\nPassword Manager Menu\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer
        switch (choice)
        {
            case 1:
                addPassword(password, &size);
                break;
            case 2:
                removePassword(password, &size);
                break;
            case 3:
                viewPasswords(password, size);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}