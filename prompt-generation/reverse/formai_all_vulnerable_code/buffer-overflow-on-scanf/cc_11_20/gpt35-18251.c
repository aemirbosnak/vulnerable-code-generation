//FormAI DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

int main() {
    srand(time(0));
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH + 1] = {"cucumber", "pineapple", "watermelon", "grapefruit", "tomato",
                                                             "zucchini", "avocado", "eggplant", "broccoli", "carrot"};
    int num_passwords = 10;
    char input_password[MAX_PASSWORD_LENGTH + 1];
    int password_index;

    printf("Welcome to the Surreal Password Manager!\n");

    while(1) {
        printf("What would you like to do?\n");
        printf("1. View your passwords\n");
        printf("2. Add a new password\n");
        printf("3. Remove a password\n");
        printf("4. Generate a random password\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_passwords == 0) {
                    printf("You have no passwords stored!\n");
                } else {
                    printf("Your stored passwords are:\n");
                    for(int i = 0; i < num_passwords; i++) {
                        printf("%d. %s\n", i+1, passwords[i]);
                    }
                }
                break;

            case 2:
                if(num_passwords >= MAX_PASSWORDS) {
                    printf("Sorry, you can only store up to %d passwords!\n", MAX_PASSWORDS);
                } else {
                    printf("Enter the new password (max length %d): ", MAX_PASSWORD_LENGTH);
                    scanf("%s", input_password);
                    strcpy(passwords[num_passwords], input_password);
                    num_passwords++;
                    printf("Password added successfully!\n");
                }
                break;

            case 3:
                if(num_passwords == 0) {
                    printf("You have no passwords stored!\n");
                } else {
                    printf("Enter the index of the password you want to remove: ");
                    scanf("%d", &password_index);
                    if(password_index < 1 || password_index > num_passwords) {
                        printf("Invalid index!\n");
                    } else {
                        for(int i = password_index-1; i < num_passwords-1; i++) {
                            strcpy(passwords[i], passwords[i+1]);
                        }
                        num_passwords--;
                        printf("Password removed successfully!\n");
                    }
                }
                break;

            case 4:
                printf("How long would you like the password to be? ");
                int password_length;
                scanf("%d", &password_length);
                if(password_length <= 0) {
                    printf("Invalid password length!\n");
                } else {
                    char random_password[MAX_PASSWORD_LENGTH + 1];
                    for(int i = 0; i < password_length; i++) {
                        int random_number = rand() % 26 + 97;
                        char random_char = (char) random_number;
                        random_password[i] = random_char;
                    }
                    random_password[password_length] = '\0';
                    printf("Your random password is: %s\n", random_password);
                }
                break;

            case 5:
                printf("Thank you for using the Surreal Password Manager!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}