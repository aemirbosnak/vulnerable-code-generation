//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
/* 
The Case of the Missing Passwords

Once again, I find myself embroiled in a mystery that requires my expertise in the world of computer programming.
This time, the case involves a series of hacked accounts, all with easily guessable passwords. As a precaution, I have taken it upon myself to create a secure password generator.

I shall now begin my investigation by constructing a C program that generates random passwords with varying levels of complexity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Initializing variables
    int length, choice, i;
    char password[100];

    printf("Greetings! I am Sherlock Holmes, and I have been contracted to create a secure password generator.\n");
    printf("How long would you like your password to be? (must be between 8 and 24 characters)\n");
    scanf("%d", &length);
    
    //Error handling for invalid password lengths
    while(length < 8 || length > 24){
        printf("Invalid input. Please input a valid number between 8 and 24.\n");
        scanf("%d", &length);
    }

    printf("Excellent. Now, please choose your desired level of complexity:\n");
    printf("1 - Simple lowercase letters only\n");
    printf("2 - Lowercase and uppercase letters\n");
    printf("3 - Lowercase and uppercase letters, as well as numbers\n");
    printf("4 - Lowercase and uppercase letters, numbers, and special characters\n");
    scanf("%d", &choice);

    //Error handling for invalid complexity levels
    while(choice < 1 || choice > 4){
        printf("Invalid input. Please input a valid number between 1 and 4.\n");
        scanf("%d", &choice);
    }

    //Switch case for different complexity levels
    switch(choice){
        case 1:
            for(i = 0; i < length; i++){
                password[i] = (rand() % 26) + 97;
            }
            break;
        case 2:
            for(i = 0; i < length; i++){
                int type = rand() % 2;
                if(type == 0){
                    password[i] = (rand() % 26) + 97;
                }
                else{
                    password[i] = (rand() % 26) + 65;
                }
            }
            break;
        case 3:
            for(i = 0; i < length; i++){
                int type = rand() % 3;
                if(type == 0){
                    password[i] = (rand() % 26) + 97;
                }
                else if(type == 1){
                    password[i] = (rand() % 26) + 65;
                }
                else{
                    password[i] = (rand() % 10) + 48;
                }
            }
            break;
        case 4:
            for(i = 0; i < length; i++){
                int type = rand() % 4;
                if(type == 0){
                    password[i] = (rand() % 26) + 97;
                }
                else if(type == 1){
                    password[i] = (rand() % 26) + 65;
                }
                else if(type == 2){
                    password[i] = (rand() % 10) + 48;
                }
                else{
                    int special_type = rand() % 10;
                    if(special_type <= 2){
                        password[i] = (rand() % 15) + 33;
                    }
                    else if(special_type <= 5){
                        password[i] = (rand() % 7) + 58;
                    }
                    else{
                        password[i] = (rand() % 6) + 91;
                    }
                }
            }
            break;
    }

    printf("Your new password is:\n");
    printf("%s\n", password);

    printf("I do hope this satisfies your security needs. If you require any further assistance, do not hesitate to contact me.\n");

    return 0;
}