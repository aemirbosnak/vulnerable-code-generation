//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to generate a secure password
char* secure_password_generator(int length) {

    // Variables to store characters with different types
    char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    char all_chars[100];

    // Array to store the password
    char* password = (char*) malloc(length * sizeof(char));
    memset(password, 0, length * sizeof(char));
    
    // Seed value for the rand function
    srand((unsigned int) time(NULL));

    // Add characters of different types to the all_chars array
    strcat(all_chars, lower_case);
    strcat(all_chars, upper_case);
    strcat(all_chars, numbers);
    strcat(all_chars, symbols);

    // Loop to generate the password
    for(int i=0; i<length; i++) {
        int random_index = rand() % strlen(all_chars);
        password[i] = all_chars[random_index];
    }

    return password;
}

int main() {

    int length;
    printf("Enter the password length: ");
    scanf("%d", &length);

    // Ensure password is at least 8 characters long
    if (length < 8) {
        printf("Error: Password must contain at least 8 characters!");
        return 0;
    }

    char* password = secure_password_generator(length);

    printf("Secure Password: %s", password);

    free(password);

    return 0;
}