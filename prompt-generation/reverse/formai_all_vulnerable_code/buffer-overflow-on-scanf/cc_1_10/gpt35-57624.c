//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: recursive
#include<stdio.h>
#include<string.h>

int check_length(char[]); // Function to check the length of given password
int check_uppercase(char[]); // Function to check at least one upper case character is there
int check_lowercase(char[]); // Function to check at least one lower case character is there
int check_special(char[]); // Function to check at least one special character is there
int check_number(char[]); // Function to check at least one number is there

int main() {
    char password[50];
    int len_check, upper_check, lower_check, special_check, num_check;
    printf("Enter your password: ");
    scanf("%s", password);

    len_check = check_length(password);
    upper_check = check_uppercase(password);
    lower_check = check_lowercase(password);
    special_check = check_special(password);
    num_check = check_number(password);

    if(len_check == 1 && upper_check == 1 && lower_check == 1 && special_check == 1 && num_check == 1) {
        printf("Password is strong\n");
    }
    else {
        printf("Password is weak\n");
    }
    return 0;
}

int check_length(char password[]) {
    if(strlen(password) >= 8) {
        return 1;
    }
    else {
        printf("Password should be at least 8 characters long\n");
        return check_length(password);
    }
}

int check_uppercase(char password[]) {
    int i, flag = 0;
    for(i = 0; i < strlen(password); i++) {
        if(isupper(password[i])) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        return 1;
    }
    else {
        printf("Password should contain at least one uppercase character\n");
        return check_uppercase(password);
    }
}

int check_lowercase(char password[]) {
    int i, flag = 0;
    for(i = 0; i < strlen(password); i++) {
        if(islower(password[i])) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        return 1;
    }
    else {
        printf("Password should contain at least one lowercase character\n");
        return check_lowercase(password);
    }
}

int check_special(char password[]) {
    int i, flag = 0;
    for(i = 0; i < strlen(password); i++) {
        if(ispunct(password[i])) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        return 1;
    }
    else {
        printf("Password should contain at least one special character\n");
        return check_special(password);
    }
}

int check_number(char password[]) {
    int i, flag = 0;
    for(i = 0; i < strlen(password); i++) {
        if(isdigit(password[i])) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        return 1;
    }
    else {
        printf("Password should contain at least one number\n");
        return check_number(password);
    }
}