//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // macro for finding max value

// function to detect intrusion
int detect_intrusion(char* username, char* password, char* ip_address) {
    // check if username and password are empty
    if (strlen(username) == 0 || strlen(password) == 0) {
        printf("Username and Password are required!\n");
        return 0;
    }

    // check if username contains only alphabets
    for (int i = 0; i < strlen(username); i++) {
        if (!isalpha(username[i])) {
            printf("Invalid Username Format!\n");
            return 0;
        }
    }

    // check if password contains at least 8 characters, 1 uppercase, 1 lowercase and 1 digit
    int uppercase = 0, lowercase = 0, digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        }
    }
    if (strlen(password) < 8 || !uppercase || !lowercase || !digit) {
        printf("Invalid Password Format!\n");
        return 0;
    }

    // check if IP address is valid
    int a, b, c, d;
    if (sscanf(ip_address, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
        printf("Invalid IP Address Format!\n");
        return 0;
    }
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255) {
        printf("Invalid IP Address Range!\n");
        return 0;
    }

    // all validations passed, return success
    printf("Intrusion Detected! User %s with password %s attempted to login from IP address %s\n", username, password, ip_address);
    return 1;
}

// main function to test the intrusion detection system
int main() {
    char* username = "JohnDoe";
    char* password = "P@ssw0rd123";
    char* ip_address = "192.168.0.1";
    detect_intrusion(username, password, ip_address);
    return 0;
}