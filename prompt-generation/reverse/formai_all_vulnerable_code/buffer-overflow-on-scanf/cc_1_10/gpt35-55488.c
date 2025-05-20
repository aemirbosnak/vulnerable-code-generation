//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LEN 20 /* Maximum length of the generated password */
#define ALPHA_NUM 62 /* Total number of alphanumeric characters */

/* Function to check if a character is uppercase */
int isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

/* Function to check if a character is lowercase */
int isLowerCase(char c) {
    return (c >= 'a' && c <= 'z');
}

/* Function to check if a character is a digit */
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

/* Function to generate a random password */
char* generatePassword(int len) {
    char *password = (char*)malloc(sizeof(char) * len);
    int i = 0, j = 0;
    char c;

    /* Use current time as seed for the random number generator */
    srand(time(0));

    /* Generate random characters for the password */
    while (i < len) {
        c = rand() % ALPHA_NUM;
        
        if (c < 26) { /* Uppercase characters */
            password[i++] = 'A' + c;
        } else if (c < 52) { /* Lowercase characters */
            password[i++] = 'a' + (c - 26);
        } else { /* Digits */
            password[i++] = '0' + (c - 52);
        }
    }

    password[len] = '\0'; /* Set NULL terminator */

    return password;
}

int main() {
    int len = 0;
    char *password = NULL;

    printf("Enter the length of the password: ");
    scanf("%d", &len);

    if (len <= 0 || len > MAX_LEN) {
        printf("Invalid password length.\n");
        return 1;
    }

    /* Generate the password */
    password = generatePassword(len);

    printf("Generated password: %s\n", password);

    free(password); /* Free memory allocated for password */
    password = NULL; /* Set pointer to NULL to avoid dangling pointer */

    return 0;
}