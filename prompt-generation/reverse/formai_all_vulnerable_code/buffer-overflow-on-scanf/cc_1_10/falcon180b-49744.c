//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int i, j, k;
    int choice;

    printf("Enter your choice:\n");
    printf("1. Bitwise OR\n");
    printf("2. Bitwise AND\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    scanf("%d", &choice);

    printf("Enter the first string: ");
    scanf("%s", input);
    printf("Enter the second string: ");
    scanf("%s", input + strlen(input));

    switch(choice) {
        case 1: // Bitwise OR
            for(i = 0; i < strlen(input); i++) {
                output[i] = input[i] | input[i + strlen(input)];
            }
            break;
        case 2: // Bitwise AND
            for(i = 0; i < strlen(input); i++) {
                output[i] = input[i] & input[i + strlen(input)];
            }
            break;
        case 3: // Bitwise XOR
            for(i = 0; i < strlen(input); i++) {
                output[i] = input[i] ^ input[i + strlen(input)];
            }
            break;
        case 4: // Bitwise NOT
            for(i = 0; i < strlen(input); i++) {
                output[i] = ~input[i];
            }
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("Output:\n");
    for(i = 0; i < strlen(output); i++) {
        printf("%d ", output[i]);
    }

    return 0;
}