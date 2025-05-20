//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char name[20], email[40];
    int id, age;

    // opening the file in write mode
    fp = fopen("details.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // getting user input
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your id: ");
    scanf("%d", &id);
    printf("Enter your age: ");
    scanf("%d", &age);

    // writing to the file
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Email: %s\n", email);
    fprintf(fp, "ID: %d\n", id);
    fprintf(fp, "Age: %d\n", age);

    printf("\nData written to file successfully!\n");

    // closing the file
    fclose(fp);

    // opening the file in read mode
    fp = fopen("details.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // reading from the file
    printf("\nData read from file:\n");
    printf("=====================\n");

    fscanf(fp, "Name: %[^\n]\n", name);
    fscanf(fp, "Email: %[^\n]\n", email);
    fscanf(fp, "ID: %d\n", &id);
    fscanf(fp, "Age: %d\n", &age);

    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("ID: %d\n", id);
    printf("Age: %d\n", age);

    // closing the file
    fclose(fp);

    return 0;
}