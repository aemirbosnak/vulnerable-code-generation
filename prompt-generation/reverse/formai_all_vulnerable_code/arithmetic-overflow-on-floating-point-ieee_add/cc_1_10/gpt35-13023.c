//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int main()
{
    FILE *fp;
    char filename[] = "example.csv";
    char line[MAX_LINE_LEN];
    char *token;
    char *parsed_tokens[10]; // maximum 10 tokens per row
    int num_tokens;
    int row_num = 0;

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening %s file\n", filename);
        return 1;
    }

    printf("Row, Column 1, Column 2, Column 3, Column 4\n");

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        // Parse line into tokens
        num_tokens = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            parsed_tokens[num_tokens] = token;
            num_tokens++;
            token = strtok(NULL, ",");
        }

        // Print parsed values
        printf("%d, %s, %s, %s, %s", row_num, parsed_tokens[0], parsed_tokens[1], parsed_tokens[2], parsed_tokens[3]);

        // Do statistical analysis of values
        float value1 = atof(parsed_tokens[1]);
        float value2 = atof(parsed_tokens[2]);
        float value3 = atof(parsed_tokens[3]);

        printf("  Mean: %.2f, %.2f, %.2f", (value1+value2+value3)/3, (value1+value2)/2, (value2+value3)/2);
        printf("  Median: %.2f, %.2f, %.2f\n", value1, value2, value3);

        row_num++;
    }

    fclose(fp);
    return 0;
}