//FormAI DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20

/* A struct to store password information */
struct Password {
    char password[MAX_PASSWORD_LEN];
    char hint[MAX_PASSWORD_LEN];
    int attempts;
};

/* Function to update the password hint */
void update_hint(struct Password *p, char new_hint[]) {
    strcpy(p->hint, new_hint);
    printf("Hint updated successfully!\n");
}

/* Function to check if the password is correct */
int check_password(struct Password *p, char pwd[]) {
    if(strcmp(p->password, pwd) == 0) {
        printf("Password is correct! Access granted.\n");
        return 1;
    } else {
        p->attempts++;
        printf("Password is incorrect. Try again!\n");
        return 0;
    }
}

/* Function to reset the password and hint */
void reset_password(struct Password *p, char new_pwd[], char new_hint[]) {
    strcpy(p->password, new_pwd);
    strcpy(p->hint, new_hint);
    p->attempts = 0;
    printf("Password and hint updated successfully!\n");
}

int main() {
    struct Password p = {"password123", "my favorite color", 0};
    int choice;

    while(1) {
        printf("\n");
        printf("---------------------------\n");
        printf("| Password Management App |\n");
        printf("---------------------------\n");
        printf("\n");
        printf("1. Check password\n");
        printf("2. Update password hint\n");
        printf("3. Reset password\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char pwd[MAX_PASSWORD_LEN];
                printf("Enter the password: ");
                scanf("%s", pwd);
                check_password(&p, pwd);
                break;
            }
            case 2: {
                char new_hint[MAX_PASSWORD_LEN];
                printf("Enter the new hint: ");
                scanf("%s", new_hint);
                update_hint(&p, new_hint);
                break;
            }
            case 3: {
                char new_pwd[MAX_PASSWORD_LEN], new_hint[MAX_PASSWORD_LEN];
                printf("Enter the new password: ");
                scanf("%s", new_pwd);
                printf("Enter the new hint: ");
                scanf("%s", new_hint);
                reset_password(&p, new_pwd, new_hint);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }

        if(p.attempts >= 3) {
            printf("Maximum attempts exceeded! Program is terminating...\n");
            exit(0);
        }
    }

    return 0;
}