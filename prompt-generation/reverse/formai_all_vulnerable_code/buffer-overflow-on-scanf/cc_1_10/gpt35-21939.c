//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20 // Maximum password length
#define MIN_LENGTH 8  // Minimum password length

// Function to generate a random character from a given character set
char get_random_char(char* char_set, int char_set_length){
    int random_index = rand() % char_set_length;
    return char_set[random_index];
}

// Function to generate a secure password using a given character set and length
char* generate_secure_password(char* char_set, int char_set_length, int password_length){
    char* password = (char*) malloc((password_length+1) * sizeof(char));

    for(int i=0; i<password_length; i++){
        password[i] = get_random_char(char_set, char_set_length);
    }
    password[password_length] = '\0';

    return password;
}

int main(){
    srand(time(NULL)); // Seed random number generator

    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special_chars[] = "!@#$%^&*()-_+=";
    int char_set_lengths[] = {26, 26, 10, 12};
    char* char_sets[] = {lowercase, uppercase, digits, special_chars};

    int num_char_sets = 4;
    int min_num_special_chars = 2;

    int password_length;
    do{
        printf("Enter password length (minimum %d, maximum %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &password_length);
    }while(password_length < MIN_LENGTH || password_length > MAX_LENGTH);

    char* password = (char*) malloc((password_length+1) * sizeof(char));
    int num_special_chars = 0;

    while(num_special_chars < min_num_special_chars){
        // Generate password with at least min_num_special_chars number of special characters
        int char_set_index = rand() % num_char_sets;
        password = generate_secure_password(char_sets[char_set_index], char_set_lengths[char_set_index], password_length);

        for(int i=0; i<password_length; i++){
            if(strchr(special_chars, password[i]) != NULL){
                num_special_chars++;
            }
        }
    }

    printf("Secure password: %s\n", password);

    free(password);

    return 0;
}