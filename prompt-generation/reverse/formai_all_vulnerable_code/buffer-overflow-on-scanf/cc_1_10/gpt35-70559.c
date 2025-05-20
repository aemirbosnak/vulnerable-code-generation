//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a file pointer and open the file
    FILE *fp;
    fp = fopen("survivor_data.txt", "w");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1); // Stop the program
    } else {
        printf("File opened successfully.\n");
    }

    // Ask the user for input and write it to the file
    char name[50];
    int age;
    char occupation[50];
    char location[50];

    printf("Enter your name: ");
    scanf("%s", name);
    fprintf(fp, "Name: %s\n", name);

    printf("Enter your age: ");
    scanf("%d", &age);
    fprintf(fp, "Age: %d\n", age);

    printf("Enter your occupation: ");
    scanf("%s", occupation);
    fprintf(fp, "Occupation: %s\n", occupation);

    printf("Enter your current location: ");
    scanf("%s", location);
    fprintf(fp, "Location: %s\n", location);

    // Close the file
    fclose(fp);

    // Reopen the file to read the data
    fp = fopen("survivor_data.txt", "r");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1); // Stop the program
    } else {
        printf("File opened successfully.\n");
    }

    printf("\nSurvivor report:\n");

    // Read and print each line from the file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    // Close the file
    fclose(fp);

    // End the program
    return 0;
}