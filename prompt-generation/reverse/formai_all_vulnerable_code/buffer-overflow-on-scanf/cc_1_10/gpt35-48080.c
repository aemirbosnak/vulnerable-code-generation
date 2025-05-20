//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PASSWORD_LENGTH 20
#define MAX_TRIES 3

// Function prototypes
void generatePassword(char password[MAX_PASSWORD_LENGTH+1], int length);
void testPassword(char password[MAX_PASSWORD_LENGTH+1], int tries);
void setPassword(char password[MAX_PASSWORD_LENGTH+1], int length);
void changePassword(char password[MAX_PASSWORD_LENGTH+1], int tries);

int main(){
    char password[MAX_PASSWORD_LENGTH+1];
    int choice, length, tries;
    printf("Enter password length: ");
    scanf("%d", &length);
    generatePassword(password, length);
    do{
        printf("\nPassword Management System\n");
        printf("1. Test Password\n");
        printf("2. Set Password\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nTesting Password...\n");
                testPassword(password, MAX_TRIES);
                break;
            case 2:
                printf("\nSetting Password...\n");
                setPassword(password, length);
                break;
            case 3:
                printf("\nChanging Password...\n");
                changePassword(password, MAX_TRIES);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }while(choice != 4);
    return 0;
}

void generatePassword(char password[MAX_PASSWORD_LENGTH+1], int length){
    int i;
    for(i=0;i<length;i++){
        password[i] = (char)((rand() % 94) + 33);
    }
    password[length] = '\0';
    printf("Generated Password: %s\n", password);
}

void testPassword(char password[MAX_PASSWORD_LENGTH+1], int tries){
    char guess[MAX_PASSWORD_LENGTH+1];
    int attempt = 0;
    do{
        attempt++;
        printf("Attempt #%d: ", attempt);
        scanf("%s", guess);
        if(strcmp(guess, password) == 0){
            printf("You have successfully logged in.\n");
            return;
        }
        printf("Wrong password. Please try again.\n");
    }while(attempt < tries);
    printf("You have failed to login after %d attempts. Exiting...\n", tries);
}

void setPassword(char password[MAX_PASSWORD_LENGTH+1], int length){
    char new_password[MAX_PASSWORD_LENGTH+1];
    int i;
    printf("Enter new password (length %d): ", length);
    scanf("%s", new_password);
    if(strlen(new_password) != length){
        printf("Invalid password length. Password must be exactly %d characters long.\n", length);
        return;
    }
    for(i=0;i<length;i++){
        if(new_password[i] < 33 || new_password[i] > 126){
            printf("Invalid character '%c'. Password must contain only printable ascii characters.\n", new_password[i]);
            return;
        }
    }
    strcpy(password, new_password);
    printf("Password successfully set.\n");
}

void changePassword(char password[MAX_PASSWORD_LENGTH+1], int tries){
    char new_password[MAX_PASSWORD_LENGTH+1];
    int i, attempt = 0;
    do{
        attempt++;
        printf("Attempt #%d: ", attempt);
        scanf("%s", new_password);
        if(strcmp(new_password, password) == 0){
            printf("Enter new password (length %d): ", strlen(password));
            scanf("%s", new_password);
            if(strlen(new_password) != strlen(password)){
                printf("Invalid password length. Password must be exactly %d characters long.\n", strlen(password));
                continue;
            }
            for(i=0;i<strlen(password);i++){
                if(new_password[i] < 33 || new_password[i] > 126){
                    printf("Invalid character '%c'. Password must contain only printable ascii characters.\n", new_password[i]);
                    continue;
                }
            }
            strcpy(password, new_password);
            printf("Password successfully changed.\n");
            return;
        }
        printf("Wrong password. Please try again.\n");
    }while(attempt < tries);
    printf("You have failed to authenticate after %d attempts. Exiting...\n", tries);
}