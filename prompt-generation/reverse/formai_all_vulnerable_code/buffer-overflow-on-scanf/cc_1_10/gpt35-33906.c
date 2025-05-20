//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20

//function to generate a random upper case letter
char generate_random_upper_case_letter(){
    return 'A' + (rand() % 26);
}

//function to generate a random lower case letter
char generate_random_lower_case_letter(){
    return 'a' + (rand() % 26);
}

//function to generate a random digit
char generate_random_digit(){
    return '0' + (rand() % 10);
}

//function to generate a random special character
char generate_random_special_char(){
    char special_chars[] = "!@#$%^&*()_-+={}[]\\|:;\",.<>/?`~";
    int random_index = rand() % strlen(special_chars);
    return special_chars[random_index];
}

//function to check if a character is already present in the password
int check_if_char_exists_in_password(char password[], char c){
    for(int i=0; i<strlen(password); i++){
        if(password[i] == c)
            return 1;
    }
    return 0;
}

//function to generate the password
void generate_password(int length, char password[]){
    while(strlen(password) < length){
        int random_number = rand() % 4;
        char c;
        switch(random_number){
            case 0:
                c = generate_random_upper_case_letter();
                break;
            case 1:
                c = generate_random_lower_case_letter();
                break;
            case 2:
                c = generate_random_digit();
                break;
            case 3:
                c = generate_random_special_char();
                break;
        }
        if(!check_if_char_exists_in_password(password, c))
            password[strlen(password)] = c;
    }
    password[length] = '\0';
}


int main(){
    srand(time(NULL));
    char password[MAX_LENGTH+1];
    printf("Enter the password maximum length(%d): ", MAX_LENGTH);
    int length;
    scanf("%d", &length);
    if(length > MAX_LENGTH){
        printf("Error! Maximum length allowed is %d.", MAX_LENGTH);
        exit(0);
    }
    generate_password(length, password);
    printf("Generated Password: %s", password);
    return 0;
}