//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50];
    char last_name[50];
    char full_name[100];
    int name_len, last_name_len;

    printf("Welcome to the Full Name Generator!\n");
    printf("Please enter your first name: ");
    scanf("%s", name);

    printf("Please enter your last name: ");
    scanf("%s", last_name);

    // Get the length of each name
    name_len = strlen(name);
    last_name_len = strlen(last_name);

    // Copy the first name to the full name variable
    strcpy(full_name, name);

    // Concatenate the last name to the full name variable
    strcat(full_name, " ");
    strcat(full_name, last_name);

    printf("Your full name is: %s\n", full_name);

    // Convert the first name to uppercase
    for (int i = 0; i < name_len; i++) {
        name[i] = toupper(name[i]);
    }

    printf("Your uppercase first name is: %s\n", name);

    // Convert the last name to lowercase
    for (int i = 0; i < last_name_len; i++) {
        last_name[i] = tolower(last_name[i]);
    }

    printf("Your lowercase last name is: %s\n", last_name);

    // Replace the first vowel in the first name with an asterisk
    for (int i = 0; i < name_len; i++) {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u') {
            name[i] = '*';
            break;
        }
    }

    printf("Your name with the first vowel replaced with an asterisk is: %s\n", name);

    return 0;
}