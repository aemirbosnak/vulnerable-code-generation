//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Function to generate a random number between min and max (inclusive)
 */
int random_number(int min, int max) {
    int range = max - min;
    int random = rand() % (range + 1);
    return random + min;
}

/*
 * Function to generate a random uppercase letter between A and Z
 */
char random_uppercase() {
    return random_number('A', 'Z');
}

/*
 * Function to generate a random lowercase letter between a and z
 */
char random_lowercase() {
    return random_number('a', 'z');
}

/*
 * Function to generate a random digit between 0 and 9
 */
char random_digit() {
    return random_number('0', '9');
}

/*
 * Function to generate a random special character
 */
char random_special() {
    char special[] = "!@#$%^&*()_+-=[]{}|;':\"<>,.?/~`";
    int index = random_number(0, strlen(special) - 1);
    return special[index];
}

/*
 * Function to shuffle a character array
 */
void shuffle(char* array, int size) {
    for (int i = 0; i < size; i++) {
        int j = random_number(0, size - 1);
        char temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

/*
 * Function to generate a secure password
 */
void generate_password(char* password, int length) {
    int num_uppercase = length / 4;
    int num_lowercase = length / 4;
    int num_digits = length / 4;
    int num_special = length - num_uppercase - num_lowercase - num_digits;
    
    for (int i = 0; i < num_uppercase; i++) {
        password[i] = random_uppercase();
    }
    
    for (int i = 0; i < num_lowercase; i++) {
        password[num_uppercase + i] = random_lowercase();
    }
    
    for (int i = 0; i < num_digits; i++) {
        password[num_uppercase + num_lowercase + i] = random_digit();
    }
    
    for (int i = 0; i < num_special; i++) {
        password[num_uppercase + num_lowercase + num_digits + i] = random_special();
    }
    
    // Shuffle the password
    shuffle(password, length);
}

/*
 * Main function
 */
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Get the length of the password from the user
    int length;
    printf("How long should the password be? ");
    scanf("%d", &length);
    
    // Generate the password
    char password[length + 1];
    generate_password(password, length);
    printf("Your secure password is: %s\n", password);
    return 0;
}