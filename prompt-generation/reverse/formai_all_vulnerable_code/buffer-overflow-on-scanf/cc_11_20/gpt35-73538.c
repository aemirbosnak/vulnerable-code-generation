//FormAI DATASET v1.0 Category: Data validation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define PHONE_NUM_LENGTH 12

int main() {
    char name[MAX_NAME_LENGTH];
    char phoneNum[PHONE_NUM_LENGTH];
    int age;

    printf("Welcome! Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    // Trim newline character from name
    if ((strlen(name) > 0) && (name[strlen(name) - 1] == '\n')) {
        name[strlen(name) - 1] = '\0';
    }

    // Ensure name only contains letters and is not too long
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Oopsie! Your name can only contain letters. Please try again.\n");
            return 0;
        }
    }
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Uh oh! Your name is too long. Please enter a name that is %d characters or fewer.\n", MAX_NAME_LENGTH - 1);
        return 0;
    }

    printf("Nice to meet you, %s! Please enter your age: ", name);
    scanf("%d", &age);

    // Ensure age is a valid positive integer
    if (age <= 0 || age > 150) {
        printf("Whoa there! Your age must be a positive number less than or equal to 150. Please try again.\n");
        return 0;
    }

    printf("Great! Please enter your phone number (format: XXX-XXX-XXXX): ");
    scanf("%s", phoneNum);

    // Ensure phone number is in proper format
    if (strlen(phoneNum) != PHONE_NUM_LENGTH - 1) {
        printf("Oops! Your phone number must be in the format XXX-XXX-XXXX. Please try again.\n");
        return 0;
    }
    for (int i = 0; i < PHONE_NUM_LENGTH - 1; i++) {
        if (i == 3 || i == 7) { // Check for dashes in proper places
            if (phoneNum[i] != '-') {
                printf("ERROR: Your phone number must contain dashes in the proper places (XXX-XXX-XXXX). Please try again.\n");
                return 0;
            }
        } else {
            if (!isdigit(phoneNum[i])) { // Ensure only digits are used
                printf("Oopsie! Your phone number can only contain digits and dashes (XXX-XXX-XXXX). Please try again.\n");
                return 0;
            }
        }
    }
    printf("Congrats! You have entered valid information.\n");

    return 0;
}