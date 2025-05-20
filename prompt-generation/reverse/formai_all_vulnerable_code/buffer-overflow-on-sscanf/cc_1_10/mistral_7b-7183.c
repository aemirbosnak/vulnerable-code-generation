//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define BUFFER_SIZE 1024

void process_line(char *line) {
    char op[5], num1[MAX_LINE], num2[MAX_LINE], result[MAX_LINE];
    double value1, value2, result_value;
    int index1, index2;

    sscanf(line, "%s %s %s", op, num1, num2);

    if (strlen(op) > 4 || strlen(op) < 1) {
        printf("Invalid operator: %s\n", op);
        return;
    }

    value1 = strtod(num1, NULL);
    value2 = strtod(num2, NULL);

    switch (op[0]) {
        case '+':
            result_value = value1 + value2;
            break;
        case '-':
            result_value = value1 - value2;
            break;
        case '*':
            result_value = value1 * value2;
            break;
        case '/':
            if (value2 == 0) {
                printf("Cannot divide by zero.\n");
                return;
            }
            result_value = value1 / value2;
            break;
        default:
            printf("Invalid operator: %s\n", op);
            return;
    }

    snprintf(result, sizeof(result), "%.10g", result_value);

    index1 = strlen(num1) - 1;
    index2 = strlen(num2) - 1;

    while (index1 >= 0 && (num1[index1] == ' ' || num1[index1] == '\t')) {
        index1--;
    }

    while (index2 >= 0 && (num2[index2] == ' ' || num2[index2] == '\t')) {
        index2--;
    }

    if (index1 >= 0 && index2 >= 0) {
        printf("%s %s = %s\n", num1, op, result);
    } else {
        printf("%s %s = %s\n", "", op, result);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    FILE *file;
    size_t bytes_read;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        process_line(buffer);
    }

    fclose(file);

    return 0;
}