//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator\n");

    int length = 0;
    while (length < 8 || length > 16) {
        printf("Please input the desired length of your password (between 8-16 characters): ");
        if (scanf("%d", &length) != 1) {
            printf("Invalid input. Please try again.\n");
            length = 0;
            while (getchar() != '\n');
        }
    }

    char password[length+1];
    for (int i = 0; i < length; ++i) {
        int random = rand() % 62;
        if (random < 26) {
            password[i] = 'A' + random;
        } else if (random < 52) {
            password[i] = 'a' + (random - 26);
        } else {
            password[i] = '0' + (random - 52);
        }
    }
    password[length] = '\0';

    printf("Your secure password is: ");
    for (int i = 0; i < length; ++i) {
        printf("*");
    }
    printf("\n");

    char check[5] = {'0', '0', '0', '0', '\0'};
    for (int i = 0; i < 3; ++i) {
        int index = rand() % length;
        password[index] = (rand() % 10) + '0';
        check[i] = index + '1';
    }
    int index = rand() % length;
    password[index] = (rand() % 26) + 'A';
    check[3] = index + '1';

    char answer[5];
    printf("Please enter the positions of the three digits in your password (e.g. 134): ");
    if (scanf("%4s", answer) != 1 || answer[3] != '\0') {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    int correct = 0;
    for (int i = 0; i < 3; ++i) {
        if (answer[i] == check[i]) {
            ++correct;
        } else if (answer[i] < '1' || answer[i] > '0'+length) {
            printf("Invalid input. Please try again.\n");
            return 1;
        }
    }

    if (correct == 3) {
        printf("Congratulations! You have successfully generated a secure password.\n");
        printf("Your secure password is: %s\n", password);
    } else {
        printf("Sorry, the positions of the three digits you entered are incorrect.\n");
    }

    return 0;
}