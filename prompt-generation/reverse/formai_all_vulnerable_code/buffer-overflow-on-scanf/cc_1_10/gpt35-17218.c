//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int main()
{
    FILE *fp;
    char filename[] = "example.txt";
    char data[MAX_SIZE];
    int choice;

    printf("1. Write to file\n");
    printf("2. Read from file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter data to write to file: ");
            fflush(stdin); // clear input buffer
            fgets(data, MAX_SIZE, stdin);

            fp = fopen(filename, "w");
            if(fp == NULL)
            {
                printf("Error opening file.\n");
                exit(1);
            }

            fputs(data, fp);

            printf("Data written successfully to file.\n");

            fclose(fp);
            break;

        case 2:
            fp = fopen(filename, "r");
            if(fp == NULL)
            {
                printf("Error opening file.\n");
                exit(1);
            }

            printf("Data read from file: \n");
            while(fgets(data, MAX_SIZE, fp) != NULL)
            {
                printf("%s", data);
            }

            fclose(fp);
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}