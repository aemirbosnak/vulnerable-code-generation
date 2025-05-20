//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[1000], temp[10];
    printf("Enter string in C Cat Language: ");
    gets(input);
    int i, j = 0, k = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'c') {
            output[k++] = 'm';
            output[k++] = 'e';
            output[k++] = 'o';
            output[k++] = 'w';
        } else if (input[i] == 'C') {
            output[k++] = 'M';
            output[k++] = 'E';
            output[k++] = 'O';
            output[k++] = 'W';
        } else if (input[i] == '(') {
            output[k++] = '(';
            output[k++] = 'p';
            output[k++] = 'u';
            output[k++] = 'r';
            output[k++] = 'r';
            output[k++] = '(';
        } else if (input[i] == ')') {
            output[k++] = ')';
            output[k++] = ')';
        } else if (input[i] == '{') {
            output[k++] = '{';
        } else if (input[i] == '}') {
            output[k++] = '}';
        } else if (input[i] == ';') {
            output[k++] = ';';
            output[k++] = '\n';
        } else if (input[i] == '#') {
            output[k++] = '#';
        } else if (input[i] == ' ') {
            output[k++] = ' ';
        } else if (input[i] == '\n') {
            output[k++] = '\n';
        } else if (input[i] >= '0' && input[i] <= '9') {
            int n = input[i] - '0';
            while (i + 1 < strlen(input) && input[i+1] >= '0' && input[i+1] <= '9') {
                i++;
                n = n * 10 + (input[i] - '0');
            }
            sprintf(temp, "%d", n);
            strcat(output, temp);
            k += strlen(temp);
        } else if (input[i] != '\r') {
            printf("Unknown character: %c\n", input[i]);
        }
    }
    printf("Output:\n%s\n", output);
    return 0;
}