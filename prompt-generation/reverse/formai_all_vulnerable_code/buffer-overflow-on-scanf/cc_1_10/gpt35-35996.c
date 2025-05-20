//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>

int strength(char* password){
	// Initializing variables to keep track of password strength
    int length = strlen(password);
    int lowercase = 0, uppercase = 0, digits = 0, symbols = 0;

    // Checking each character of the password
    for (int i = 0; i < length; i++) {
        
        // Checking for lowercase letters
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        }

        // Checking for uppercase letters
        else if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        }

        // Checking for digits
        else if (password[i] >= '0' && password[i] <= '9') {
            digits++;
        }

        // Checking for symbols
        else {
            symbols++;
        }
    }

    // Calculating the password strength based on the criteria specified
    int strength = 0;

    if (length < 6) {
        strength += 1;
    }

    if (lowercase == 0 || uppercase == 0) {
        strength += 1;
    }

    if (digits == 0 || symbols == 0) {
        strength += 1;
    }

    return strength;
}

int main(){

	// Accepting password from user
	char password[500];
	printf("Enter your password: ");
	scanf("%s", password);

	// Calculating the password strength using the strength function
	int passwordStrength = strength(password);

	// Displaying appropriate message based on password strength
	if(passwordStrength == 0){
		printf("Your password is Strong. Good job!");
	}else if(passwordStrength == 1){
		printf("Your password is Medium strength. Please try harder.");
	}else{
		printf("Your password is Weak. Please try again with a stronger password.");
	}

	return 0;
}