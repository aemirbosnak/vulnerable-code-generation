//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int size;
    int choice;
    bool valid_input = true;

    do {
        printf("Enter a string (max %d characters): ", MAX_SIZE - 1);
        fgets(input, MAX_SIZE, stdin);
        size = strlen(input);
        if (size == 0 || size == MAX_SIZE - 1) {
            printf("Invalid input. Please try again.\n");
            valid_input = false;
        }
    } while (!valid_input);

    do {
        printf("Choose an operation:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT\n");
        printf("5. Shift left\n");
        printf("6. Shift right\n");
        scanf("%d", &choice);
        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 6);

    switch (choice) {
        case 1:
            for (int i = 0; i < size; i++) {
                output[i] = input[i] & 0x7F;
            }
            break;
        case 2:
            for (int i = 0; i < size; i++) {
                output[i] = input[i] | 0x7F;
            }
            break;
        case 3:
            for (int i = 0; i < size; i++) {
                output[i] = input[i] ^ 0x7F;
            }
            break;
        case 4:
            for (int i = 0; i < size; i++) {
                output[i] = ~input[i];
            }
            break;
        case 5:
            for (int i = 0; i < size; i++) {
                output[i] = input[i] << 1;
            }
            break;
        case 6:
            for (int i = 0; i < size; i++) {
                output[i] = input[i] >> 1;
            }
            break;
    }

    printf("Output:\n");
    for (int i = 0; i < size; i++) {
        printf("%c", output[i]);
    }

    return 0;
}