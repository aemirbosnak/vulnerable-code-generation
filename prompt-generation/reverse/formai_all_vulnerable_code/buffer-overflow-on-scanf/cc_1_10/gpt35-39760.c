//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *file_pointer;
    char filename[] = "example.txt";
    char buffer[MAX_SIZE];
    int option, num_numbers = 0, sum = 0, number;
    float average;

    // Open file in write mode and write some data
    file_pointer = fopen(filename, "w");
    fputs("22\n33\n44\n55\n66\n", file_pointer);
    fclose(file_pointer);

    printf("*** Welcome to the File Handling Application ***\n\n");
    printf("1. Read file\n");
    printf("2. Write to file\n");
    printf("3. Average of numbers\n");
    printf("4. Exit\n\n");

    do {
        printf("Please select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Open file in read mode and print contents
                file_pointer = fopen(filename, "r");
                printf("\nFile content:\n\n");

                while (fgets(buffer, MAX_SIZE, file_pointer) != NULL) {
                    printf("%s", buffer);
                }

                fclose(file_pointer);
                break;

            case 2:
                // Open file in append mode and write a new line
                file_pointer = fopen(filename, "a");
                printf("\nPlease enter a number to append: ");
                scanf("%d", &number);
                fprintf(file_pointer, "%d\n", number);
                fclose(file_pointer);
                break;

            case 3:
                // Open file in read mode, read numbers, calculate average and print result
                file_pointer = fopen(filename, "r");
                printf("\nCalculating average...\n");

                while (fscanf(file_pointer, "%d", &number) == 1) {
                    num_numbers++;
                    sum += number;
                }

                fclose(file_pointer);

                if (num_numbers > 0) {
                    average = (float) sum / num_numbers;
                    printf("Average of %d numbers: %.2f\n", num_numbers, average);
                } else {
                    printf("No numbers found in file.\n");
                }

                break;

            case 4:
                printf("\nThank you for using the File Handling Application!");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
        }

        printf("\n");

    } while (option != 4);

    return 0;
}