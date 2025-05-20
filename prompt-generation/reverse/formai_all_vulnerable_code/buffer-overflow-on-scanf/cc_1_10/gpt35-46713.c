//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *string);
void createPassword(char *password);
void printPassword(char *password);
void storePassword(char *database[][2], char *password);
int findIndex(char *database[][2], char *password);
void retrievePassword(char *database[][2], char *password);

int main()
{
    char *database[50][2];
    char password[100];

    createPassword(password);
    storePassword(database, password);
    retrievePassword(database, password);
    printPassword(password);

    return 0;
}

int hash(char *string)
{
    int index = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        index = index + (int) string[i];
    }

    return index;
}

void createPassword(char *password)
{
    printf("Enter your new password: ");
    scanf("%s", password);
}

void printPassword(char *password)
{
    printf("Your password is: %s", password);
}

void storePassword(char *database[][2], char *password)
{
    int index = hash(password) % 50;
    database[index][0] = password;
}

int findIndex(char *database[][2], char *password)
{
    int index = hash(password) % 50;
    return index;
}

void retrievePassword(char *database[][2], char *password)
{
    int index = findIndex(database, password);
    char *storedPassword = database[index][0];
    if (strcmp(password, storedPassword) == 0) {
        printf("Password found!\n");
    } else {
        printf("Password not found.\n");
    }
}