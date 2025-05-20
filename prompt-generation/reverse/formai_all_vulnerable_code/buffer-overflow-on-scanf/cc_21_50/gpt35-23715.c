//FormAI DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];
    int choice;

    printf("Welcome to Retro String Manipulator!\n");

    while (1) {
        printf("\nEnter a string: ");
        fgets(inputString, 100, stdin);

        printf("\nSelect an operation:\n");
        printf("1. Reverse\n");
        printf("2. UPPERCASE\n");
        printf("3. lowercase\n");
        printf("4. CamelCase\n");
        printf("5. Replace vowels with '*'\n");
        printf("6. Replace spaces with '_'\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int length = strlen(inputString);
                char reversed[length + 1];

                for (int i = 0; i < length; i++) {
                    reversed[i] = inputString[length - i - 1];
                }

                reversed[length] = '\0';

                printf("\nReversed string: %s\n", reversed);

                break;
            }

            case 2: {
                int length = strlen(inputString);

                for (int i = 0; i < length; i++) {
                    if (inputString[i] >= 'a' && inputString[i] <= 'z') {
                        inputString[i] -= 32;
                    }
                }

                printf("\nUppercase string: %s\n", inputString);

                break;
            }

            case 3: {
                int length = strlen(inputString);

                for (int i = 0; i < length; i++) {
                    if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
                        inputString[i] += 32;
                    }
                }

                printf("\nLowercase string: %s\n", inputString);

                break;
            }

            case 4: {
                int length = strlen(inputString);
                int prevChar = 32;

                for (int i = 0; i < length; i++) {
                    if (inputString[i] == ' ') {
                        prevChar = 32;
                        continue;
                    }

                    if (prevChar == 32) {
                        if (inputString[i] >= 'a' && inputString[i] <= 'z') {
                            inputString[i] -= 32;
                        }
                    }

                    prevChar = inputString[i];
                }

                printf("\nCamelCase string: %s\n", inputString);

                break;
            }

            case 5: {
                int length = strlen(inputString);

                for (int i = 0; i < length; i++) {
                    if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u') {
                        inputString[i] = '*';
                    }
                }

                printf("\nVowels replaced with '*': %s\n", inputString);

                break;
            }

            case 6: {
                int length = strlen(inputString);

                for (int i = 0; i < length; i++) {
                    if (inputString[i] == ' ') {
                        inputString[i] = '_';
                    }
                }

                printf("\nSpaces replaced with '_': %s\n", inputString);

                break;
            }

            default: {
                printf("\nInvalid input, please try again.\n");
            }
        }
    }

    return 0;
}