//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 50
#define UPPER_CASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER_CASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()_+-=[]{}\\|;:'\",.<>?"

int main() {
    srand(time(NULL));
    int password_length;
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter desired password length (between 8 and %d): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%d", &password_length);
    
    if (password_length < 8 || password_length > MAX_PASSWORD_LENGTH - 1) {
        printf("Invalid password length.\n");
        return 1;
    }
    
    char *character_sets[] = {UPPER_CASE_LETTERS, LOWER_CASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS};
    int number_of_sets = sizeof(character_sets) / sizeof(character_sets[0]);
    
    char *selected_sets[number_of_sets];
    int selected_set_count = 0;
    
    printf("Select character sets to include in password (1-%d): ", number_of_sets - 1);
    scanf("%d", &selected_set_count);
    
    for (int i = 0; i < selected_set_count; i++) {
        int set_number;
        printf("Enter character set number: ");
        scanf("%d", &set_number);
        selected_sets[i] = character_sets[set_number - 1];
    }
    
    char *password_characters = selected_sets[0];
    for (int i = 1; i < selected_set_count; i++) {
        strcat(password_characters, selected_sets[i]);
    }
    
    for (int i = 0; i < password_length; i++) {
        int random_number = rand() % strlen(password_characters);
        password[i] = password_characters[random_number];
    }
    
    printf("Generated password: %s\n", password);
    
    return 0;
}