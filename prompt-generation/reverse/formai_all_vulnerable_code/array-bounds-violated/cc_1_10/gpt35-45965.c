//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main(){
    int length, num, cap, spe;
    char chars[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+}{[]?/><,.:`~";
    char password[128];
    srand(time(NULL)); // initalize random number generator

    // Ask user for password length
    printf("Enter the length of password: ");
    scanf("%d", &length);

    // Ask user for number of numbers
    printf("Enter the number of numbers in the password: ");
    scanf("%d", &num);

    // Ask user for number of capital letters
    printf("Enter the number of capital letters in the password: ");
    scanf("%d", &cap);

    // Ask user for number of special characters
    printf("Enter the number of special characters in the password: ");
    scanf("%d", &spe);

    // Check if the password length is greater than the sum of numbers, capital letters and special characters
    if(num + cap + spe > length){
        printf("Error: The sum of numbers, capital letters and special characters cannot be greater than the length of password.");
        return 0;
    }

    // Generate random characters for the password
    for(int i = 0; i < num; i++){
        password[i] = (rand() % 10) + 48; // ASCII code for numbers 0-9
    }
    for(int i = num; i < num+cap; i++){
        password[i] = (rand() % 26) + 65; // ASCII code for capital letters A-Z
    }
    for(int i = num+cap; i < num+cap+spe; i++){
        password[i] = chars[rand() % 31 + 52]; // ASCII code for special characters
    }
    for(int i = num+cap+spe; i < length; i++){
        password[i] = chars[rand() % 52]; // ASCII code for lowercase letters
    }
    password[length] = '\0'; // null terminate the password

    // Shuffle the characters in the password
    for(int i = 0; i < length; i++){
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Output the password
    printf("Your password is: %s", password);

    return 0;
}