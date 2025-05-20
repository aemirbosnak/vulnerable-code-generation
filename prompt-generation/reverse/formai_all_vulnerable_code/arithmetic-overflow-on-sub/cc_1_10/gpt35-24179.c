//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random uppercase letter
char rand_upper() {
    return rand() % 26 + 'A';
}

// function to generate a random lowercase letter
char rand_lower() {
    return rand() % 26 + 'a';
}

// function to generate a random digit
char rand_digit() {
    return rand() % 10 + '0';
}

// function to generate a random special character
char rand_special() {
    char special[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
    return special[rand() % sizeof(special)];
}

// main function
int main() {
    int length, num_upper, num_lower, num_digit, num_special;
    char password[100];
    srand(time(NULL));
    
    // get desired password length from user
    printf("Enter the desired password length: ");
    scanf("%d", &length);
    
    // get desired number of uppercase letters from user
    printf("Enter the desired number of uppercase letters: ");
    scanf("%d", &num_upper);
    
    // get desired number of lowercase letters from user
    printf("Enter the desired number of lowercase letters: ");
    scanf("%d", &num_lower);
    
    // get desired number of digits from user
    printf("Enter the desired number of digits: ");
    scanf("%d", &num_digit);
    
    // get desired number of special characters from user
    printf("Enter the desired number of special characters: ");
    scanf("%d", &num_special);
    
    // generate random characters for password
    int i;
    for (i = 0; i < num_upper; i++) {
        password[i] = rand_upper();
    }
    for (; i < num_upper + num_lower; i++) {
        password[i] = rand_lower();
    }
    for (; i < num_upper + num_lower + num_digit; i++) {
        password[i] = rand_digit();
    }
    for (; i < length - num_special; i++) {
        password[i] = rand_upper();
    }
    for (; i < length; i++) {
        password[i] = rand_special();
    }
    
    // shuffle characters in password
    for (i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // print password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}