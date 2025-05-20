//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PW_LENGTH 50
#define MAX_PW_NUM 20

typedef struct password {
    char pw[MAX_PW_LENGTH+1]; // adding 1 for null termination
} Password;

Password password_list[MAX_PW_NUM]; // an array of Password struct to store the password

void add_password(char new_pw[]) {
    int i;
    for (i = 0; i < MAX_PW_NUM; i++) {
        if (strlen(password_list[i].pw) == 0) { // find an empty slot
            strcpy(password_list[i].pw, new_pw);
            printf("Password successfully added!\n");
            return;
        }
    }
    printf("Unable to add new password. Password list is full.\n");
}

void delete_password(char pw_to_delete[]) {
    int i;
    for (i = 0; i < MAX_PW_NUM; i++) {
        if (strcmp(password_list[i].pw, pw_to_delete) == 0) { // find the given password
            password_list[i].pw[0] = '\0'; // clear the password
            printf("Password successfully deleted!\n");
            return;
        }
    }
    printf("The password specified does not exist.\n");
}

void display_passwords() {
    int i, count=0;
    for (i = 0; i < MAX_PW_NUM; i++) {
        if (strlen(password_list[i].pw) > 0) { // find non-empty slots
            printf("%d. %s\n", count+1, password_list[i].pw);
            count++;
        }
    }
    if (count == 0) {
        printf("No passwords found in the list.\n");
    }
}

int main() {
    char choice;
    char new_pw[MAX_PW_LENGTH+1];
    char pw_to_delete[MAX_PW_LENGTH+1];
    
    printf("Welcome to Password Manager\n");
    printf("---------------------------\n");
    
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Display passwords\n");
        printf("4. Quit the program\n");
        printf("Please enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                printf("Please enter the new password (maximum of %d characters): ", MAX_PW_LENGTH);
                scanf("%s", new_pw);
                add_password(new_pw);
                break;
            case '2':
                printf("Please enter the password to delete (maximum of %d characters): ", MAX_PW_LENGTH);
                scanf("%s", pw_to_delete);
                delete_password(pw_to_delete);
                break;
            case '3':
                display_passwords();
                break;
            case '4':
                printf("Thank you for using Password Manager.\n");
                exit(0); // exit the program
            default:
                printf("Invalid choice. Please choose from the available options.\n");
                break;
        }
    }
    
    return 0;
}