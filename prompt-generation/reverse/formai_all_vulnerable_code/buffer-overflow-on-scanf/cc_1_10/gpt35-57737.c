//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define PASSWORD_LENGTH 8

void generate_random_password(char *password);
int is_password_valid(char *password);

int main(){
    char password[PASSWORD_LENGTH+1];
    int choice, loop = 1;

    while(loop){
        // Menu options
        printf("\n1. Generate new password\n");
        printf("2. Check if a password is valid\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                generate_random_password(password);
                printf("\nNew Password: %s\n", password);
                break;
            case 2:
                printf("\nEnter password to check: ");
                scanf("%s", password);
                if(is_password_valid(password))
                    printf("\nValid Password\n");
                else
                    printf("\nInvalid Password\n");
                break;
            case 3:
                printf("\nExiting...\n\n");
                loop = 0;
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}

// Function to generate a random password
void generate_random_password(char *password){
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;':\",.<>/?";
    const int charset_length = strlen(charset);
    int i;

    for(i = 0; i < PASSWORD_LENGTH; i++){
        password[i] = charset[rand() % charset_length];
    }
    password[i] = '\0';
}

// Function to validate a password
int is_password_valid(char *password){
    int length = strlen(password);
    int i, has_lowercase = 0, has_uppercase = 0, has_digit = 0, has_special = 0;

    if(length < PASSWORD_LENGTH)
        return 0;

    for(i = 0; i < length; i++){
        if(password[i] >= 'a' && password[i] <= 'z')
            has_lowercase = 1;
        else if(password[i] >= 'A' && password[i] <= 'Z')
            has_uppercase = 1;
        else if(password[i] >= '0' && password[i] <= '9')
            has_digit = 1;
        else
            has_special = 1;
    }

    if(has_lowercase && has_uppercase && has_digit && has_special)
        return 1;
    else
        return 0;
}