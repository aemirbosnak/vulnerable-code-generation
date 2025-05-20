//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random lowercase character */
char random_lowercase() {
    return (char) (rand() % 26 + 'a');
}

/* Function to generate a random uppercase character */
char random_uppercase() {
    return (char) (rand() % 26 + 'A');
}

/* Function to generate a random digit character */
char random_digit() {
    return (char) (rand() % 10 + '0');
}

/* Function to generate a random special character */
char random_special() {
    const char special_characters[] = "!@#$%^&*()_+-=[]{}\\|;:\",./<>?";
    return special_characters[rand() % sizeof(special_characters)];
}

/* Function to shuffle an array */
void shuffle_array(char* arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* Function to generate a secure password */
void generate_password(char* password, int length) {
    srand(time(NULL)); // Seed the random number generator
    int num_lower = length / 3; // Minimum number of lowercase characters
    int num_upper = length / 3; // Minimum number of uppercase characters
    int num_digit = length / 4; // Minimum number of digit characters
    int num_special = length - num_lower - num_upper - num_digit; // Remaining characters will be special characters
    
    for (int i = 0; i < num_lower; i++) {
        password[i] = random_lowercase();
    }
    for (int i = num_lower; i < num_lower + num_upper; i++) {
        password[i] = random_uppercase();
    }
    for (int i = num_lower + num_upper; i < num_lower + num_upper + num_digit; i++) {
        password[i] = random_digit();
    }
    for (int i = num_lower + num_upper + num_digit; i < length; i++) {
        password[i] = random_special();
    }
    
    shuffle_array(password, length); // Shuffle the array to mix up the characters
}

/* Main program */
int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    char* password = malloc(length * sizeof(char)); // Allocate memory for the password
    generate_password(password, length);
    printf("Your secure password is: %s\n", password);
    free(password); // Free the memory allocated for the password
    return 0;
}