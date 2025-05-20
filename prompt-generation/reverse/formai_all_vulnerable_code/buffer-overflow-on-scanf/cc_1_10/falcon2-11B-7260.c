//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
// Welcome to the Cyberpunk Spam Detection System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid email address
int isValidEmail(char *email) {
    // Check for email format
    if (strlen(email) < 5 || strchr(email, '@') == NULL) {
        return 0;
    }

    // Check for valid domain
    if (strstr(email, "gmail.com") == NULL && strstr(email, "hotmail.com") == NULL && strstr(email, "yahoo.com") == NULL) {
        return 0;
    }

    // Check for valid username
    if (strlen(strtok(email, "@")) < 3 || strchr(strtok(email, "@"), '.')!= NULL) {
        return 0;
    }

    return 1;
}

// Function to check if a string is a valid phone number
int isValidPhoneNumber(char *phone) {
    // Check for phone number format
    if (strlen(phone) < 10 || strchr(phone, '-')!= NULL) {
        return 0;
    }

    // Check for valid area code
    if (strlen(strtok(phone, "-")) < 3 || strchr(strtok(phone, "-"), '.')!= NULL) {
        return 0;
    }

    // Check for valid exchange code
    if (strlen(strtok(strtok(phone, "-"), "-")) < 3 || strchr(strtok(strtok(phone, "-"), "-"), '.')!= NULL) {
        return 0;
    }

    // Check for valid extension code
    if (strlen(strtok(strtok(strtok(phone, "-"), "-"), "-")) < 3 || strchr(strtok(strtok(strtok(phone, "-"), "-"), "-"), '.')!= NULL) {
        return 0;
    }

    return 1;
}

// Function to check if a string is spam
int isSpam(char *message) {
    // Check for spam keywords
    if (strstr(message, "viagra")!= NULL || strstr(message, "cialis")!= NULL || strstr(message, "online pharmacy")!= NULL) {
        return 1;
    }

    // Check for spam links
    if (strstr(message, "click here")!= NULL || strstr(message, "www.example.com")!= NULL) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    char email[100];
    char phone[20];
    char message[1000];

    printf("Enter email address: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Valid email address.\n");
    } else {
        printf("Invalid email address.\n");
    }

    printf("Enter phone number: ");
    scanf("%s", phone);

    if (isValidPhoneNumber(phone)) {
        printf("Valid phone number.\n");
    } else {
        printf("Invalid phone number.\n");
    }

    printf("Enter message: ");
    scanf("%s", message);

    if (isSpam(message)) {
        printf("Spam message detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}