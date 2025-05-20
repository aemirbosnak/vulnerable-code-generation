//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 50

char* generate_password(int length){
    char* password = calloc(length+1,sizeof(char)); //+1 for the string terminator '\0'
    if(password == NULL){
        printf("[ERROR] Could not allocate memory for password string.\n");
        exit(1);
    }
    srand(time(NULL)); //initialize random seed based on current time
    const char* allowed_chars = "0123456789"
                                "abcdefghijklmnopqrstuvwxyz"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "`~!@#$%^&*()-_=+[]{}|;:',.<>/?"; //allowed characters for password
    int i;
    for(i = 0; i < length; i++){
        int index = rand() % strlen(allowed_chars); //get a random index in the allowed_chars string
        password[i] = allowed_chars[index];
    }
    return password;
}

int check_security(char* password){
    //check length of password
    int length = strlen(password);
    if(length < 8 || length > 16){
        return 0; //password length not secure
    }
    //check for uppercase letters
    int i, uppercase_found = 0;
    for(i = 0; i < length; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            uppercase_found = 1;
            break;
        }
    }
    if(!uppercase_found){
        return 0; //no uppercase letters found
    }
    //check for lowercase letters
    int lowercase_found = 0;
    for(i = 0; i < length; i++){
        if(password[i] >= 'a' && password[i] <= 'z'){
            lowercase_found = 1;
            break;
        }
    }
    if(!lowercase_found){
        return 0; //no lowercase letters found
    }
    //check for digits
    int digit_found = 0;
    for(i = 0; i < length; i++){
        if(password[i] >= '0' && password[i] <= '9'){
            digit_found = 1;
            break;
        }
    }
    if(!digit_found){
        return 0; //no digits found
    }
    //check for special characters
    const char* special_chars = "`~!@#$%^&*()-_=+[]{}|;:',.<>/?";
    int special_char_found = 0;
    for(i = 0; i < length; i++){
        if(strchr(special_chars, password[i]) != NULL){
            special_char_found = 1;
            break;
        }
    }
    if(!special_char_found){
        return 0; //no special characters found
    }
    return 1; //password is considered secure
}

int main(){
    int password_length;
    printf("Enter desired password length (8-16 characters): ");
    scanf("%d", &password_length);
    if(password_length < 8 || password_length > 16){
        printf("[ERROR] Invalid password length. Please choose between 8-16 characters.\n");
        return 1;
    }
    char* password = generate_password(password_length); //generate password
    int security_status = check_security(password); //check password security level
    while(security_status == 0){ //if password not secure, generate new password until it is secure
        free(password);
        password = generate_password(password_length); //generate new password
        security_status = check_security(password); //check security level of new password
    }
    printf("Your new password is: %s\n", password);
    free(password); //free allocated memory for password string
    return 0;
}