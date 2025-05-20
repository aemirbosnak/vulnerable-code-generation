//FormAI DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[20], buffer[100], choice;
    int option;
    long int size;

    printf("Welcome to File Handling in C Example Program\n");
    printf("---------------------------------------------\n");

    do
    {
        printf("\n1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Write data to a file\n");
        printf("4. Read data from a file\n");
        printf("5. Close the file\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                if(fp == NULL)
                {
                    printf("Could not create file.");
                    exit(1);
                }
                printf("File created successfully.\n");
                fclose(fp);
                break;

            case 2:
                printf("Enter the filename to open: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if(fp == NULL)
                {
                    printf("Could not open file.");
                    exit(1);
                }
                size = ftell(fp);
                fseek(fp, 0L, SEEK_END);
                size = ftell(fp) - size;
                printf("File opened successfully.\nSize of file is %ld Bytes.\n", size);
                fclose(fp);
                break;

            case 3:
                printf("Enter the filename to write data: ");
                scanf("%s", filename);
                fp = fopen(filename, "a");
                if(fp == NULL)
                {
                    printf("Could not open file.");
                    exit(1);
                }
                printf("Enter the data to write to file: ");
                scanf("%s", buffer);
                fprintf(fp, "%s", buffer);
                printf("Data successfully written to file %s.\n", filename);
                fclose(fp);
                break;

            case 4:
                printf("Enter the filename to read data: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if(fp == NULL)
                {
                    printf("Could not open file.");
                    exit(1);
                }
                printf("Data read from file %s is:\n", filename);
                while(fgets(buffer, 100, fp) != NULL)
                {
                    printf("%s", buffer);
                }
                fclose(fp);
                break;

            case 5:
                printf("Thank you for using File Handling in C Example Program.\n");
                exit(0);

            default:
                printf("Invalid input. Please enter a valid option.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        scanf("%s", &choice);
    }while(choice == 'y' || choice == 'Y');

    return 0;
}