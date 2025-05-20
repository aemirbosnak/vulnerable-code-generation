//Gemma-7B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main()
{
    system("clear");
    printf("Welcome to the Crazy Password Manager!\n");

    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);

    char password[20];
    printf("Enter your current password: ");
    scanf("%s", password);

    time_t t = time(NULL);
    srand(t);

    int r = rand() % 10;
    char secret_key[r + 1];
    for (int i = 0; i < r + 1; i++)
    {
        secret_key[i] = (char)rand() % 26 + 65;
    }

    char new_password[20];
    printf("Enter your new password: ");
    scanf("%s", new_password);

    char confirm_password[20];
    printf("Confirm your new password: ");
    scanf("%s", confirm_password);

    if (strcmp(new_password, confirm_password) == 0)
    {
        FILE *fp = fopen("passwords.txt", "a");
        fprintf(fp, "%s:%s:%s\n", username, new_password, secret_key);
        fclose(fp);

        printf("Your password has been changed successfully!\n");
    }
    else
    {
        printf("Error: Passwords do not match.\n");
    }

    sleep(2);
    system("clear");
    return 0;
}