//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int choice;
    FILE *fp;
    int num[MAX_SIZE], n, i;

    printf("Select an option:\n");
    printf("1. Write to file\n");
    printf("2. Read from file\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of integers: ");
            scanf("%d", &n);

            printf("Enter the integers: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &num[i]);
            }

            fp = fopen("numbers.txt", "w");
            if (fp == NULL) {
                printf("Error: File could not be opened!");
                exit(1);
            }

            for (i = 0; i < n; i++) {
                fprintf(fp, "%d ", num[i]);
            }

            fclose(fp);
            printf("Data written to file successfully!");
            break;
        
        case 2:
            fp = fopen("numbers.txt", "r");
            if (fp == NULL) {
                printf("Error: File could not be opened!");
                exit(1);
            }

            fscanf(fp, "%d", &num[0]);
            printf("Numbers from file: %d ", num[0]);

            for (i = 1; !feof(fp) && i < MAX_SIZE; i++) {
                fscanf(fp, "%d", &num[i]);
                printf("%d ", num[i]);
            }

            fclose(fp);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}