//FormAI DATASET v1.0 Category: Data validation ; Style: cheerful
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Hello! Let's validate some data!\n");

    char name[50], email[50], address[50];
    int age;

    printf("Please enter your name: ");
    scanf("%s", name);

    // check if name contains alphabets only
    int i = 0;
    while(name[i] != '\0') {
        if(!isalpha(name[i])) {
            printf("%s is an invalid name! Only alphabets are allowed.\n", name);
            return -1;
        }
        i++;
    }

    printf("Please enter your age: ");
    scanf("%d", &age);

    // check if age is between 0 and 150
    if (age < 0 || age > 150) {
        printf("Invalid age! Age must be between 0 and 150.\n");
        return -1;
    }

    printf("Please enter your email address: ");
    scanf("%s", email);

    // check if email contains @ symbol
    i = 0;
    int at_count = 0;
    while(email[i] != '\0') {
        if(email[i] == '@')
            at_count++;

        i++;
    }
    if(at_count != 1) {
        printf("Invalid email address! An email address must contain only one '@' symbol.\n");
        return -1;
    }

    printf("Please enter your address: ");
    scanf("%s", address);

    // check if address contains alphabets and numbers only
    i = 0;
    while(address[i] != '\0') {
        if(!isalnum(address[i]) && address[i] != ' ') {
            printf("%s is an invalid address! Only alphabets and numbers are allowed.\n", address);
            return -1;
        }
        i++;
    }

    printf("Congratulations! Your data has been validated successfully!\n");

    return 0;
}