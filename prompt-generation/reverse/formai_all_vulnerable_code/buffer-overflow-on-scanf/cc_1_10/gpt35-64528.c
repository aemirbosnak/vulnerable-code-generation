//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function is used to split a string based on a delimiter, in this case ','
char **split_string(char *str, char del) {
    char **result = NULL;
    char *token = strtok(str, &del);
    int count = 0;

    // Loop through each token and split the string at delimiters
    while (token) {
        result = realloc(result, sizeof(char*) * ++count);
        result[count-1] = token;
        token = strtok(NULL, &del);
    }
    result = realloc(result, sizeof(char*) * (count+1));
    result[count] = 0;
    return result;
}

int main(void) {
    char filename[100];
    printf("===========================\n");
    printf("Welcome to the CSV Reader!\n");
    printf("===========================\n");

    printf("Please enter the filename you would like to read: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Sorry, could not open file.\n");
        exit(1);
    }

    printf("\nReading file...\n");

    char csv_line[1024];
    while (fgets(csv_line, 1024, fp)) {
        printf("------------\n");
        char **values = split_string(csv_line, ',');
        int count = 0;
        while (values[count]) {
            printf("%s\n", values[count]);
            count++;
        }
        free(values);
    }

    fclose(fp);
    printf("\nThanks for using the CSV Reader!\n");
    return 0;
}