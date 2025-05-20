//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    char output[100] = "I LOVE CODING! ";

    printf("Welcome to the C String Manipulation Example Program! \n");
    printf("Please enter a string: ");
    scanf("%[^\n]s", input);
    getchar();

    int len = strlen(input);
    int middle = len/2;
    char temp;

    //reverse the string using pointers
    char* start = input;
    char* end = input + len - 1;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    //replace vowels with special characters
    for(int i = 0; i < len; i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
           input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            input[i] = '*';
        }
    }

    //insert the input string in the middle of the output string
    strcat(output, input);
    output[strlen(output)] = '\0';
    int output_len = strlen(output);
    for(int i = output_len - 1; i >= middle; i--) {
        output[i] = output[i-1];
    }
    for(int i = 0; i < middle; i++) {
        output[i] = '-';
    }

    //capitalize every other letter in the output string
    char current;
    for(int i = 0; i < output_len; i++) {
        current = output[i];
        if((i+1) % 2 == 0) {
            if(current >= 'a' && current <= 'z') {
                output[i] = current - 'a' + 'A';
            }
        }
    }

    printf("\nHere's the result: \n%s\n", output);

    return 0;
}