//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main()
{
    char input_str[MAX_STR_LEN];
    FILE *fp;
    int option = 0, num_records = 0, record_size = 0;

    while (option != 4)
    {
        // Show menu options
        printf("\nChoose an option:");
        printf("\n1) Create a file");
        printf("\n2) Write records to the file");
        printf("\n3) Read records from the file");
        printf("\n4) Quit\n\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                // Get filename from user and create a new file
                char filename[50];
                printf("Enter file name: ");
                scanf("%s", filename);
                fp = fopen(filename, "wb");
                if (fp == NULL)
                {
                    printf("Error: Could not create file.\n");
                    break;
                }
                printf("File created successfully.\n");
                break;
            }

            case 2:
            {
                // Get number of records and record size from user
                printf("Enter number of records to write: ");
                scanf("%d", &num_records);
                printf("Enter record size: ");
                scanf("%d", &record_size);
                if (record_size >= MAX_STR_LEN)
                {
                    printf("Error: Record size is too large.\n");
                    break;
                }

                // Allocate memory for each record
                char **records;
                records = (char **)malloc(num_records * sizeof(char *));
                for (int i = 0; i < num_records; i++)
                {
                    records[i] = (char *)malloc(record_size * sizeof(char));
                }

                // Get input string from user and copy into each record
                printf("Enter input string:\n");
                fflush(stdin);
                fgets(input_str, MAX_STR_LEN, stdin);
                input_str[strcspn(input_str, "\n")] = 0; // Remove newline character

                for (int i = 0; i < num_records; i++)
                {
                    strncpy(records[i], input_str, record_size);
                }

                // Write records to file
                for (int i = 0; i < num_records; i++)
                {
                    fwrite(records[i], sizeof(char), record_size, fp);
                }

                printf("%d records written to file.\n", num_records);

                // Free memory
                for (int i = 0; i < num_records; i++)
                {
                    free(records[i]);
                }
                free(records);

                break;
            }

            case 3:
            {
                // Get number of records and record size from user
                printf("Enter number of records to read: ");
                scanf("%d", &num_records);
                printf("Enter record size: ");
                scanf("%d", &record_size);
                if (record_size >= MAX_STR_LEN)
                {
                    printf("Error: Record size is too large.\n");
                    break;
                }

                // Allocate memory for each record
                char **records;
                records = (char **)malloc(num_records * sizeof(char *));
                for (int i = 0; i < num_records; i++)
                {
                    records[i] = (char *)malloc(record_size * sizeof(char));
                }

                // Read records from file
                rewind(fp);
                for (int i = 0; i < num_records; i++)
                {
                    fread(records[i], sizeof(char), record_size, fp);
                }

                // Print records
                printf("Records read from file:\n");
                for (int i = 0; i < num_records; i++)
                {
                    printf("%s\n", records[i]);
                }

                // Free memory
                for (int i = 0; i < num_records; i++)
                {
                    free(records[i]);
                }
                free(records);

                break;
            }

            case 4:
            {
                // Close file and exit program
                fclose(fp);
                printf("Exiting program.\n");
                exit(0);
                break;
            }

            default:
            {
                printf("Error: Invalid option.\n");
                break;
            }
        }
    }
    return 0;
}