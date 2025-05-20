//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;
    char ch;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    //check for minimum length
    if(length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    //check for uppercase letters
    if(!isupper(password[0])) {
        printf("Password should contain at least one uppercase letter.\n");
        return 0;
    }

    //check for lowercase letters
    if(!islower(password[0])) {
        printf("Password should contain at least one lowercase letter.\n");
        return 0;
    }

    //check for digits
    if(!isdigit(password[0])) {
        printf("Password should contain at least one digit.\n");
        return 0;
    }

    //check for special characters
    if(!isalpha(password[0])) {
        printf("Password should contain at least one special character.\n");
        return 0;
    }

    //check for consecutive characters
    for(i=0; i<length-1; i++) {
        if(password[i] == password[i+1]) {
            printf("Password should not contain consecutive characters.\n");
            return 0;
        }
    }

    //check for repeated characters
    for(i=0; i<length-2; i++) {
        if(password[i] == password[i+2]) {
            printf("Password should not contain repeated characters.\n");
            return 0;
        }
    }

    //check for dictionary words
    FILE *fp;
    char word[10];
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL) {
        printf("Dictionary file not found.\n");
        return 0;
    }
    while(fscanf(fp, "%s", word)!= EOF) {
        if(strcmp(word, password) == 0) {
            printf("Password should not be a dictionary word.\n");
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);

    printf("Password is strong.\n");

    return 0;
}