//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char name[20], email[50], phone[15];
    int age;
    bool valid_name, valid_email, valid_phone, valid_age;

    // Input validation loop
    do {

        // Name validation
        valid_name = false;
        printf("Enter your full name: ");
        fgets(name, 20, stdin);
        name[strcspn(name, "\n")] = 0;
        if (strlen(name) > 0) {
            valid_name = true;
        } else {
            printf("Invalid name, please try again.\n");
        }

        // Email validation
        valid_email = false;
        printf("Enter your email address: ");
        fgets(email, 50, stdin);
        email[strcspn(email, "\n")] = 0;
        if (strchr(email, '@') != NULL && strchr(email, '.') != NULL) {
            valid_email = true;
        } else {
            printf("Invalid email, please try again.\n");
        }

        // Phone validation
        valid_phone = false;
        printf("Enter your phone number: ");
        fgets(phone, 15, stdin);
        phone[strcspn(phone, "\n")] = 0;
        if (strlen(phone) == 10 && strtol(phone, NULL, 10) != 0) {
            valid_phone = true;
        } else {
            printf("Invalid phone number, please try again.\n");
        }

        // Age validation
        valid_age = false;
        printf("Enter your age: ");
        if (scanf("%d", &age) == 1) {
            if (age >= 18 && age <= 120) {
                valid_age = true;
            } else {
                printf("Invalid age, please try again.\n");
            }
        } else {
            printf("Invalid age, please try again.\n");
        }

        // If validation fails, clear input buffer
        if (!valid_name || !valid_email || !valid_phone || !valid_age) {
            fflush(stdin);
        }

    } while (!valid_name || !valid_email || !valid_phone || !valid_age);

    // Print validated inputs
    printf("\n\nThank you! Your inputs have been validated!\n\n");
    printf("Full Name: %s\n", name);
    printf("Email Address: %s\n", email);
    printf("Phone Number: %s\n", phone);
    printf("Age: %d\n", age);

    return 0;
}