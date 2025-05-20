//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_password(char *password, int length);
int check_criteria(char *password);

int main() {
    int length, criteria_met;
    char password[20];

    // Seed the random function with current time
    srand(time(0));

    printf("Enter the password length (min. 8 characters): ");
    scanf("%d", &length);

    // Validate length
    if(length < 8) {
        printf("Password length should be minimum 8 characters.\n");
        exit(0);
    }

    do {
        generate_password(password, length);
        criteria_met = check_criteria(password);
    } while(!criteria_met);

    printf("Generated password is: %s\n", password);

    return 0;
}

void generate_password(char *password, int length) {
    int i, random_num;

    // Generate a random character between 33 and 126 ASCII range
    for(i = 0; i < length; i++) {
        random_num = rand() % 94 + 33;
        password[i] = (char)random_num;
    }

    password[length] = '\0'; // Add null character to the end of string
}

int check_criteria(char *password) {
    int i, uppercase = 0, lowercase = 0, number = 0, special_char = 0;

    // Check for all criteria
    for(i = 0; i < strlen(password); i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            number++; 
        } else {
            special_char++;
        }
    }

    // Check if all criteria are met
    if(uppercase > 0 && lowercase > 0 && number > 0 && special_char > 0) {
        return 1; // Password meets all criteria
    } else {
        return 0; // Password does not meet all criteria
    }
}