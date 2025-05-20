//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX 1000
#define MASTER_PASS "123456789"

int main()
{
    char website[MAX], username[MAX], password[MAX], master[MAX];
    int ch, count; 
    FILE *fileptr;
    fileptr = fopen("database.txt", "a+");
    if (fileptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    printf("\nEnter the master password: ");
    fgets(master, MAX, stdin);
    if (strcmp(master, MASTER_PASS) != 0)
    {
        printf("\nInvalid master password");
        exit(1);
    }
    printf("\nChoose an option:\n1. Store password for a new website\n2. Retrieve password for an existing website\n");
    scanf("%d", &ch);
    fgetc(stdin); //clearing input buffer
    switch(ch)
    {
        case 1:
            printf("\nEnter website name: ");
            fgets(website, MAX, stdin);
            printf("Enter username: ");
            fgets(username, MAX, stdin);
            do
            {
                count = 0;
                printf("Enter password: ");
                fgets(password, MAX, stdin);
                for (int i = 0; i < strlen(password); i++)
                {
                    if (isdigit(password[i]) || isalpha(password[i]))
                    {
                        count++;
                    }
                }
                if (count < 6 || count > 16)
                {
                    printf("The password must be 6-16 characters long and contain only letters and digits.\n");
                }
            } while (count < 6 || count > 16);
            printf("\nPassword saved successfully.\n");
            fprintf(fileptr, "%s%s%s", website, username, password);
            break;

        case 2:
            printf("\nEnter the website name: ");
            fgets(website, MAX, stdin);
            char line[150], found = 0;
            while (fgets(line, 150, fileptr) != NULL)
            {
                if (strstr(line, website) != NULL)
                {
                    printf("\n%s", line);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nWebsite not found.");
            }
            break;

        default:
            printf("\nInvalid choice");
    }
    fclose(fileptr);
    return 0;
}