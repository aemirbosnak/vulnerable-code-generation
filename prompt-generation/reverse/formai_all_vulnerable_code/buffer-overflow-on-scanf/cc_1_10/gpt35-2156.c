//FormAI DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to write data to file
void writeToFile(FILE *file)
{
    int num;
    
    printf("Enter a number to write to the file: ");
    scanf("%d", &num);
    
    // Write data to file
    fprintf(file, "%d", num);
    
    printf("\nData written to file successfully!\n\n");
}

// Function to read data from file
void readFromFile(FILE *file)
{
    int num;
    
    // Read data from file
    fscanf(file, "%d", &num);
    
    printf("\nThe number read from file is: %d\n\n", num);
}

int main()
{
    FILE *file;
    int choice;
    
    // Open file in write mode
    file = fopen("data.txt", "w");
    
    // Check if file opened successfully
    if(file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("1. Write data to file\n2. Read data from file\n3. Exit\n\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                writeToFile(file);
                break;
                
            case 2:
                // Close file in write mode
                fclose(file);
                
                // Open file in read mode
                file = fopen("data.txt", "r");
                
                if(file == NULL)
                {
                    printf("Error opening file!\n");
                    exit(1);
                }
                
                readFromFile(file);
                break;
                
            case 3:
                // Close file
                fclose(file);
                
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}