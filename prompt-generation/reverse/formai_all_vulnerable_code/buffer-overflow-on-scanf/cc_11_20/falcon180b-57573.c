//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid email address
int is_valid_email(char* email) {
    int i = 0, j = 0, k = 0;

    // Check for special characters
    while (email[i]!= '@') {
        if (!isalpha(email[i])) {
            return 0;
        }
        i++;
    }

    // Check for domain name
    i++;
    while (email[i]!= '\0') {
        if (!isalpha(email[i])) {
            if (email[i]!= '.') {
                return 0;
            }
        }
        i++;
    }

    // Check for top-level domain
    while (email[i]!= '\0') {
        if (!isalpha(email[i])) {
            if (email[i]!= '.') {
                return 0;
            }
        }
        i++;
    }

    // Check for length of domain name and top-level domain
    j = i - 1;
    while (j > k && email[j]!= '.') {
        j--;
    }
    if (j - k < 2 || j - k > 63) {
        return 0;
    }

    // Check for length of top-level domain
    while (email[i]!= '\0') {
        if (email[i] == '.') {
            break;
        }
        i++;
    }
    k = i;
    while (email[i]!= '\0') {
        if (!isalpha(email[i])) {
            if (email[i]!= '.') {
                return 0;
            }
        }
        i++;
    }
    if (i - k < 2 || i - k > 63) {
        return 0;
    }

    return 1;
}

int main() {
    char email[100];

    // Get email address from user
    printf("Enter email address: ");
    scanf("%s", email);

    // Check if email address is valid
    if (is_valid_email(email)) {
        printf("Valid email address.\n");
    } else {
        printf("Invalid email address.\n");
    }

    return 0;
}