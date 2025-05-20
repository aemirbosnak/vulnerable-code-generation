//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct{
    char password[MAX_PASSWORD_LENGTH + 1];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* newPass){
    if(numPasswords == MAX_PASSWORDS){
        printf("Error: There cannot be more than %d passwords", MAX_PASSWORDS);
        return;
    }

    if(strlen(newPass) > MAX_PASSWORD_LENGTH){
        printf("Error: Password too long. Maximum length is %d characters", MAX_PASSWORD_LENGTH);
        return;
    }

    Password newPassStruct;

    strcpy(newPassStruct.password, newPass);

    passwords[numPasswords++] = newPassStruct;

    printf("Password added successfully\n");
}

void printPasswords(){
    printf("Passwords:\n");

    for(int i = 0; i < numPasswords; ++i){
        printf("%d. %s\n", i + 1, passwords[i].password);
    }
}

int main(){
    char password[MAX_PASSWORD_LENGTH + 1];

    while(1){
        int choice;

        printf("Choose option:\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter new password: ");
                scanf("%s", password);
                addPassword(password);
                break;
            case 2:
                printPasswords();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}