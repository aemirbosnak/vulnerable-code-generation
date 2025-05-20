//FormAI DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*Declare our functions*/
bool passwordIsValid(char *masterPassword, char *password, char *hint);
bool passwordMatches(char *password, char *confirm_password);
bool containsCharacter(char *password,char c);
bool isFamousCharacter(char *name,char *password);
char* getRandomHint();

/* Define a famous characters struct */
struct famousCharacter {
    char name[30];
    char password[30];
};

/* Create a function that returns a random hint */
char* getRandomHint() {
    char* hints[] = {"The hint is the name of a flower",
                     "The hint is the year of a famous event in history",
                     "The hint is the name of a famous musician",
                     "The hint is the color of the sky in a beautiful evening"};
    int i = rand()%4;
    return hints[i];
}

/* Create an array of famous characters */
struct famousCharacter famousCharacters[5] ={
    {"Sherlock Holmes","Elementary"},
    {"Hercule Poirot","LittleGreycells"},
    {"John Watson","TheGameIsAfoot"},
    {"Miss Marple","CluesAreEverything"},
    {"Nancy Drew","SleuthForever"}
};

int main() {
    printf("Welcome to Password Manager 1.0\n\n");
    char masterPassword[30], password[30], confirm_password[30], hint[100];
    printf("Please enter your master password: ");
    scanf("%s", masterPassword);
    printf("\n");

    if (strlen(masterPassword) < 8 || !containsCharacter(masterPassword, '@') || !containsCharacter(masterPassword, '!')) {
        printf("Invalid Master Password! The master password must be at least 8 characters in length and should contain the characters '@' and '!'\n");
        return 0;
    }

    for (int i=0;i<5;i++) {
        if (isFamousCharacter(famousCharacters[i].name,masterPassword)) {
            printf("%s is not allowed as a master password!\n", famousCharacters[i].name);
            return 0;
        }
    }

    int retry = 3;
    do {
        printf("Please enter a new password: ");
        scanf("%s", password);
        printf("\n");

        if (strlen(password) < 8 || !containsCharacter(password, '@') || !containsCharacter(password, '!')) {
            printf("Invalid Password! The password must be at least 8 characters in length and should contain the characters '@' and '!'\n");
            continue;
        }

        printf("Please re-enter your password: ");
        scanf("%s", confirm_password);
        printf("\n");

        if (!passwordMatches(password, confirm_password)) {
            printf("The passwords do not match!\n");
            continue;
        }

        printf("Please enter a hint for your new password: ");
        scanf(" %[^\n]s", hint);
        printf("\n");

    } while (!passwordIsValid(masterPassword, password, hint) && (--retry > 0));

    if (retry == 0) {
        printf("Max number of attempts reached. Please try again later!\n");
        return 0;
    }

    printf("Password Set Successfully!\n");

    return 0;
}

/* Function to check if the master password is not a famous character */
bool isFamousCharacter(char *name,char *password) {
    if (strstr(password,name) != NULL) {
        return true;
    }
    return false;
}

/* Function to check if password contains a certain character */
bool containsCharacter(char *password,char c) {
    for(int i=0; i<strlen(password);i++) {
        if(password[i] == c) {
            return true;
        }
    }
    return false;
}

/* Function to check if the password is valid */
bool passwordIsValid(char *masterPassword, char *password, char *hint) {
    if (strstr(masterPassword, password) != NULL) {
        printf("Invalid password! The password should not contain the master password\n");
        return false;
    }
    if (isFamousCharacter(hint,masterPassword)) {
        printf("Invalid hint! The hint must not contain the master password or any famous character\n");
        return false;
    }
    for (int i=0;i<5;i++) {
        if (isFamousCharacter(famousCharacters[i].name,password)) {
            printf("Invalid Password! The password should not contain %s\n", famousCharacters[i].name);
            return false;
        }
    }
    printf("Your hint is: %s\n", getRandomHint());
    return true;
}

/* Function to check if passwords match */
bool passwordMatches(char *password, char *confirm_password) {
    if (strcmp(password, confirm_password) == 0) {
        return true;
    }
    return false;
}