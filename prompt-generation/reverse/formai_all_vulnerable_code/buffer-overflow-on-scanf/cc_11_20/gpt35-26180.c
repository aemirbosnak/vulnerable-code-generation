//FormAI DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char output[100] = {'\0'};
    int count = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", input);

    // Reverse the string
    for(int i=strlen(input)-1; i>=0; i--) {
        output[count] = input[i];
        count++;
    }

    // Count the number of vowels in the string
    int vowelCount = 0;
    for(int i=0; i<strlen(input); i++) {
        switch(input[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowelCount++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowelCount++;
                break;
            default:
                break;
        }
    }

    // Capitalize every other letter of the string
    for(int i=0; i<strlen(output); i++) {
        if(i % 2 == 0 && output[i] >= 'a' && output[i] <= 'z') {
            output[i] = output[i] - 32; // Convert lowercase letter to uppercase
        }
    }

    printf("Reversed string: %s\n", output);
    printf("Number of vowels in string: %d\n", vowelCount);

    return 0;
}