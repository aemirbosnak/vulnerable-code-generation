//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
int is_upper(char c);
int is_lower(char c);
int is_digit(char c);
char get_random_upper(void);
char get_random_lower(void);
char get_random_digit(void);
char generate_random_char(void);
void generate_password(char *password, int length);

/* main function */
int main(void) {
    int length;
    char *password;
    
    /* get password length from user */
    printf("Enter password length (must be between 8 and 32): ");
    scanf("%d", &length);
    
    /* validate password length */
    if (length < 8 || length > 32) {
        printf("Invalid password length! Password must be between 8 and 32 characters long.\n");
        return EXIT_FAILURE;
    }
    
    /* allocate memory for password */
    password = (char *) malloc(length * sizeof(char));
    
    /* generate password */
    generate_password(password, length);
    
    /* print password */
    printf("Your password is: %s\n", password);
    
    /* free memory */
    free(password);
    
    return EXIT_SUCCESS;
}

/*
 * Check if a character is an uppercase letter.
 */
int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

/*
 * Check if a character is a lowercase letter.
 */
int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

/*
 * Check if a character is a digit.
 */
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

/*
 * Return a random uppercase letter.
 */
char get_random_upper(void) {
    return (char) ('A' + rand() % 26);
}

/*
 * Return a random lowercase letter.
 */
char get_random_lower(void) {
    return (char) ('a' + rand() % 26);
}

/*
 * Return a random digit.
 */
char get_random_digit(void) {
    return (char) ('0' + rand() % 10);
}

/*
 * Generate a random character.
 */
char generate_random_char(void) {
    char c;
    int choice;
    
    /* generate random number between 0 and 2 */
    choice = rand() % 3;
    
    /* select character type based on choice */
    switch (choice) {
        case 0:
            c = get_random_upper();
            break;
        case 1:
            c = get_random_lower();
            break;
        case 2:
            c = get_random_digit();
            break;
        default:
            c = '\0';
    }
    
    return c;
}

/*
 * Generate a random password.
 */
void generate_password(char *password, int length) {
    int i;
    char c;
    
    /* seed random number generator */
    srand((unsigned int) time(NULL));
    
    /* generate random characters for password */
    for (i = 0; i < length; i++) {
        c = generate_random_char();
        
        /* make sure password meets criteria */
        if (i == 0 || i == length - 1) {
            while (!is_upper(c) && !is_lower(c)) {
                c = generate_random_char();
            }
        } else {
            while (!is_upper(c) && !is_lower(c) && !is_digit(c)) {
                c = generate_random_char();
            }
        }
        
        /* add character to password */
        password[i] = c;
    }
    
    /* add null terminator to password */
    password[length] = '\0';
}