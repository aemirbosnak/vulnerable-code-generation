//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], line[100], *token;
    char *name, *age, *gender, *occupation;
    int count = 0;

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("CSV file contents:\n");

    while (fgets(line, 100, fp)) {
        count++;

        if (count > 1) {
            token = strtok(line, ",");

            if (token != NULL) {
                name = token;
            } else {
                printf("Error parsing file!\n");
                return 1;
            }

            token = strtok(NULL, ",");

            if (token != NULL) {
                age = token;
            } else {
                printf("Error parsing file!\n");
                return 1;
            }

            token = strtok(NULL, ",");

            if (token != NULL) {
                gender = token;
            } else {
                printf("Error parsing file!\n");
                return 1;
            }

            token = strtok(NULL, ",");

            if (token != NULL) {
                occupation = token;
            } else {
                printf("Error parsing file!\n");
                return 1;
            }

            printf("Name: %s\n", name);
            printf("Age: %s\n", age);
            printf("Gender: %s\n", gender);
            printf("Occupation: %s\n\n", occupation);
        }
    }

    fclose(fp);
    return 0;
}