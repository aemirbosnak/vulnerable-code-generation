//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 26
#define NUM_COUNT 10
#define SPECIAL_COUNT 12

const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char special_chars[] = "!@#$%^&*()_+-=[]{}|\\:;\"'<>,.?/";

void generate_password(int length, char *password) {
    int lower_case_count = length / 3;
    int upper_case_count = length / 3;
    int digits_count = length / 3;
    int special_chars_count = length - (lower_case_count * CHAR_COUNT + upper_case_count * CHAR_COUNT + digits_count * NUM_COUNT);

    if (lower_case_count < 0 || upper_case_count < 0 || digits_count < 0 || special_chars_count < 0 || length < 4) {
        printf("Invalid password length.\n");
        return;
    }

    for (int i = 0; i < lower_case_count; i++) {
        password[i] = lower_case[rand() % CHAR_COUNT];
    }

    for (int i = lower_case_count; i < lower_case_count + upper_case_count; i++) {
        password[i] = upper_case[rand() % CHAR_COUNT];
    }

    for (int i = lower_case_count + upper_case_count; i < length; i++) {
        if (special_chars_count > 0) {
            password[i] = special_chars[rand() % SPECIAL_COUNT];
            special_chars_count--;
        } else {
            password[i] = digits[rand() % NUM_COUNT];
            digits_count--;
            if (digits_count == 0) {
                lower_case_count++;
                i--;
            }
        }
    }

    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    char password[length + 1];

    generate_password(length, password);
    printf("Generated password: %s\n", password);

    return 0;
}