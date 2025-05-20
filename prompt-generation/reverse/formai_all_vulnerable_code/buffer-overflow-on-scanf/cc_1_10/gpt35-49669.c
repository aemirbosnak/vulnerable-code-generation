//FormAI DATASET v1.0 Category: Data validation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    Program to validate user input for a person's name and age
    Name should contain only letters
    Age should be a positive integer and less than or equal to 150
*/

int main() {
    char name[50];
    int age;
    char age_str[10];
    int valid_input = 0;

    while (!valid_input) {
        // Get person's name
        printf("Please enter a person's name: ");
        scanf("%s", name);

        // Check that name contains only letters
        int name_len = strlen(name);
        int valid_name = 1;
        for (int i = 0; i < name_len; i++) {
            if (!isalpha(name[i])) {
                printf("Invalid name, please enter only letters.\n");
                valid_name = 0;
                break;
            }
        }
        // If name is valid, get age
        if (valid_name) {
            printf("Please enter a person's age: ");
            scanf("%s", age_str);
        
            // Check that age is a positive integer
            int age_len = strlen(age_str);
            int valid_age = 1;
            for (int i = 0; i < age_len; i++) {
                if (!isdigit(age_str[i])) {
                    printf("Invalid age, please enter a positive integer.\n");
                    valid_age = 0;
                    break;
                }
            }
            // If age is valid, convert to integer and check if less than or equal to 150
            if (valid_age) {
                age = atoi(age_str);
                if (age > 150) {
                    printf("Invalid age, please enter an age less than or equal to 150.\n");
                } else {
                    valid_input = 1;
                }
            }
        }
    }

    // Print validated input
    printf("\nName: %s\nAge: %d\n", name, age);
    
    return 0;
}