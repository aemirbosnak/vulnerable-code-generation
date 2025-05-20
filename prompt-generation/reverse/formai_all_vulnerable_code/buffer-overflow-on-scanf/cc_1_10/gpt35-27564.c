//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){

    printf("Welcome to the C Secure Password Generator!\n");

    //ask user for password length
    int length;
    printf("Enter length of password (min 8, max 20): ");
    scanf("%d", &length);

    //validate password length
    while(length<8 || length>20){
        printf("Invalid length. Please enter length between 8 and 20: ");
        scanf("%d", &length);
    }

    //initialize character sets
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()-_+=";

    //determine number of characters from each set based on password length
    int lower_count = length/4;
    int upper_count = length/4;
    int digit_count = length/4;
    int special_count = length - lower_count - upper_count - digit_count;

    //generate password
    char password[length+1]; //+1 for null terminator
    srand(time(NULL)); //seed random number generator
    int i;

    //get random lower case characters
    for(i=0;i<lower_count;i++){
        int index = rand() % strlen(lower);
        password[i] = lower[index];
    }

    //get random upper case characters
    for(i=lower_count;i<lower_count+upper_count;i++){
        int index = rand() % strlen(upper);
        password[i] = upper[index];
    }

    //get random digits
    for(i=lower_count+upper_count;i<lower_count+upper_count+digit_count;i++){
        int index = rand() % strlen(digits);
        password[i] = digits[index];
    }

    //get random special characters
    for(i=lower_count+upper_count+digit_count;i<length;i++){
        int index = rand() % strlen(special);
        password[i] = special[index];
    }

    password[length] = '\0'; //add null terminator to end of string

    //shuffle characters in the password
    for(i=0;i<length;i++){
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    //print generated password
    printf("Your randomly generated password is: %s\n", password);

    return 0;
}