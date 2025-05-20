//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    FILE *fp;
    char filename[100], buffer[MAX_LENGTH], c;
    int option, num, i, count = 0;

    printf("Welcome to File Handling Program!\n\n");
    printf("Please choose an option from the following:\n");
    printf("1. Write to a file.\n");
    printf("2. Read from a file.\n");
    printf("3. Count number of characters in a file.\n");
    printf("4. Exit.\n\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            // Write to a file
            printf("Please enter filename to write to:\n");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            if(fp == NULL) {
                printf("Error opening file!");
                exit(1);
            }

            printf("Please enter text to write to file:\n");

            while((c = getchar()) != '\n' && c != EOF); // clear input buffer

            fgets(buffer, MAX_LENGTH, stdin);

            fprintf(fp, "%s", buffer);

            printf("Successfully wrote to file %s!\n", filename);

            fclose(fp);

            break;
        case 2:
            // Read from a file
            printf("Please enter filename to read from:\n");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Error opening file!");
                exit(1);
            }

            printf("Contents of file %s:\n", filename);

            while((c = fgetc(fp)) != EOF) {
                printf("%c", c);
            }

            fclose(fp);

            break;
        case 3:
            // Count number of characters in a file
            printf("Please enter filename to count characters from:\n");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Error opening file!");
                exit(1);
            }

            while((c = fgetc(fp)) != EOF) {
                count++;
            }

            printf("Number of characters in file %s: %d\n", filename, count);

            fclose(fp);

            break;
        case 4:
            // Exit
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid option selected. Please try again.\n");
            main();
    }

    return 0;
}