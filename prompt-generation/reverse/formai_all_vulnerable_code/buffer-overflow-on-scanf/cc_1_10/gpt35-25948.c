//FormAI DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of passwords the user can store */
#define MAX_PWDS 10

/* Define the maximum length of each password */
#define MAX_PWD_LEN 20

/* Define the maximum length of the website name for storing password */
#define MAX_SITE_LEN 50

/* Define the struct to hold the website name and its password */
struct Password {
    char site_name[MAX_SITE_LEN];
    char pwd[MAX_PWD_LEN];
};

/* Define a function to get the website name from the user */
void get_site_name(char *site_name) {
    printf("Enter the website name: ");
    scanf("%s", site_name);
}

/* Define a function to get the website password from the user */
void get_pwd(char *pwd) {
    printf("Enter the password: ");
    scanf("%s", pwd);
}

/* Define a function to validate if the password is strong */
int is_strong_password(char *pwd) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int len = strlen(pwd);
    
    if (len < 8) {
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        char ch = pwd[i];
        if (isupper(ch)) {
            has_upper = 1;
        } else if (islower(ch)) {
            has_lower = 1;
        } else if (isdigit(ch)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    
    if (has_upper && has_lower && has_digit && has_special) {
        return 1;
    }
    
    return 0;
}

/* Define a function to check if the website name already exists */
int site_exists(struct Password passwords[], char *site_name, int num_pwds) {
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(passwords[i].site_name, site_name) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Define the main function */
int main() {
    struct Password passwords[MAX_PWDS];
    int num_pwds = 0;
    
    while (1) {
        char choice;
        printf("\nEnter choice:\n1. Store password\n2. Retrieve password\n3. Exit\n");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1': {
                if (num_pwds < MAX_PWDS) {
                    char site_name[MAX_SITE_LEN];
                    get_site_name(site_name);
                    
                    if (site_exists(passwords, site_name, num_pwds)) {
                        printf("This website already has a password stored\n");
                    } else {
                        char pwd[MAX_PWD_LEN];
                        get_pwd(pwd);
                        
                        if (is_strong_password(pwd)) {
                            struct Password password = {0};
                            strcpy(password.site_name, site_name);
                            strcpy(password.pwd, pwd);
                            passwords[num_pwds] = password;
                            printf("Password stored successfully\n");
                            num_pwds++;
                        } else {
                            printf("Password is not strong enough. Please use at least 8 characters with a mix of upper and lower case letters, a digit, and a special character.\n");
                        }
                    }
                } else {
                    printf("You have reached the maximum number of passwords you can store\n");
                }
                break;
            }
            case '2': {
                if (num_pwds > 0) {
                    char site_name[MAX_SITE_LEN];
                    get_site_name(site_name);
                    
                    for (int i = 0; i < num_pwds; i++) {
                        if (strcmp(passwords[i].site_name, site_name) == 0) {
                            printf("Password for %s is %s\n", site_name, passwords[i].pwd);
                            break;
                        }
                    }
                } else {
                    printf("You have not stored any passwords yet\n");
                }
                break;
            }
            case '3': {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    
    return 0;
}