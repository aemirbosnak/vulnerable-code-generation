//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char name[20], address[50];
    int age;

    // Open the file in write mode
    fp = fopen("myFile.txt", "w");

    if (fp == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }

    // Get user input for name, address, and age
    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter address: ");
    scanf("%s", address);

    printf("Enter age: ");
    scanf("%d", &age);

    // Write the input to the file
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Address: %s\n", address);
    fprintf(fp, "Age: %d\n", age);

    // Close the file
    fclose(fp);

    // Open the file in read mode
    fp = fopen("myFile.txt", "r");

    if (fp == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }

    // Print the contents of the file
    printf("\nFile contents:\n\n");
    char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}