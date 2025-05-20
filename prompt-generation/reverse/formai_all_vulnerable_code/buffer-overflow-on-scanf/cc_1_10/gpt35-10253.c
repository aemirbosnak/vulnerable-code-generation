//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20

/* Function to generate a random character */
char generate_random_character(){
    /* ASCII code for characters to generate */
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",./<>?";

    /* Length of character set */
    const int charset_len = sizeof(charset) - 1;
    
    /* Generate random index within the range of character set */
    int random_index = rand() % charset_len;

    /* Return the randomly generated character */
    return charset[random_index];
}

/* Function to generate a secure password */
void generate_secure_password(char *password, int length){
    srand(time(NULL));
    int i;
    for(i=0; i<length; i++){
        password[i] = generate_random_character();
    }
    password[i] = '\0';
}

/* Driver code */
int main(){
    int password_length, i;
    char password[MAX_LENGTH];

    printf("Enter length of your password (must be between 8 to 20 characters): ");
    scanf("%d", &password_length);

    if(password_length<8 || password_length>20){
        printf("Invalid password length. Please enter length between 8 to 20.\n");
        return 0;
    }

    generate_secure_password(password, password_length);

    printf("Your secure password is: %s\n", password);

    return 0;
}