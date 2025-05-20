//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random lowercase letter
char random_lower() {
    return (char) random_int(97, 122);
}

// Function to generate a random uppercase letter
char random_upper() {
    return (char) random_int(65, 90);
}

// Function to generate a random digit
char random_digit() {
    return (char) random_int(48, 57);
}

// Function to generate a random special character
char random_special() {
    int pick = random_int(1, 4);
    if (pick == 1) {
        return '!'; 
    } else if (pick == 2) {
        return '@';
    } else if (pick == 3) {
        return '#';
    } else {
        return '$';
    }
}

// Function to generate a secure password with a given length
void generate_password(int length) {
    char password[length + 1];
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int pick = random_int(1, 4);
        if (pick == 1) {
            password[i] = random_lower();
        } else if (pick == 2) {
            password[i] = random_upper();
        } else if (pick == 3) {
            password[i] = random_digit();
        } else {
            password[i] = random_special();
        }
    }
    password[length] = '\0'; // Add the null terminator
    printf("Your secure password is: %s\n", password);
}

int main() {
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);
    generate_password(length);
    return 0;
}