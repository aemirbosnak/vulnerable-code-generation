//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

void draw_rainbow(int r, int g, int b) {
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int i, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++) {
        switch (password[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                strength++;
                draw_rainbow(255, 0, 0);
                printf("%c ", password[i]);
                draw_rainbow(0, 255, 0);
                break;
            default:
                draw_rainbow(255, 255, 0);
                printf("%c ", password[i]);
                draw_rainbow(0, 0, 255);
                break;
        }
    }

    printf("\nYour password strength is: ");
    switch (strength) {
        case 0:
            printf("Weak");
            break;
        case 1:
            printf("Fair");
            break;
        case 2:
            printf("Good");
            break;
        case 3:
            printf("Strong");
            break;
        case 4:
            printf("Excellent");
            break;
    }

    return 0;
}