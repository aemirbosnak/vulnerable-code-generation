//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to our Log Analysis Program!\n");
    printf("Please enter the name of the log file: ");
    char filename[50];
    scanf("%s", filename);

    FILE *log_file = fopen(filename, "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(0);
    }

    char line[256];
    char shape[10];
    int count = 0;
    int i;

    printf("Would you like to see the log in a different shape? (y/n): ");
    char choice[2];
    scanf("%s", choice);

    if (choice[0] == 'y') {
        printf("Please enter the shape you would like to transform the log into: ");
        scanf("%s", shape);
        printf("\n");
    }

    while (fgets(line, sizeof(line), log_file)) {
        count++;
        if (strcmp(shape, "square") == 0) {
            for (i = 0; i < strlen(line); i++) {
                printf("%c ", line[i]);
            }
            printf("\n");
        } else if (strcmp(shape, "circle") == 0) {
            for (i = 0; i < strlen(line); i++) {
                printf("(%c) ", line[i]);
            }
            printf("\n");
        } else if (strcmp(shape, "triangle") == 0) {
            for (i = 0; i < strlen(line); i++) {
                printf("%c\n", line[i]);
            }
        } else {
            printf("%d. %s", count, line);
        }
    }

    fclose(log_file);
    printf("\nThank you for using our Log Analysis Program!\n");

    return 0;
}