//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include <stdio.h>

//First, let's initialize all our variables
int uppercase = 0, lowercase = 0, number = 0, special_char = 0, length = 0, strength = 0;
char password[50];

int main() {

    //Let's prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    //Loop through the password string to check for each character type
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            //Uppercase letter found
            uppercase++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            //Lowercase letter found
            lowercase++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            //Number found
            number++;
        } else {
            //Special character found
            special_char++;
        }
    }

    //Now let's calculate the password strength
    strength = length * 2;

    if(uppercase > 0) {
        strength += 10;
    }
    if(lowercase > 0) {
        strength += 10;
    }
    if(number > 0) {
        strength += 10;
    }
    if(special_char > 0) {
        strength += 10;
    }

    if(length >= 8 && length <= 12) {
        strength += 10;
    } else if(length > 12) {
        strength += 25;
    }

    if(uppercase > 0 && lowercase > 0 && number > 0 && special_char > 0) {
        strength += 25;
    }

    //Let's display the password strength to the user
    printf("Password strength: %d\n", strength);

    return 0;
}