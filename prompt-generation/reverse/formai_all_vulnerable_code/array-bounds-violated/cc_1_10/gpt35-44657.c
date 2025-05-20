//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

bool is_valid_name(char *name) {
    int i;
    int len = strlen(name);
    for (i = 0; i < len; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool is_valid_email(char *email) {
    int i;
    int len = strlen(email);
    bool at = false;
    for (i = 0; i < len; i++) {
        if (email[i] == '@') {
            if (at || i == 0 || i == len-1) {
                return false;
            }
            at = true;
        } else if (email[i] == '.') {
            if (i == 0 || i == len-1 || email[i-1] == '.') {
                return false;
            }
        } else if (!isalpha(email[i]) && !isdigit(email[i]) && email[i] != '-' && email[i] != '_' && email[i] != '+') {
            return false;
        }
    }
    return at;
}

bool is_valid_phone(char *phone) {
    int i;
    int len = strlen(phone);
    if (len != 10) {
        return false;
    }
    for (i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char name[MAX_LEN], email[MAX_LEN], phone[MAX_LEN];
    
    printf("Hello! Welcome to the Data Validation Program.\n");
    printf("Please enter your name: ");
    fgets(name, MAX_LEN, stdin);
    name[strlen(name)-1] = '\0'; // remove newline character from fgets output
    while (!is_valid_name(name)) {
        printf("Invalid name, please enter again: ");
        fgets(name, MAX_LEN, stdin);
        name[strlen(name)-1] = '\0';
    }
    
    printf("Great! Now enter your email: ");
    fgets(email, MAX_LEN, stdin);
    email[strlen(email)-1] = '\0';
    while (!is_valid_email(email)) {
        printf("Invalid email, please enter again: ");
        fgets(email, MAX_LEN, stdin);
        email[strlen(email)-1] = '\0';
    }
    
    printf("Awesome! Finally, enter your phone number (10 digits): ");
    fgets(phone, MAX_LEN, stdin);
    phone[strlen(phone)-1] = '\0';
    while (!is_valid_phone(phone)) {
        printf("Invalid phone number, please enter again: ");
        fgets(phone, MAX_LEN, stdin);
        phone[strlen(phone)-1] = '\0';
    }
    
    printf("Thank you! Here is your information:\n");
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Congratulations! Your data has been successfully validated.\n");
    
    return 0;
}