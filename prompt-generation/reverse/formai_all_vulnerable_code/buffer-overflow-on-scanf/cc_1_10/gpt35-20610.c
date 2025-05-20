//FormAI DATASET v1.0 Category: Password management ; Style: Donald Knuth
/* Password management system */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Struct to hold password information */
struct password {
    char *site_name;
    char *username;
    char *password;
};

/* Prototypes */
void print_menu(void);
void add_password(struct password **passwords, int *num_passwords);
void view_passwords(struct password *passwords, int num_passwords);
void remove_password(struct password **passwords, int *num_passwords);
void generate_password(char *str, int n);
int check_password_strength(char *str);

/* Main function */
int main(void) {
    struct password *passwords = NULL;
    int num_passwords = 0;
    char selection;

    do {
        print_menu();
        scanf(" %c", &selection);

        switch (tolower(selection)) {
            case 'a':
                add_password(&passwords, &num_passwords);
                break;
            case 'v':
                view_passwords(passwords, num_passwords);
                break;
            case 'r':
                remove_password(&passwords, &num_passwords);
                break;
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while (tolower(selection) != 'q');

    /* Free dynamically allocated memory */
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].site_name);
        free(passwords[i].username);
        free(passwords[i].password);
    }
    free(passwords);

    return 0;
}

/* Function to print the main menu */
void print_menu(void) {
    printf("Password Manager\n");
    printf("A) Add a password\n");
    printf("V) View passwords\n");
    printf("R) Remove a password\n");
    printf("Q) Quit\n");
    printf("Select an option: ");
}

/* Function to add a password */
void add_password(struct password **passwords, int *num_passwords) {
    /* Prompt user for information */
    char site_name[50];
    char username[50];
    char password[50];

    printf("Enter the site name: ");
    scanf("%s", site_name);
    printf("Enter the username: ");
    scanf("%s", username);
    
    /* Generates a random password */
    generate_password(password, 12);
    printf("Generated password: %s\n", password);

    /* Asks user if they want to enter their own password instead */
    printf("Do you want to use this password? (Y/N) ");
    char response;
    scanf(" %c", &response);
    if (tolower(response) == 'n') {
        printf("Enter your own password (at least 8 characters): ");
        scanf("%s", password);
        int strength = check_password_strength(password);
        while (strength < 3) {
            printf("Weak password! Please try again (at least 8 characters): ");
            scanf("%s", password);
            strength = check_password_strength(password);
        }
    }

    /* Assign the password information */
    if (*passwords == NULL) {
        /* If list is empty, allocate memory */
        *passwords = malloc(sizeof(struct password));
    } else {
        /* If list is not empty, resize the memory */
        *passwords = realloc(*passwords, (*num_passwords + 1) * sizeof(struct password));
    }

    /* Assign site name, username, and password */
    (*passwords)[*num_passwords].site_name = strdup(site_name);
    (*passwords)[*num_passwords].username = strdup(username);
    (*passwords)[*num_passwords].password = strdup(password);

    /* Increment number of passwords */
    (*num_passwords)++;
}

/* Function to view passwords */
void view_passwords(struct password *passwords, int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to display.\n");
    } else {
        for (int i = 0; i < num_passwords; i++) {
            printf("Site name: %s\n", passwords[i].site_name);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            printf("\n");
        }
    }
}

/* Function to remove a password */
void remove_password(struct password **passwords, int *num_passwords) {
    printf("Enter the site name to remove: ");
    char site_name[50];
    scanf("%s", site_name);

    int i;
    int found = 0;
    for (i = 0; i < *num_passwords; i++) {
        if (strcmp((*passwords)[i].site_name, site_name) == 0) {
            /* Found the site to remove */
            found = 1;
            break;
        }
    }

    if (found) {
        /* Shift all elements after the removed element */
        for (; i < (*num_passwords - 1); i++) {
            (*passwords)[i].site_name = (*passwords)[i+1].site_name;
            (*passwords)[i].username = (*passwords)[i+1].username;
            (*passwords)[i].password = (*passwords)[i+1].password;
        }

        /* Decrement number of passwords */
        (*num_passwords)--;

        /* Resize memory */
        if (*num_passwords == 0) {
            /* If list is now empty, free the memory */
            free(*passwords);
            *passwords = NULL;
        } else {
            /* If list is not empty, resize the memory */
            *passwords = realloc(*passwords, *num_passwords * sizeof(struct password));
        }
        printf("Password for %s removed.\n", site_name);
    } else {
        printf("Site name not found.\n");
    }
}

/* Function to generate a random password */
void generate_password(char *str, int n) {
    /* Generates a password containing uppercase and lowercase letters, numbers, and symbols */
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    for (int i = 0; i < n; i++) {
        int index = rand() % (int) (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[n] = '\0';
}

/* Function to check the strength of a password */
int check_password_strength(char *str) {
    int score = 0;

    /* Length */
    int len = strlen(str);
    if (len < 8) {
        score -= 1;
    } else if (len > 12) {
        score += 2;
    } else {
        score += 1;
    }

    /* Uppercase letters */
    int upper_count = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            upper_count++;
        }
    }
    if (upper_count == 1) {
        score += 1;
    } else if (upper_count >= 2) {
        score += 2;
    }

    /* Lowercase letters */
    int lower_count = 0;
    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            lower_count++;
        }
    }
    if (lower_count == 1) {
        score += 1;
    } else if (lower_count >= 2) {
        score += 2;
    }

    /* Numbers */
    int number_count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            number_count++;
        }
    }
    if (number_count == 1) {
        score += 1;
    } else if (number_count >= 2) {
        score += 2;
    }

    /* Symbols */
    int symbol_count = 0;
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i])) {
            symbol_count++;
        }
    }
    if (symbol_count == 1) {
        score += 1;
    } else if (symbol_count >= 2) {
        score += 2;
    }

    return score;
}