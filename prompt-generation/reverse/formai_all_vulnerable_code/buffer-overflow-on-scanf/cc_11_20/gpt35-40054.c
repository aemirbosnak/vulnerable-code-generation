//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age < 0 || age > 120) {
        printf("Invalid age entered\n");
        return 1;
    }

    double weight;

    printf("Enter your weight (in kilograms): ");
    scanf("%lf", &weight);

    if(weight < 0 || weight > 500) {
        printf("Invalid weight entered\n");
        return 1;
    }

    long int phoneNumber;

    printf("Enter your phone number: ");
    scanf("%ld", &phoneNumber);

    if(phoneNumber < 1000000000 || phoneNumber > 9999999999) {
        printf("Invalid phone number entered\n");
        return 1;
    }

    char gender;

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    if(gender != 'M' && gender != 'F') {
        printf("Invalid gender entered\n");
        return 1;
    }

    char email[50];

    printf("Enter your email address: ");
    scanf("%s", email);

    // A simple validation for email addresses
    int atCount = 0, dotCount = 0;
    for(int i = 0; email[i] != '\0'; i++) {
        if(email[i] == '@') {
            atCount++;
        } else if(email[i] == '.') {
            dotCount++;
        }
    }
    if(atCount != 1 || dotCount < 1 || dotCount > 3) {
        printf("Invalid email address entered\n");
        return 1;
    }

    printf("Valid data entered\n");

    return 0;
}