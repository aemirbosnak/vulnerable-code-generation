//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a C statement to parse: ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Parsing C statement
    int i = 0;
    int num_vars = 0;
    char var_type[10];
    char var_name[10];
    char parsed_vars[20][20];

    while (input[i] != '\0') {
        // Looking for variable type
        if (input[i] == 'i' && input[i+1] == 'n' && input[i+2] == 't') {
            num_vars++;
            strcpy(var_type, "int");
            i += 3;
        } else if (input[i] == 'c' && input[i+1] == 'h' && input[i+2] == 'a' && input[i+3] == 'r') {
            num_vars++;
            strcpy(var_type, "char");
            i += 4;
        }

        // Looking for variable name
        if (input[i] >= 'a' && input[i] <= 'z') {
            int j = 0;
            while (input[i] != ',' && input[i] != ';') {
                var_name[j] = input[i];
                i++;
                j++;
            }
            var_name[j] = '\0';

            // Saving variable name and type
            sprintf(parsed_vars[num_vars-1], "%s %s", var_type, var_name);
        }

        i++;
    }

    // Printing out parsed variables
    printf("Parsed variables:\n");
    for (int j = 0; j < num_vars; j++) {
        printf("%s\n", parsed_vars[j]);
    }

    return 0;
}