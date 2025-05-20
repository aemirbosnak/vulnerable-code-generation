//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120
#define MAX_PHONE_LENGTH 15

int validate_name(char* name);
int validate_age(int age);
int validate_phone(char* phone);

int main() {
    char name[MAX_NAME_LENGTH];
    int age;
    char phone[MAX_PHONE_LENGTH];
    
    printf("Enter your name: ");
    scanf("%s", name);

    int name_valid = validate_name(name);
    while (!name_valid) {
        printf("Invalid name. Please enter a valid name: ");
        scanf("%s", name);
        name_valid = validate_name(name);
    }

    printf("Enter your age: ");
    scanf("%d", &age);

    int age_valid = validate_age(age);
    while (!age_valid) {
        printf("Invalid age. Please enter a valid age: ");
        scanf("%d", &age);
        age_valid = validate_age(age);
    }

    printf("Enter your phone number: ");
    scanf("%s", phone);

    int phone_valid = validate_phone(phone);
    while (!phone_valid) {
        printf("Invalid phone number. Please enter a valid phone number: ");
        scanf("%s", phone);
        phone_valid = validate_phone(phone);
    }

    printf("\nName: %s\nAge: %d\nPhone Number: %s\n", name, age, phone);

    return 0;
}

int validate_name(char* name) {
    int name_length = strlen(name);
    if (name_length > MAX_NAME_LENGTH) {
        return 0;
    }
    for (int i = 0; i < name_length; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int validate_age(int age) {
    if (age < 0 || age > MAX_AGE) {
        return 0;
    }
    return 1;
}

int validate_phone(char* phone) {
    int phone_length = strlen(phone);
    if (phone_length != MAX_PHONE_LENGTH - 1) {
        return 0;
    }
    for (int i = 0; i < phone_length; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}