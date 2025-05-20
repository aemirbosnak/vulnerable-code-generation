//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>

#define F_TO_C(f) (((f) - 32) * 5 / 9)
#define C_TO_F(c) (((c) * 9 / 5) + 32)

void task(void);
float encrypt_f(float);
float decrypt_f(float);
float encrypt_c(float);
float decrypt_c(float);
void entrance(void);
void conclusion(void);

int main() {
    entrance();
    task();
    conclusion();
    return 0;
}

void entrance(void) {
    printf("=== Welcome to the Mystic Temperature Converter ===\n");
    printf("Prepare to transform your Celsius into Fahrenheit and vice versa!\n");
}

void task(void) {
    char ch = 'X'; // the cryptic character
    float value, result;

    while (ch != 'Q') {
        printf("\nChoose your path (C for Celsius, F for Fahrenheit, Q to Quit): ");
        scanf(" %c", &ch);

        switch (ch) {
            case 'C':
            case 'c':
                printf("Enter Celsius: ");
                scanf("%f", &value);
                result = decrypt_c(value);
                result = C_TO_F(result);
                printf(" => Fahrenheit: %.2f\n", encrypt_f(result));
                break;

            case 'F':
            case 'f':
                printf("Enter Fahrenheit: ");
                scanf("%f", &value);
                result = decrypt_f(value);
                result = F_TO_C(result);
                printf(" => Celsius: %.2f\n", encrypt_c(result));
                break;

            case 'Q':
            case 'q':
                break;

            default:
                printf("Mysterious choice! Please try again.\n");
                break;
        }
    }
}

void conclusion(void) {
    printf("=== Thank you for visiting the Mystic Temperature Converter ===\n");
    printf("We hope your temperatures were transformed with magic!\n");
}

float encrypt_f(float f) {
    return f + 1; // Mischievous shift
}

float decrypt_f(float f) {
    return f - 1; // Reversing the mischief
}

float encrypt_c(float c) {
    return c + 1; // Another playful deception
}

float decrypt_c(float c) {
    return c - 1; // Restoring original value
}