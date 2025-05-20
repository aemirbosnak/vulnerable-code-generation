//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum number of characters in username and password */
#define MAX_CHAR 50

/* function to authenticate user */
void authenticateUser(char username[], char password[])
{
    char validUsername[] = "admin";     // valid username
    char validPassword[] = "password";  // valid password

    if(strcmp(validUsername, username) == 0 && strcmp(validPassword, password) == 0)
    {
        printf("\nAuthentication successful!\n");
    }
    else
    {
        printf("\nAuthentication failed!\n");
    }
}

/* function to detect intrusion */
void intrusionDetection(char username[])
{
    printf("\nIntrusion attempt detected!\n");
    printf("Username: %s\n", username);
}

/* main function */
int main()
{
    char username[MAX_CHAR];
    char password[MAX_CHAR];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    /* check if username contains any illegal characters */
    if(strpbrk(username, "<>@!#$%^&*()+={}[]|\\/?~`")==NULL)
    {
        authenticateUser(username, password);
    }
    else
    {
        intrusionDetection(username);
    }

    return 0;
}