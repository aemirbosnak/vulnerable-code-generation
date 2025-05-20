//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// function to check if a string has only alphabets
bool is_all_alphabets(char *str) {
    for(int i=0; str[i] != '\0'; i++) {
        if(!isalpha(str[i]))
            return false;
    }
    return true;
}

// function to check if a string has only digits
bool is_all_digits(char *str) {
    for(int i=0; str[i] != '\0'; i++) {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

int main() {
    char name[20], age[3], phone[11];

    // taking input from user
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%s", age);

    printf("Enter your phone number: ");
    scanf("%s", phone);

    // validating input
    if(!is_all_alphabets(name)) {
        printf("Invalid Name! Name should contain only alphabets.\n");
        return 1;
    }

    if(!is_all_digits(age)) {
        printf("Invalid Age! Age should contain only digits.\n");
        return 1;
    }

    if(!is_all_digits(phone)) {
        printf("Invalid Phone Number! Phone number should contain only digits.\n");
        return 1;
    }

    if(strlen(phone) != 10) {
        printf("Invalid Phone Number Length! Phone number should contain exactly 10 digits.\n");
        return 1;
    }

    // if all inputs are valid
    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Phone: %s\n", phone);

    return 0;
}