//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recurse(int);

int main()
{
    char password[30];
    printf("Enter password to access system administration: ");
    scanf("%s", password);

    if(strcmp(password, "uuddlrlrba") == 0) {
        printf("Password accepted!\n");
        recurse(5);
    } else {
        printf("Incorrect password.\n");
        exit(0);
    }

    return 0;
}

void recurse(int level)
{
    if(level <= 0) {
        printf("Access granted on Level 2!\n");
        printf("Welcome to the secret system administration page.\n");
        printf("What would you like to do?\n");
        printf("1. Reset system settings\n");
        printf("2. Backup system files\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("System settings have been reset.\n");
                break;
            case 2:
                printf("System files have been backed up.\n");
                break;
            case 3:
                printf("Exiting administration mode...\n");
                exit(0);
            default:
                printf("Invalid choice. Exiting...\n");
                exit(0);
        }
    } else {
        printf("Access Level %d cleared.\n", level);
        printf("Enter code: ");
        char code[30];
        scanf("%s", code);
        if(strcmp(code, "01357") == 0) {
            printf("Code accepted! Recursive call...\n");
            recurse(level-1);
        } else {
            printf("Incorrect code entered. Exiting...\n");
            exit(0);
        }
    }
}