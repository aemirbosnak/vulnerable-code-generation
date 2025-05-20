//FormAI DATASET v1.0 Category: Data validation ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/* function prototypes */
bool validate_name(char *);
bool validate_age(int);
bool validate_phone(char *);
bool validate_email(char *);

int main(void) {

    char name[25], phone[15], email[50];
    int age;

    printf("Please enter your name: ");
    fgets(name, 25, stdin);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your phone number: ");
    scanf("%s", phone);

    printf("Please enter your email address: ");
    scanf("%s", email);

    if (!validate_name(name)) {
        printf("\nInvalid name. Please enter a valid name.\n");
        return 1;
    }

    if (!validate_age(age)) {
        printf("\nInvalid age. Please enter a valid age.\n");
        return 1;
    }

    if (!validate_phone(phone)) {
        printf("\nInvalid phone number. Please enter a valid phone number.\n");
        return 1;
    }

    if (!validate_email(email)) {
        printf("\nInvalid email address. Please enter a valid email address.\n");
        return 1;
    }

    printf("\nThank you for entering your information.\n");

    return 0;
}

/*
 * Function to validate name
 * Returns true if name is valid, false otherwise
 */
bool validate_name(char *name) {
    int i;
    char c;

    for (i = 0; name[i] != '\0'; i++) {
        c = name[i];

        /* check if character is alphabet or space */
        if (!(isalpha(c) || isspace(c))) {
            return false;
        }
    }

    /* check if there is at least one alphabet in the name */
    for (i = 0; name[i] != '\0'; i++) {
        if (isalpha(name[i])) {
            return true;
        }
    }

    return false;
}

/*
 * Function to validate age
 * Returns true if age is valid, false otherwise
 */
bool validate_age(int age) {
    if (age < 0 || age > 120) {
        return false;
    }

    return true;
}

/*
 * Function to validate phone number
 * Returns true if phone number is valid, false otherwise
 */
bool validate_phone(char *phone) {
    int i;

    /* check if all characters are digits */
    for (i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }

    /* check if phone number has 10 digits */
    if (i != 10) {
        return false;
    }

    return true;
}

/*
 * Function to validate email address
 * Returns true if email address is valid, false otherwise
 */
bool validate_email(char *email) {
    int i;
    char c;

    /* check if there is at least one '@' sign and one '.' */
    for (i = 0; email[i] != '\0'; i++) {
        c = email[i];

        if (c == '@') {
            break;
        }
    }

    if (email[i] == '\0') {
        return false;
    }

    for (; email[i] != '\0'; i++) {
        c = email[i];

        if (c == '.') {
            break;
        }
    }

    if (email[i] == '\0') {
        return false;
    }

    /* check if there is at least one character before '@' sign */
    if (i == 0) {
        return false;
    }

    return true;
}