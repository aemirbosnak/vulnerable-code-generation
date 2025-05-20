//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

bool check_upper_lower(char* password) {
    bool has_upper = false;
    bool has_lower = false;
    int i = 0;
    
    while(password[i]) {
        if(isupper(password[i])) //check if it's an uppercase letter
            has_upper = true;
        else if(islower(password[i])) //check if it's a lowercase letter
            has_lower = true;
        if(has_upper && has_lower) //if it has both upper and lower, then return true
            return true;
        i++;
    }
    return false; //if it doesn't have both upper and lower, then return false
}

bool check_special(char* password) {
    int i = 0;
    
    while(password[i]) {
        if(!isalnum(password[i])) //check if it's not alphanumeric
            return true;
        i++;
    }
    return false; //if none of the characters are special characters, then return false
}

int main() {
    int length; //length of password
    
    printf("Welcome to the Secure Password Generator!\n\n");
    printf("Enter the desired length of your password (between 8 to 20 characters): ");
    scanf("%d", &length);
    
    while(length < 8 || length > 20) { //keep asking for input until it's within range
        printf("\nYour password length is invalid. Please enter a value between 8 to 20 characters: ");
        scanf("%d", &length);
    }
    
    char password[length]; //initialize password array with the desired length
    
    srand(time(NULL)); //seed the random generator with current time
    
    for(int i = 0; i < length; i++) {
        int rand_num = rand() % 94 + 33; //generate a random number from ascii table (excluding space) - 33 to 126
        password[i] = rand_num; //assign the random number to the password array
    }
    
    while(!check_upper_lower(password) || !check_special(password)) { //keep generating passwords until it meets the requirements
        for(int i = 0; i < length; i++) {
            int rand_num = rand() % 94 + 33; //generate a random number from ascii table (excluding space) - 33 to 126
            password[i] = rand_num; //assign the random number to the password array
        }
    }
    
    printf("\nYour secure password is: ");
    for(int i = 0; i < length; i++) {
        printf("%c", password[i]); //print out the generated password
    }
    
    return 0;
}