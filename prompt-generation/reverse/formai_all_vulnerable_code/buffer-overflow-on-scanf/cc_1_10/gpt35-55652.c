//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 6

int main(){
    int password_length = 0;
    char password[MAX_PASSWORD_LENGTH+1];
    
    srand(time(NULL)); //Seed for random number generator
    
    printf("Enter desired password length (between %d and %d): ",MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d",&password_length);
    
    if(password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH){ //Check for valid length
        printf("Invalid password length\n");
        exit(EXIT_FAILURE); //Terminate program with error code
    }
    
    //Character sets for password generation
    char charset_lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char charset_uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char charset_digits[] = "0123456789";
    char charset_special[] = "!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    
    //Generate password
    int i = 0;
    while(i < password_length){
        int choice = rand() % 4; //Choose charachter set randomly
        
        switch(choice){
            case 0:
                password[i] = charset_lowercase[rand() % strlen(charset_lowercase)];
                break;
            case 1:
                password[i] = charset_uppercase[rand() % strlen(charset_uppercase)];
                break;
            case 2:
                password[i] = charset_digits[rand() % strlen(charset_digits)];
                break;
            case 3:
                password[i] = charset_special[rand() % strlen(charset_special)];
                break;
            default:
                break;
        }
        i++;
    }
    password[i] = '\0'; //Terminate password string
    
    printf("Generated password: %s\n",password);
    
    return 0;
}