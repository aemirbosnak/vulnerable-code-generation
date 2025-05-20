//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
// A unique C User Input Sanitizer program in a multivariable style

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of allowed input string

int main() {
    char name[MAX_LENGTH], email[MAX_LENGTH], phone[MAX_LENGTH];
    int age;

    // Get user input
    printf("Enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your phone number: ");
    scanf("%s", phone);
    getchar(); // Clear input buffer

    // Sanitize user input
    // Sanitize name input by removing whitespace and ensuring only alphabets are present
    int i, j;
    char temp;
    for (i = j = 0; name[i] != '\0'; i++) {
        if (!isspace(name[i]) && isalpha(name[i])) {
            temp = (name[i] >= 'a' && name[i] <= 'z') ? name[i] - 32 : name[i]; // Convert to uppercase
            name[j++] = temp;
        }
    }
    name[j] = '\0'; // Terminate sanitized string

    // Sanitize age input by ensuring it is within a valid range (10-100)
    if (age < 10 || age > 100) {
        age = 10; // Set to lowest valid value if outside range
    }

    // Sanitize email input by ensuring it contains @ symbol and a valid domain name
    int at_pos = -1, dot_pos = -1;
    char *domain;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_pos = i;
        } else if (email[i] == '.') {
            dot_pos = i;
        }
    }
    domain = strchr(email, '@') + 1; // Get domain substring
    if (at_pos == -1 || dot_pos == -1 || strlen(domain) < 3) {
        strcpy(email, "invalid_email@example.com"); // Set to default if invalid
    }

    // Sanitize phone input by removing non-digits and ensuring it is 10 digits long
    for (i = j = 0; phone[i] != '\0'; i++) {
        if (isdigit(phone[i])) {
            phone[j++] = phone[i];
        }
    }
    if (j == 11 && phone[0] == '1') {
        memmove(phone, phone + 1, strlen(phone)); // Remove leading 1 from 11-digit numbers
    }
    if (j != 10) {
        strcpy(phone, "0000000000"); // Set to default if invalid
    }
    phone[j] = '\0'; // Terminate sanitized string

    // Print sanitized user input
    printf("\nSanitized user input:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);

    return 0;
}