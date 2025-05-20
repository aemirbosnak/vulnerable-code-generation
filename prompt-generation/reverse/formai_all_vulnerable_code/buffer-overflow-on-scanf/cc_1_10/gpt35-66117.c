//FormAI DATASET v1.0 Category: Data validation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* This program is going to validate user inputs to ensure only specific types of inputs are allowed. */

int main() {

    char user_choice;
    char user_name[25];
    char user_password[25];
    char user_email[50];
    int user_age;

    printf("Welcome to our new user registration portal.\n");
    printf("Please select an option from the menu below:\n");
    printf("A. Register\n");
    printf("B. Exit\n");
    scanf("%c", &user_choice);
    user_choice = toupper(user_choice);

    while(user_choice != 'B') {
        switch(user_choice) {
            case 'A':
                printf("Please enter your name: ");
                scanf("%s", user_name);

                // Checking for invalid characters in the user name input
                if(strpbrk(user_name, "!@#$%^&*()_+={}[]|\\:\";'<>?,./")) {
                    printf("Error! Invalid characters detected. Please enter a valid name.\n");
                    break;
                }

                printf("Please enter your age: ");
                scanf("%d", &user_age);

                // Checking if user entered a valid age
                if(user_age < 0 || user_age > 110) {
                    printf("Error! Invalid age detected. Please enter a valid age.\n");
                    break;
                }

                printf("Please enter your email: ");
                scanf("%s", user_email);

                // Checking if user entered a valid email
                if(strpbrk(user_email, "!#$%^&*()_+={}[]|\\:;'<>,/?")) {
                    printf("Error! Invalid email detected. Please enter a valid email.\n");
                    break;
                }

                printf("Please enter your password (no special characters allowed): ");
                scanf("%s", user_password);

                // Checking if user entered a valid password
                if(strpbrk(user_password, "!@#$%^&*()+={}[]|\\:\";'<>?,./")) {
                    printf("Error! Invalid password detected. Please enter a valid password.\n");
                    break;
                }

                printf("Congratulations! You have successfully registered.\n");
                break;


            default:
                printf("Error! Invalid menu option selected. Please select a valid option.\n");

        }

        printf("Thank you for using our new user registration portal.\n");
        printf("Would you like to continue using this portal?\n");
        printf("A. Register\n");
        printf("B. Exit\n");
        scanf(" %c", &user_choice);

        user_choice = toupper(user_choice);

    }

    printf("Goodbye! Thank you for choosing our user registration portal.\n");

    return 0;

}